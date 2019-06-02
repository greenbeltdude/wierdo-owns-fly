/*
 * SpaceObject.cpp
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#include "SpaceObject.h"


SpaceObject::SpaceObject( sf::Shape *shape ) :
mShape( shape ),mIsExploding(false),mDestroyed(false),
mType("Unknown"),mValue(0)
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
int SpaceObject::value() const {
	return mValue;
}
void SpaceObject::setValue(int newvalue){
mValue=newvalue;
}
std::string SpaceObject::type() const {
    return mType;
}
void SpaceObject::setType(std::string newtype){
mType=newtype;
}
