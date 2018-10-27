/*
 * TrackingAlienArmy.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "TrackingAlienArmy.h"

TrackingAlienArmy::TrackingAlienArmy( int column, int rows ) :
	std::vector<std::shared_ptr<TrackingAlien>>(column * rows),
	mDirection(1)
{
	for( auto &soldier : *this ) {
		soldier = std::make_shared<TrackingAlien>(10);
	}

	for( int icol=0; icol<column; icol++ ) {
		for( int irow=0; irow<rows; irow++) {
			at(icol*rows+irow)->setPosition(300+100*icol,25+50*irow);
		}
	}
}


TrackingAlienArmy::~TrackingAlienArmy() = default;

void TrackingAlienArmy::setTarget( std::shared_ptr<sf::CircleShape> newTarget ) {
	for( auto &soldier : *this ) {
		soldier->setTarget( newTarget );
	}
}


void TrackingAlienArmy::step() {
	for( auto &soldier : *this ) {
		soldier->step();
	}
}

void TrackingAlienArmy::setFillColor( sf::Color newColor ) {
	for( auto &soldier : *this ) {
		soldier->setFillColor( newColor );
	}
}


