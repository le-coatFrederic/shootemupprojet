#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <string>

class Network {
public:
    // constructors / destructors
    Network(sf::IpAddress ip, short int port);
    ~Network();

    // accessors

    // connexion methods
    void run();
    
    // messages
    void sendMessage(std::string message);

protected:
    // clients parameters
    std::string pseudo;

    // connexion parameters
    bool connected;
    sf::TcpSocket socket;
    sf::IpAddress ip;
    short int port;

    void connexion(sf::IpAddress ip, short int port);

};

#endif