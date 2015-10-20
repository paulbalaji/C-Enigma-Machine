/*
 * Plugboard.h
 *
 *  Created on: 19 Oct 2015
 *      Author: paul
 */

#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

#include <vector>
#include <stdlib.h>

#include "Component.h"

using namespace std;

class Plugboard : public Component {
public:
    Plugboard(vector<int>*);
private:
    void firstTimeConfig(vector<int>*);
};

#endif /* PLUGBOARD_H_ */
