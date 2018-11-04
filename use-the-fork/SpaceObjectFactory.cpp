/*
 * SpaceObjectFactory.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "SpaceObjectFactory.h"

SpaceObjectFactory::SpaceObjectFactory() = default;

SpaceObjectFactory::~SpaceObjectFactory() = default;

void SpaceObjectFactory::setTarget( std::shared_ptr<SpaceObject> newTarget ) {
	mTarget = newTarget;
}

void SpaceObjectFactory::step() {
	for( auto &object : *this ) {
		object->step();
	}
	mTarget->step();
}

bool SpaceObjectFactory::checkForCollisions() {
	for( auto &object : *this ) {
		if( mTarget->shape()->getGlobalBounds().intersects(object->shape()->getGlobalBounds())) return true;
	}

	return false;
}
