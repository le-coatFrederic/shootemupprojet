#include "Client.hpp"
#include "Party.hpp"
#include <SFML/Network/TcpSocket.hpp>

Client::Client(sf::TcpSocket* socket) {
    this->socket = socket;
}

Client::~Client() {
    socket->disconnect();
    delete socket;
    party->clientDisconnect(this);
}

Party* Client::getParty() {
    return party;
}

sf::TcpSocket* Client::getSocket() {
    return this->socket;
}

void Client::joinParty(Party *party) {
    if (party != nullptr || party->isAvailable()) {
        this->party = party;
        party->clientConnect(this);
    }
}

void Client::leaveParty() {
    this->party->clientDisconnect(this);
    this->party = nullptr;
}