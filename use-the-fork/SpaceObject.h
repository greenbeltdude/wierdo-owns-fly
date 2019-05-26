/*
 * DumbAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef SpaceObject_H_
#define SpaceObject_H_

#include <SFML/Graphics.hpp>

#include <memory>

class SpaceObject
{
public:
	SpaceObject( sf::Shape *shape );
	virtual ~SpaceObject();

	bool isExploding() const;
	
	void setIsExploding();

	virtual void step() = 0;

	bool destroyed() const;

	sf::Shape *shape() const;

private:

	bool mIsExploding;
	bool mDestroyed;
	sf::Shape *mShape;

};


#endif
