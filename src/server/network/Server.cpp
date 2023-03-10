#include "Server.hpp"
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <stdexcept>
#include <string>

Server::Server(unsigned short port) : listener(), clients() {
    if (listener.listen(port) != sf::Socket::Done)
        throw std::runtime_error("Error listening.");
    std::cout << "Server listening on port " << port << ".\n";
}

Server& Server::getServer(unsigned short port) {
    static Server instance(port);
    return instance;
}

Server::~Server() {
    for (sf::TcpSocket* socket : clients)
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

}

void Server::listeningExistingConnection() {
    for (sf::TcpSocket* client : clients) {
        if (selector.isReady(*client)) {
            sf::Packet receivePacket;
                if (client->receive(receivePacket) == sf::Socket::Done) { // have to treat any possible case
                    this->readMessage(receivePacket);
                }
        }
    }
}

void Server::listeningNewConnection() {
    if (selector.isReady(listener)) {
        sf::TcpSocket *socket = new sf::TcpSocket();
        listener.accept(*socket);
        selector.add(*socket);
        clients.push_back(socket);
    }
}

void Server::readMessage(sf::Packet message) {
    std::string msg;
    message >> msg;
    std::cout << msg << std::endl;
}

void createParty() {

}

void leaveParty(Party* party) {

}
