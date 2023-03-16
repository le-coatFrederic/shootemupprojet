#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <string>

class Game;

class Network {
public:
    // constructors / destructors
    Network(sf::IpAddress ip, short int port, Game* game);
    ~Network();

    // accessors

    // connexion methods
    void run();
    
    // messages
    void updateNetwork();
    void sendMessage(std::string message);
    void readMessage(sf::Packet);
    std::vector<std::string> readline(std::string msg, char separator);

protected:
    // clients parameters
    std::string pseudo;
    Game* game;

    // connexion parameters
    bool connected;
    sf::TcpSocket socket;
    sf::IpAddress ip;
    short int port;

    void connexion(sf::IpAddress ip, short int port);

};

#endif