#ifndef PARTY_HPP
#define PARTY_HPP

#include "../data/Data.hpp"
#include "Client.hpp"
#include "../entities/Entity.hpp"

class Party {
public:
    // constructors / destructors
    Party();
    ~Party();

    // accessors
    short int getId();
    Data<Client*> getClients();
    Data<Entity*> getEntities();

protected:
    // identity
    short int id;

    // data
    Data<Client*> clients;
    Data<Entity*> entities;
    //bullets
};

#endif