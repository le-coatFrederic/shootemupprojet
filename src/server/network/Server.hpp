#ifndef __Server__
#define __Server__

#include <SFML/Network.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/SocketSelector.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <vector>
#include <iostream>
#include "../../both/data/Data.hpp"
#include "../game/Party.hpp"

class Server {
protected:
    //SINGLETON, on empeche toutes les possibilités de copie et création de nouveau objet.
    Server(unsigned short port);

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
    //SINGLETON, on permet de voir le seul objet Server
    static Server& getServer(unsigned short port);
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
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