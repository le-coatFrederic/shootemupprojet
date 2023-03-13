#ifndef SERVEUR_HPP
#define SERVEUR_HPP

#include <SFML/Network.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/SocketSelector.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "../game/Client.hpp"
#include "../game/Party.hpp"

class Server {
protected:
    // connection
    sf::TcpListener listener;
    std::vector<Client*> clients;
    sf::SocketSelector selector;
    bool running;

    // network
    void listeningExistingConnection();
    void listeningNewConnection();
    void sendMessage(sf::TcpSocket* socket, std::string message);
    void readMessage(Client* client, sf::Packet message);

    // game mechanics
    std::vector<Party*> parties;
    void sendListParty(Client *client);
    std::vector<std::string> readline(std::string);

public:
    Server(unsigned short port);
    ~Server();

    // accessors
    std::vector<Party*> getParties();

    // server methods
    void run();
    void closeServer();

    // methods via messages
    void createParty();
    void leaveParty(Party* party);
};

#endif