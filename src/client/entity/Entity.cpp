#include "Entity.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

Entity::Entity(sf::Vector2f pos, sf::Vector2f size, sf::RenderWindow* window) {
    this->pos = pos;
    this->size = size;
    this->window = window;
    this->initVariable();
}

Entity::~Entity() {
    delete this->window;
}

void Entity::update() {
    this->pos.x = pos.x + this->speed;
    this->pos.y = pos.y + this->speed;
    this->shape.setPosition(this->pos);
}

// methods
void Entity::render() {
    window->draw(this->shape);
}

// protected methods
void Entity::initVariable() {
    // shape configuration
    this->shape.setSize(this->size);
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(this->pos);
    this->shape.setOutlineThickness(5.f);
    this->shape.setOutlineColor(sf::Color::Black);

    // position
    this->speed = 0.005;
    this->angle = 0;
}
