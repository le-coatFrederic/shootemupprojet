#ifndef SERVEUR_HPP
#define SERVEUR_HPP

#include <SFML/Network.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/SocketSelector.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <vector>
#include <iostream>
#include "../data/Data.hpp"
#include "../game/Party.hpp"
class Server {
protected:
    // connection
    sf::TcpListener listener;
    std::vector<sf::TcpSocket*> clients;
    sf::SocketSelector selector;
    bool running;

    // network
    void listeningExistingConnection();
    void listeningNewConnection();
    void readMessage(sf::Packet message);

    // game mechanics
    Data<Party*> parties;

public:
    Server(unsigned short port);
    ~Server();

    // accessors
    Data<Party*> getParties();

    // server methods
    void run();
    void closeServer();

    // methods via messages
    void createParty();
    void leaveParty(Party* party);
};

#endif