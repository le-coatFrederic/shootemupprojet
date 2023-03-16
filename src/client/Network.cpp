#include "Network.hpp"
#include "Game.hpp"
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <string>

Network::Network(sf::IpAddress ip, short int port, Game* game) {
    this->game = game;
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
}

void Network::sendMessage(std::string message) {
    sf::Packet msgToSend;
    msgToSend << message;
    std::cout << "j'envoie un message\n";
    if (this->socket.send(msgToSend) == sf::Socket::Done)
        std::cout << "j'ai reussis\n";
    else
        std::cout << "je n\'ai pas reussis\n";
}

void Network::updateNetwork() {
    sf::Packet packet;

    if (this->socket.receive(packet) == sf::Socket::Done)
        this->readMessage(packet);
}

void Network::readMessage(sf::Packet message) {
    std::string msg;
    message >> msg;
    //std::cout << client->getSocket()->getRemoteAddress() << " m'a envoye : " << msg << "\n";
    std::vector<std::string> msgElements = this->readline(msg, ':');
    std::cout << "je lis :\n";

    for (std::string mot : msgElements)
        std::cout << "\t" << mot << "\n";

    if (msgElements.at(0) == "pos") {
        msgElements = this->readline(msgElements.at(1), ',');
        this->game->getEntities().at(1)->update(sf::Vector2i(std::stoi(msgElements.at(0)), std::stoi(msgElements.at(1))));
        std::cout << "je suis position : " << this->game->getEntities().at(1)->getShape().getPosition().x << " : " << this->game->getEntities().at(1)->getShape().getPosition().y << "\n";
    }
}

std::vector<std::string> Network::readline(std::string msg, char separator) {
    //std::cout << "je vais traiter " << msg << "\n"; 
    
    std::vector<std::string> toback;
    std::string temp;
    for (int i = 0; msg[i] != '\0' | i < msg.size(); i++)
        if (msg[i] == separator) {
            toback.push_back(temp);
            temp.clear();
        } else {
            temp += msg[i];
        }
    toback.push_back(temp);
    
    return toback;
}

void Network::connexion(sf::IpAddress ip, short int port) {
    if (this->socket.connect(ip, port) == sf::Socket::Done) {
        connected = true;
        this->socket.setBlocking(false);
        std::cout << "connected\n";
    } else {
        std::cout << "error : not connected\n";
        exit(1);
    }
}