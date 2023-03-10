#include "Server.hpp"
#include "../data/Data.hpp"
#include <iostream>

Server::Server(unsigned short port) : listener(), clients() {
    if (listener.listen(port) != sf::Socket::Done)
        throw std::runtime_error("Error listening.");
    std::cout << "Server listening on port " << port << ".\n";
    this->run();
}

Server::~Server() {
    for (Client* socket : clients.getData())
        delete socket;


}

Data<Party*> Server::getParties() {
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
    for (Client* client : clients.getData()) {
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
        clients.addEntity(new Client(socket));
        std::cout << "Client ip : " << socket->getRemoteAddress() << std::endl;
    }
}

void Server::readMessage(Client* client, sf::Packet message) {
    std::string msg;
    message >> msg;
    std::cout << client->getSocket()->getRemoteAddress() << msg << std::endl;
}

void Server::createParty() {

}

void Server::leaveParty(Party* party) {

}

template class Data<Party*>;