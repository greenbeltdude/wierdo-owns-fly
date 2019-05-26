/*
 * SpaceObject.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "SpaceObject.h"


SpaceObject::SpaceObject( sf::Shape *shape ) :
mShape( shape ),mIsExploding(false),mDestroyed(false)
{}

SpaceObject::~SpaceObject() = default;

bool SpaceObject::isExploding() const {
	return mIsExploding;
}
void SpaceObject::setIsExploding(){
	mIsExploding=true;
}
bool SpaceObject::destroyed() const {
		return mDestroyed;
}


sf::Shape *SpaceObject::shape() const {
	return mShape;
}
