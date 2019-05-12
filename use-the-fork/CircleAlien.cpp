/*
 * CircleAlien.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "CircleAlien.h"
#include <cmath>

CircleAlien::CircleAlien( int radius ) :
	sf::CircleShape( radius ),
	SpaceObject( this ),
	mradius(260),
xcenter(780),
ycenter(0),
angle(0)
{}


CircleAlien::~CircleAlien() = default;

void CircleAlien::setTarget( std::shared_ptr<sf::CircleShape> newTarget ) {
	mTarget = newTarget;
}


void CircleAlien::step() {
int xnow=getPosition().x;
int ynow=getPosition().y;
angle=angle+0.1;
int xx=xcenter+mradius*cos(angle);
int yy=ycenter+mradius*sin(angle);
move(xx-xnow,yy-ynow);

ycenter=ycenter+1;
}



