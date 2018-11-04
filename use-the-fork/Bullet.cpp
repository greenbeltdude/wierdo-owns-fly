/*
 * Bullet.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "Bullet.h"

Bullet::Bullet() :
	sf::RectangleShape( sf::Vector2f(14, 28) ),
	SpaceObject( this ),
	mDirection(1)
{}


Bullet::~Bullet() = default;




void Bullet::step() {
	move( 0, mDirection * 1);

}



