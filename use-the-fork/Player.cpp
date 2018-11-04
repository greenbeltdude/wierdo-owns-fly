/*
 * Player.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "Player.h"

Player::Player( int radius ) :
	sf::CircleShape( radius ),
	SpaceObject( this )
{}


Player::~Player() = default;



void Player::step() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getPosition().x<1306 ) move(12,0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getPosition().x>30 ) move(-12,0);
}



