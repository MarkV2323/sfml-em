#include <SFML/Graphics.hpp>
#include <iostream>

#include "entityManager/entityManager.h"
#include "entityManagerTwo/entityManagerTwo.h"
#include "tests/emTwoTests.h"

using namespace em;
using namespace std;
using namespace ecs;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Entity Manager Demo");
    window.setFramerateLimit(60);

    // run EM-Two tests
    // runEntityManagerTwoTests();

    EntityManagerTwo em{};
    auto e1 = em.addEntity("TEST");
    em.update();

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

        // Transform System
        for (auto& e : em.getEntities()) {
            auto p = e.get()->getTransform().getPosition();
            auto v = e.get()->getTransform().getVelocity();
            auto n_pos = p + v;
            e.get()->getTransform().setPosition(n_pos);
            e.get()->getShape().setPosition(n_pos);
        }

        window.clear();
        // Render System
        for (auto& e : em.getEntities()) {
            window.draw(e.get()->getShape().getCircle());
        }
        window.display();
    }

    return 0;
}