#ifndef PARTY_HPP
#define PARTY_HPP

#include "../data/Data.hpp"
#include "Client.hpp"
#include "../entities/Entity.hpp"

class Party {
public:
    // constructors / destructors
    Party(short int id);
    ~Party();

    // accessors
    short int getId();
    Data<Client*> getClients();
    Data<Entity*> getEntities();

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
    Data<Client*> clients;
    Data<Entity*> entities;
    //bullets
};

#endif