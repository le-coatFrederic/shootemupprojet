#include "Game.hpp"
#include "entity/Entity.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>

// Constructors / destructors
Game::Game() {
    this->initVariable();
    this->initWindow();

    this->addEntities(new Entity(sf::Vector2f(520.f, 510.f), sf::Vector2f(50.f, 75.f), this->window));
    this->addEntities(new Entity(sf::Vector2f(15.f, 540.f), sf::Vector2f(30.f, 10.f), this->window));
    this->addEntities(new Entity(sf::Vector2f(320.f, 147.f), sf::Vector2f(50.f, 40.f), this->window));
}

Game::~Game() {
    delete this->window;
}

// Private methods
void Game::initVariable() {
    this->window = nullptr;
}

void Game::initWindow() {
    //window size
    this->videoMode.width = 800;
    this->videoMode.height = 600;

    this->window = new sf::RenderWindow(this->videoMode, this->name, sf::Style::Titlebar | sf::Style::Close);
}

// Public methods
// Update game
void Game::update() {
    for (Entity* entity : this->entities)
        entity->update();
    this->pollEvents();
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
    for (Entity* entity : this->entities)
        entity->render();
    this->window->display();
}

void Game::addEntities(Entity *entity) {
    if (entity != NULL)
        this->entities.push_back(entity);
}

// Accessors
const bool Game::getWindowState() const {
    return this->window->isOpen();
}