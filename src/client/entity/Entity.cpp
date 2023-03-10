#include "Entity.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

Entity::Entity(sf::Vector2f pos, sf::Vector2f size, sf::RenderWindow* window) {
    this->pos = pos;
    this->size = size;
    this->window = window;
    this->initVariable();
}

Entity::~Entity() {
    this->window = nullptr;
}

sf::RectangleShape Entity::getShape() {
    return this->shape;
}

void Entity::update() {
    this->pos.x = pos.x + (this->speed * angle);
    this->pos.y = pos.y + (this->speed * (angle - 1));
    this->shape.setPosition(this->pos);
    this->windowColliding();
}

// methods
void Entity::render() {
    window->draw(this->shape);
}

// game mechanics
bool Entity::mouseCollision(sf::Vector2i mousePos) {
    bool statut = false;
    if (mousePos.x >= this->shape.getPosition().x && mousePos.x <= this->shape.getPosition().x + this->shape.getSize().x)
        if (mousePos.y >= this->shape.getPosition().y && mousePos.y <= this->shape.getPosition().y + this->shape.getSize().y)
            statut = true;

    return statut;
}

void Entity::setColor(sf::Color color) {
    this->shape.setFillColor(color);
}

// protected methods
void Entity::windowColliding() {
    // entity colliding window borders
    if (shape.getPosition().x <= 0) // left
        angle += 1;
    if (shape.getPosition().y <= 0) //top
        angle += 1;
    if (shape.getPosition().x + shape.getSize().x >= window->getSize().x) // right
        angle -= 1;
    if (shape.getPosition().y + shape.getSize().y >= window->getSize().y) // bottom
        angle -= 1;
}

void Entity::initVariable() {
    // shape configuration
    this->shape.setSize(this->size);
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(this->pos);
    this->shape.setOutlineThickness(5.f);
    this->shape.setOutlineColor(sf::Color::Black);

    // position
    this->speed = 0.5;
    this->angle = 0.5;
}
