#include "Game.h"

//Private functions
void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "Game one", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
    this->enemy.setFillColor(sf::Color::White);
    this->enemy.setOutlineColor(sf::Color::Red);
    this->enemy.setOutlineThickness(1.f);
}


//Constructors and Destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
    delete this->window;
}

//Accessors
const bool Game::running() const {
    return this->window->isOpen();
}



//Functions
void Game::pollEvents() {
    //Event polling
    while(this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update() {
    this->pollEvents();

    //Update mouse position
    //Relative to the screen
    /*
     * std::cout << "Mouse position: "
    *     << sf::Mouse::getPosition().x << " "
    *     << sf::Mouse::getPosition().y << "\n";
    */

    //Relative to the window
    std::cout << "Mouse position: "
        << sf::Mouse::getPosition(*this->window).x << " "
        << sf::Mouse::getPosition(*this->window).y << "\n";
}

void Game::render() {
    /*
     * Render the game objects
     * - clear old frame
     * - render objects
     * - display frame in the window
     */

    this->window->clear();

    //Draw game objects
    this->window->draw(this->enemy);
    this->window->display();
}
