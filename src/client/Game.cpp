#include "Game.hpp"
#include "Network.hpp"
#include "entity/Entity.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <string>
#include <vector>

// Constructors / destructors
Game::Game() {
    this->initVariable();
    this->initNetwork();
    this->initWindow();

    this->addEntities(new Entity(sf::Vector2f((this->window->getSize().x / 2) - 25.f, this->window->getSize().y - 25.f), sf::Vector2f(50.f, 50.f), this->window));
    this->addEntities(new Entity(sf::Vector2f((this->window->getSize().x / 2) - 25.f, this->window->getSize().y - 25.f), sf::Vector2f(50.f, 50.f), this->window));

    this->connexion("93.8.39.46", 9010);
}

Game::~Game() {
    for (Entity* entity : entities)
        delete entity;
    delete  server;
    delete this->window;
}

// initialization methods
void Game::initVariable() {
    this->window = nullptr;
}

void Game::initWindow() {
    //window size
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->fps = 60;

    this->window = new sf::RenderWindow(this->videoMode, this->name, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(this->fps);
}

void Game::initNetwork() {
    this->server = nullptr;
}

void Game::connexion(sf::IpAddress ip, short int port) {
    this->server = new Network(ip, port, this);
}

// Public methods
// Update game
void Game::update() {
    
    this->pollEvents();   

    this->server->updateNetwork();
    this->updateEntities();
    this->updateMousePosition();
}

void Game::updateEntities() {
    for (int i = 0; i < entities.size(); i++) {
        if (i == 0) {
            entities.at(i)->update(mousePos);
            this->server->sendMessage("pos:" + std::to_string(entities.at(i)->getShape().getPosition().x) + "," + std::to_string(entities.at(i)->getShape().getPosition().y));
        }
    }

}

void Game::updateMousePosition() {
    // Position of mouse relative to window
    this->mousePos = sf::Mouse::getPosition(*this->window);  

    // display position  
    /*std::cout 
        << this->getMousePos().x << " " 
        << this->getMousePos().y << "\n";*/
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
        }
    }
}

// Render game
void Game::render() {
    // Clear window with white
    this->window->clear();

    // Draw game objects
    this->renderEntities();

    this->window->display();
}

void Game::renderEntities() {
    for (Entity* entity : this->entities) {
        entity->render();
    }
}

void Game::addEntities(Entity *entity) {
    if (entity != NULL)
        this->entities.push_back(entity);
}

// Accessors
const bool Game::getWindowState() const {
    return this->window->isOpen();
}

sf::Vector2i Game::getMousePos() {
    return this->mousePos;
}

std::vector<Entity*> Game::getEntities() {
    return entities;
}