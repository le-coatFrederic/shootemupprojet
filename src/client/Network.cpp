#include "Network.hpp"
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <iostream>
#include <string>

Network::Network(sf::IpAddress ip, short int port) {
    this->ip = ip;
    this->port = port;
    this->run();
}

Network::~Network() {

}

// accessors

// connexion methods
void Network::run() {
    this->connexion(this->ip, this->port);
    this->sendMessage(std::string("Je suis la pour te parler"));
}

void Network::sendMessage(std::string message) {
    sf::Packet msgToSend;
    msgToSend << message;
    this->socket.send(msgToSend);
}

void Network::connexion(sf::IpAddress ip, short int port) {
    if (this->socket.connect(ip, port) == sf::Socket::Done) {
        connected = true;
        std::cout << "connected\n";
    } else {
        std::cout << "error : not connected\n";
        exit(1);
    }
}