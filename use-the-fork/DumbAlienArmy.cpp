/*
 * DumbAlienArmy.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "DumbAlienArmy.h"

DumbAlienArmy::DumbAlienArmy( int column, int rows ) :
	std::vector<std::shared_ptr<DumbAlien>>(column * rows),
	mDirection(1)
{
	for( auto &soldier : *this ) {
		soldier = std::make_shared<DumbAlien>();
	}

	for( int icol=0; icol<column; icol++ ) {
		for( int irow=0; irow<rows; irow++) {
			at(icol*rows+irow)->setPosition(300+100*icol,25+50*irow);
		}
	}
}


DumbAlienArmy::~DumbAlienArmy() = default;

void DumbAlienArmy::setTarget( std::shared_ptr<sf::CircleShape> newTarget ) {
	mTarget = newTarget;
}


void DumbAlienArmy::step() {
	for( auto &soldier : *this ) {
		soldier->step();
	}
}

void DumbAlienArmy::setFillColor( sf::Color newColor ) {
	for( auto &soldier : *this ) {
		soldier->setFillColor( newColor );
	}
}


