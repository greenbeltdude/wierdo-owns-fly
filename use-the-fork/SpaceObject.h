/*
 * DumbAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef SpaceObject_H_
#define SpaceObject_H_

#include <SFML/Graphics.hpp>

#include <memory>

class SpaceObject
{
public:
	SpaceObject( sf::Shape *shape );
	virtual ~SpaceObject();

	bool isExploding() const;
	
	void setIsExploding();
	
	std::string type() const;
	
	void setType(std::string newtype);
	
	int value() const;
	
	void setValue(int newvalue);
	
	virtual void step() = 0;

	bool destroyed() const;

	sf::Shape *shape() const;


private:

	bool mIsExploding;
	bool mDestroyed;
	sf::Shape *mShape;
	std::string mType;
	int mValue;

};


#endif
