#include "DumbAlienArmy.h"
#include "SpaceObjectFactory.h"
#include "TrackingAlienArmy.h"
#include "Bullet.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

int main() {
	sf::RenderWindow window(sf::VideoMode(1366, 768), "The Player Owns the Fly, Dude", sf::Style::Fullscreen);
	std::shared_ptr<Player> player = std::make_shared<Player>(30);
	sf::CircleShape fly(15);
	TrackingAlienArmy alien(5,5);
	DumbAlienArmy dude(5,5);

	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
	SpaceObjectFactory objectFactory;
	for( auto &soldier : alien ) objectFactory.push_back(soldier);
	for( auto &soldier : dude ) objectFactory.push_back( soldier );
	objectFactory.push_back(bullet);
	objectFactory.setTarget(player);

	player->setFillColor(sf::Color::Green);
	//fly.setFillColor(sf::Color::Red);
	alien.setFillColor(sf::Color::Yellow);
	dude.setFillColor(sf::Color::Magenta);
	bullet->setFillColor(sf::Color::White);

	//fly.setPosition(683,0);
	player->setPosition(683,708);
	bullet->setPosition(722,0);

	alien.setTarget( player );
	dude.setTarget(player);

	sf::Clock clock;
	int oldElapseTime = 10;

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();

		if ( clock.getElapsedTime().asMilliseconds() > (oldElapseTime + 10) ) {
			oldElapseTime = clock.getElapsedTime().asMilliseconds();
			objectFactory.step();
			if ( objectFactory.checkForCollisions() ) {
				window.close();
				std::cout << "Alien Wins!\n" << std::endl;
			}
			window.clear();
			window.draw(*(player.get()));
			for( auto &object : objectFactory) window.draw( *(object->shape()) );
			window.display();
		}
		if (clock.getElapsedTime().asSeconds() > 60) {
			window.close();
			std::cout << "You win!\n" << std::endl;
		}

	}
	return 0;
}
