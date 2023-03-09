#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>

class Entity{
public:
    // constructors / destructors
    Entity(sf::Vector2f pos, const sf::Vector2f size, sf::RenderWindow* window);
    ~Entity();
    
    // methods
    void render();
    void update();

protected:
    // variable
    // game mechanics
    int hp;
    sf::RenderWindow* window;
    sf::RectangleShape shape;

    // movements
    sf::Vector2f pos;
    sf::Vector2f size;
    float speed;
    float angle;

    // protected methods
    void initVariable();
};

#endif