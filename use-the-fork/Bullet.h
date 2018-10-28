/*
 * Bullet.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef Bullet_H_
#define Bullet_H_

#include "DumbAlien.h"

#include <SFML/Graphics.hpp>
#include <memory>

class Bullet : public sf::RectangleShape
{
public:
	Bullet( );
	virtual ~Bullet();

	void step();

private:

	int mDirection;

};


#endif /* TRACKINGALIEN_H_ */
