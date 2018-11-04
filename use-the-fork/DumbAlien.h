/*
 * DumbAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef DUMBALIEN_H_
#define DUMBALIEN_H_

#include "SpaceObject.h"

#include <SFML/Graphics.hpp>
#include <memory>

class DumbAlien : public sf::CircleShape, public virtual SpaceObject
{
public:
	DumbAlien( int radius = 5 );
	virtual ~DumbAlien();

	void setTarget( std::shared_ptr<sf::CircleShape> newTarget );

	void step();

private:

	std::shared_ptr<sf::CircleShape> mTarget;
	int mDirection;

};


#endif /* TRACKINGALIEN_H_ */
