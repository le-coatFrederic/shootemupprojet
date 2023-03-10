#include "Party.hpp"
#include "../data/Data.hpp"

Party::Party(short int id) {
    this->id = id;
    this->maxPlayer = 3;
}

Party::~Party() {

}

short int Party::getId() {
    return id;
}

Data<Client*> Party::getClients() {
    return clients;
}

Data<Entity*> Party::getEntities() {
    return entities;
}

void Party::clientConnect(Client *client) {
    this->getClients().addEntity(client);
}

void Party::clientDisconnect(Client *client) {
    this->clients.deleteCell(client);
}

bool Party::isAvailable() {
    if (maxPlayer == clients.getData().size() || running)
        return false;
    return true;
}
