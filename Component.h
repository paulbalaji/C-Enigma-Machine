/*
 * Component.h
 *
 *  Created on: 20 Oct 2015
 *      Author: pmb14
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <vector>

using namespace std;

class Component {
public:
	int forwardsGetChar(int);
	int backwardsGetChar(int);

protected:
	vector<int>* settings;
};


#endif /* COMPONENT_H_ */
