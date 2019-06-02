/*
 * DumbAlien.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "DumbAlien.h"

DumbAlien::DumbAlien( int radius ) :
	sf::CircleShape( radius ),
	SpaceObject( this ),
	mDirection(1)
{
	setValue(19);
	setType("DumbAlien");
}


DumbAlien::~DumbAlien() = default;

void DumbAlien::setTarget( std::shared_ptr<sf::CircleShape> newTarget ) {
	mTarget = newTarget;
}


void DumbAlien::step() {
	if (getPosition().x>1300) {
		move(0,10);
		mDirection = -1 * mDirection;
	}
	if (getPosition().x<60) {
		move(0,10);
		mDirection = -1 * mDirection;
	}
	move( mDirection * 10, 0);

}



