/*
 * TrackingAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef TRACKINGALIENARMY_H_
#define TRACKINGALIENARMY_H_

#include "TrackingAlien.h"

#include <SFML/Graphics.hpp>
#include <memory>

class TrackingAlienArmy : public std::vector<std::shared_ptr<TrackingAlien>>
{
public:
	TrackingAlienArmy( int column, int rows );
	virtual ~TrackingAlienArmy();

	void setFillColor( sf::Color newColor );

	void setTarget( std::shared_ptr<sf::CircleShape> newTarget );

	void step();

private:

	int mDirection;

};


#endif /* TRACKINGALIEN_H_ */
