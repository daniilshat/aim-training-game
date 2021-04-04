#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
 * Class that acts as the game engine
 * Wrapper class
 */

class Game {
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Game objects
    sf::RectangleShape enemy;

    //Private functions
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    //Constructors and Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;


    //functions
    void pollEvents();
    void update();
    void render();
};