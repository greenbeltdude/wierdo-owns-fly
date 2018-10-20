/*
 * TrackingAlien.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "TrackingAlien.h"

TrackingAlien::TrackingAlien( int radius ) :
	sf::CircleShape( radius )
{}


TrackingAlien::~TrackingAlien() = default;

void TrackingAlien::setTarget( std::shared_ptr<sf::CircleShape> newTarget ) {
	mTarget = newTarget;
}


void TrackingAlien::step() {
	move(0,1);
	if (mTarget->getPosition().x > getPosition().x) move(1,0);
	if (mTarget->getPosition().x < getPosition().x) move(-1,0);
	if (getPosition().y>800) setPosition(getPosition().x,0);
}


