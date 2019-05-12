/*
 * CircleAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef CIRCLEALIEN_H_
#define CIRCLEALIEN_H_

#include "SpaceObject.h"

#include <SFML/Graphics.hpp>
#include <memory>

class CircleAlien : public sf::CircleShape, public virtual SpaceObject
{
public:
	CircleAlien( int radius = 16 );
	virtual ~CircleAlien();

	void setTarget( std::shared_ptr<sf::CircleShape> newTarget );

	void step();

private:

	std::shared_ptr<sf::CircleShape> mTarget;
	int mradius;
	int xcenter;
	int ycenter;
	float angle;

};


#endif /* TRACKINGALIEN_H_ */
