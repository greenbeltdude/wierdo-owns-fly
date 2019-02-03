/*
 * Player.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef PLAYER_H_
#define PLAY_
#include "SpaceObject.h"


#include <SFML/Graphics.hpp>
#include <memory>

class Player : public sf::CircleShape, public virtual SpaceObject
{
public:
	Player( int radius = 5 );
	virtual ~Player();
    void fire();
	void step();

private:


};


#endif
