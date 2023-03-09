#ifndef GAME_HPP
#define GAME_HPP

#include "entity/Entity.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <string>
#include <vector>

class Game{
public:
    // Constructors / Destructors
    Game();
    virtual ~Game();

    // Methods
    void update();
    void pollEvents();
    void render();
    void addEntities(Entity* entity);

    // Accessors
    const bool getWindowState() const;

protected:
    // Private methods
    void initVariable();
    void initWindow();

    // Variables
    // window
    std::string name;
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    // data
    std::vector<Entity*> entities;
};

#endif