#include "DumbAlienArmy.h"
#include "SpaceObjectFactory.h"
#include "TrackingAlienArmy.h"
#include "Bullet.h"
#include "Player.h"
#include "CircleAlien.h"
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
	std::shared_ptr<CircleAlien> circle = std::make_shared<CircleAlien>();
	for( auto &soldier : alien ) SpaceObjectFactory::instance()->push_back(soldier);
	for( auto &soldier : dude ) SpaceObjectFactory::instance()->push_back( soldier );
	SpaceObjectFactory::instance()->push_back(circle);
	SpaceObjectFactory::instance()->setTarget(player);

	player->setFillColor(sf::Color::Green);
	alien.setFillColor(sf::Color::Yellow);
	dude.setFillColor(sf::Color::Magenta);
	bullet->setFillColor(sf::Color::White);
	circle->setFillColor(sf::Color::Red);

	//fly.setPosition(683,0);
	player->setPosition(683,708);
	bullet->setPosition(722,0);
	//circle->setPosition(683,0);
	alien.setTarget( player );
	dude.setTarget(player);


	sf::Clock clock;
	int oldElapseTime = 666;

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) window.close();

		if ( clock.getElapsedTime().asMilliseconds() > (oldElapseTime + 10) ) {
			oldElapseTime = clock.getElapsedTime().asMilliseconds();
			SpaceObjectFactory::instance()->step();
			if ( SpaceObjectFactory::instance()->checkForCollisions() ) {
				window.close();
				std::cout << "Alien Wins!\n" << std::endl;
			}
			window.clear();
			window.draw(*(player.get()));
			for( auto &object : *(SpaceObjectFactory::instance().get())) window.draw( *(object->shape()) );
			window.display();
		}
		if (clock.getElapsedTime().asSeconds() > 10) {
			window.close();
			std::cout << "You win!\n You scored " <<
					SpaceObjectFactory::instance()->score()
					<< " points!" << std::endl;

		}

	}
	return 0;
}
