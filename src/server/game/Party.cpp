#include "Party.hpp"

Party::Party(short int id) {
    this->id = id;
    this->maxPlayer = 3;
}

Party::~Party() {

}

short int Party::getId() {
    return id;
}

std::vector<Client*> Party::getClients() {
    return clients;
}

std::vector<Entity*> Party::getEntities() {
    return entities;
}

void Party::clientConnect(Client *client) {
    this->getClients().push_back(client);
}

void Party::clientDisconnect(Client *client) {
    int id;
    for (int i = 0; i < this->clients.size(); i++)
        if (this->clients.at(i) == client) {
            delete this->clients.at(i);
            break;
        }


}

bool Party::isAvailable() {
    if (maxPlayer == clients.size() || running)
        return false;
    return true;
}
