/*
 * Bullet.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef Bullet_H_
#define Bullet_H_

#include "DumbAlien.h"
#include "SpaceObject.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Bullet : public sf::RectangleShape, public SpaceObject
{
public:
	Bullet( );
	virtual ~Bullet();

	void setDirection( int newDirection );
	void step();
	void setSpeed( int newSpeed );


private:

	int mDirection;
    int mSpeed;
};


#endif /* TRACKINGALIEN_H_ */
