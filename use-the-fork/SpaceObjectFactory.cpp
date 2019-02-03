/*
 * SpaceObjectFactory.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "SpaceObjectFactory.h"

std::shared_ptr<SpaceObjectFactory> SpaceObjectFactory_mInstance = nullptr;

SpaceObjectFactory::SpaceObjectFactory() = default;

SpaceObjectFactory::~SpaceObjectFactory() = default;

std::shared_ptr<SpaceObjectFactory> SpaceObjectFactory::instance() {
	if (SpaceObjectFactory_mInstance == nullptr) {
		SpaceObjectFactory_mInstance = std::make_shared<SpaceObjectFactory>();
	}
	return SpaceObjectFactory_mInstance;
}

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
