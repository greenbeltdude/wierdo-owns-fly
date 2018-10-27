/*
 * DumbAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef DUMBALIENARMY_H_
#define DUMBALIENARMY_H_

#include "DumbAlien.h"

#include <SFML/Graphics.hpp>
#include <memory>

class DumbAlienArmy : public std::vector<std::shared_ptr<DumbAlien>>
{
public:
	DumbAlienArmy( int column, int rows );
	virtual ~DumbAlienArmy();

	void setFillColor( sf::Color newColor );

	void setTarget( std::shared_ptr<sf::CircleShape> newTarget );

	void step();

private:

	std::shared_ptr<sf::CircleShape> mTarget;
	int mDirection;

};


#endif /* TRACKINGALIEN_H_ */
