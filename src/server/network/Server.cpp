#include "Server.hpp"
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <stdexcept>

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
    for (int i = 0; i < clients.size(); i++)
        delete clients.at(i);
}

void Server::run() {
    while (true) {
        sf::TcpSocket* socket = new sf::TcpSocket;
    }
}

void Server::closeServer() {

}

void Server::listeningExistingConnection() {

}

void Server::listeningNewConnection(sf::TcpSocket* socket) {

}
