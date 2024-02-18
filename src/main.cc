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

        // Update new entities
        em.update();

        // Transform System
        for (auto& e : em.getEntities()) {
            e.get()->setPos(e.get()->getPos() + e.get()->getVel());
        }

        // Bounding Box System
        for (auto& e : em.getEntities()) {
            auto p = e.get()->getPos();
            auto bb = e.get()->getBounds();
            if (p.x <= 0 || p.x + bb.x >= 600) {
                auto v = e.get()->getVel();
                e.get()->setVel(sf::Vector2f(v.x * -1, v.y));
            }
            if (p.y <= 0 || p.y + bb.y >= 600) {
                auto v = e.get()->getVel();
                e.get()->setVel(sf::Vector2f(sf::Vector2f(v.x, v.y * -1)));
            }
        }

        // Render System
        window.clear();
        for (auto& e : em.getEntities()) {
            window.draw(e.get()->getCircleShape());
        }
        window.display();
    }

    return 0;
}