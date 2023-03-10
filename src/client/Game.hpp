#ifndef GAME_HPP
#define GAME_HPP

#include "Network.hpp"
#include "entity/Entity.hpp"
#include <SFML/Network/IpAddress.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>

class Game{
public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Methods
    // updates
    void update();
    void updateMousePosition();
    void updateEntities();
    void pollEvents();
    void render();
    void renderEntities();

    // mechanics
    void addEntities(Entity* entity);

    // Accessors
    const bool getWindowState() const;
    sf::Vector2i getMousePos();

protected:
    // Variables
    void initVariable();
    // window
    std::string name;
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    int fps;
    void initWindow();

    // data
    std::vector<Entity*> entities;

    // network
    Network* server;
    void initNetwork();
    void connexion(sf::IpAddress ip, short int port);

    // mechanics
    sf::Vector2i mousePos;
};

#endif