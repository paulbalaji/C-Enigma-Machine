/*
 * Component.h
 *
 *  Created on: 20 Oct 2015
 *      Author: pmb14
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <stdlib.h>
#include <vector>

using namespace std;

class Component {
public:
    ~Component();
	int forwardsGetChar(int);
	int backwardsGetChar(int);
	void calculateBackwardSettings();
	virtual bool rotorTurn() = 0;

protected:
	vector<int>* forward = NULL;
	vector<int>* backward = NULL;
};

#endif /* COMPONENT_H_ */
