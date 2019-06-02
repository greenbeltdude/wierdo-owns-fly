/*
 * Player.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "Player.h"
#include "Bullet.h"
#include "SpaceObjectFactory.h"

#include <iostream>

Player::Player( int radius ) :
	sf::CircleShape( radius ),
	SpaceObject( this )
{
setType("player");
}


Player::~Player() = default;



void Player::step() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getPosition().x<1306 ) move(12,0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getPosition().x>30 ) move(-12,0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) fire();
}

void Player::fire() {
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>();
	bullet->setFillColor(sf::Color::White);
	bullet->setPosition(getPosition().x,getPosition().y-100);
	bullet->setSpeed( 5 );
	bullet->setDirection( -1 );
	SpaceObjectFactory::instance()->push_back(bullet);
}




