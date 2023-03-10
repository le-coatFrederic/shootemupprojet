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

// Constructors / destructors
Game::Game() {
    this->initVariable();
    this->initNetwork();
    this->initWindow();

    this->addEntities(new Entity(sf::Vector2f(520.f, 510.f), sf::Vector2f(50.f, 75.f), this->window));
    this->addEntities(new Entity(sf::Vector2f(15.f, 540.f), sf::Vector2f(30.f, 10.f), this->window));
    this->addEntities(new Entity(sf::Vector2f(320.f, 147.f), sf::Vector2f(50.f, 40.f), this->window));

    this->connexion("localhost", 9010);
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
    this->server = new Network(ip, port);
}

// Public methods
// Update game
void Game::update() {
    
    this->pollEvents();   

    this->updateEntities();
    this->updateMousePosition();
}

void Game::updateEntities() {
    for (Entity* entity : this->entities)
        entity->update();

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
        if (entity->mouseCollision(mousePos)) 
            entity->setColor(sf::Color::Green);
        else
            entity->setColor(sf::Color::Red);
    
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