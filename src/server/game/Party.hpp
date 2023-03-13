#ifndef PARTY_HPP
#define PARTY_HPP

#include "Client.hpp"
#include "../entities/Entity.hpp"
#include <vector>

class Party {
public:
    // constructors / destructors
    Party(short int id);
    ~Party();

    // accessors
    short int getId();
    std::vector<Client*> getClients();
    std::vector<Entity*> getEntities();

    // game mechanics
    void clientConnect(Client *client);
    void clientDisconnect(Client* client);
    bool isAvailable();

protected:
    // identity
    short int id;
    int maxPlayer;
    bool running;

    // data
    std::vector<Client*> clients;
    std::vector<Entity*> entities;
    //bullets
};

#endif