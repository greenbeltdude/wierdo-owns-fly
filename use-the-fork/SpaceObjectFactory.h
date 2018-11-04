/*
 * DumbAlien.h
 *
 *  Created on: Oct 20, 2018
 *      Author: george
 */

#ifndef SpaceObjectFactory_H_
#define SpaceObjectFactory_H_

#include "SpaceObject.h"

#include <memory>
#include <vector>

class SpaceObjectFactory : public std::vector<std::shared_ptr<SpaceObject>>
{
public:
	SpaceObjectFactory();
	virtual ~SpaceObjectFactory();

	bool checkForCollisions();

	void setTarget( std::shared_ptr<SpaceObject> newTarget );

    void step();

private:

	std::shared_ptr<SpaceObject> mTarget;

};


#endif
