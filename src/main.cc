#include <SFML/Graphics.hpp>
#include <iostream>

#include "entityManager/entityManager.h"
#include "entityManagerTwo/entityManagerTwo.h"
#include "tests/emTwoTests.h"

using namespace em;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Entity Manager Demo");
    window.setFramerateLimit(60);

    // run EM-Two tests
    runEntityManagerTwoTests();

    // TODO:
    // 1 - Refactor EntityManagerTwo addEntity to return a raw pointer
    //     rather than shared pointer.
    // 2 - Add removal function based on unique ID for entities.
    // 3 - Add getId function for entities.
    // 2 - Create test header file with static function for running
    //     several assert tests against entityManagerTwo
    //     These test should contain creation and removal of entities.
    //     Adding some randomness and timing meterics.

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Escape)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}