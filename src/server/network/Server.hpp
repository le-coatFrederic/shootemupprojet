#ifndef __Server__
#define __Server__

#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

class Server {
protected:
    //SINGLETON, on empeche toutes les possibilités de copie et création de nouveau objet.
    Server(unsigned short port);

    sf::TcpListener listener;
    std::vector<sf::TcpSocket*> clients;

    void listeningExistingConnection();
    void listeningNewConnection(sf::TcpSocket* socket);

public:
    //SINGLETON, on permet de voir le seul objet Server
    static Server& getServer(unsigned short port);
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    ~Server();
    void run();
    void closeServer();
};

#endif