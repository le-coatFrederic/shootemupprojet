#include "Server.hpp"
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Server::Server(unsigned short port) : listener(), clients() {
    if (listener.listen(port) != sf::Socket::Done)
        throw std::runtime_error("Error listening.");
    std::cout << "Server listening on port " << port << ".\n";
    this->run();
}

Server::~Server() {
    for (Client* socket : clients)
        delete socket;


}

std::vector<Party*> Server::getParties() {
    return this->parties;
}

void Server::run() {
    running = true;
    selector.add(listener);

    while (running) {
        if (selector.wait()) {
            listeningNewConnection();
            listeningExistingConnection();
        }
    }
}

void Server::closeServer() {
    this->running = false;
}

void Server::listeningExistingConnection() {
    for (Client* client : clients){
        if (selector.isReady(*client->getSocket())) {
            sf::Packet receivePacket;
                if (client->getSocket()->receive(receivePacket) == sf::Socket::Done) { // have to treat any possible case
                    this->readMessage(client, receivePacket);
                }
        }
    }
}

void Server::listeningNewConnection() {
    if (selector.isReady(listener)) {
        sf::TcpSocket *socket = new sf::TcpSocket();
        listener.accept(*socket);
        selector.add(*socket);
        clients.push_back(new Client(socket));
        std::cout << "Client ip : " << socket->getRemoteAddress() << std::endl;
    }
}

void Server::sendMessage(sf::TcpSocket* socket, std::string message) {
    sf::Packet packet;
    packet << message;

    socket->send(packet);
}

void Server::readMessage(Client* client, sf::Packet message) {
    std::string msg;
    message >> msg;
    //std::cout << client->getSocket()->getRemoteAddress() << " m'a envoye : " << msg << "\n";
    std::vector<std::string> msgElements = this->readline(msg);
    std::cout << "je lis :\n";

    for (std::string mot : msgElements)
        std::cout << "\t" << mot << "\n";

    if (msgElements.at(0) == "@")
        for (int i = 0; i < this->parties.size(); i++)
            this->sendMessage(client->getSocket(), "p:" + std::to_string(this->parties.at(i)->getId()));

    if (msgElements.at(0) == "pos")
        for (Client* clt : this->clients)
            if (clt != client)
                this->sendMessage(clt->getSocket(), msgElements.at(0) + ':' + msgElements.at(1));
}

std::vector<std::string> Server::readline(std::string msg) {
    //std::cout << "je vais traiter " << msg << "\n"; 
    
    std::vector<std::string> toback;
    std::string temp;
    for (int i = 0; msg[i] != '\0' | i < msg.size(); i++)
        if (msg[i] == ':') {
            toback.push_back(temp);
            temp.clear();
        } else {
            temp += msg[i];
        }
    toback.push_back(temp);
    
    return toback;
}

void Server::sendListParty(Client *client) {
    sf::Packet packet;
    for (Party* party : this->parties) {
        packet << party;
        client->getSocket()->send(packet);
    }
}

void Server::createParty() {

}

void Server::leaveParty(Party* party) {

}