#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpSocket.hpp>

typedef enum Role{
    Pilot,
    Gunner,
    Technician
}Role;

class Party;

class Client {
public:
    // constructors / destructors
    Client(sf::TcpSocket* socket);
    ~Client();

    // accessors
    Party* getParty();
    sf::TcpSocket* getSocket();

    // game methods
    void joinParty(Party* party);
    void leaveParty();

protected:
    // connection information
    sf::TcpSocket* socket;

    //game information
    Party* party;
    Role role;
};

#endif