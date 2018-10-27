/*
 * TrackingAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef TRACKINGALIEN_H_
#define TRACKINGALIEN_H_

#include <SFML/Graphics.hpp>
#include <memory>

class TrackingAlien : public sf::CircleShape
{
public:
	TrackingAlien( int radius = 5 );
	virtual ~TrackingAlien();

	void setTarget( std::shared_ptr<sf::CircleShape> newTarget );

	void step();

private:

	std::shared_ptr<sf::CircleShape> mTarget;

};


#endif /* TRACKINGALIEN_H_ */
