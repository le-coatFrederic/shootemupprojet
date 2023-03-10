#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics/Color.hpp>
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
    
    // accessors
    sf::RectangleShape getShape();

    // methods
    void render();
    void update();

    // game mechanics
    bool mouseCollision(sf::Vector2i mousePos);
    void setColor(sf::Color color);

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
    void windowColliding();

    // protected methods
    void initVariable();
};

#endif