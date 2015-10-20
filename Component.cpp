/*
 * Component.cpp
 *
 *  Created on: 20 Oct 2015
 *      Author: pmb14
 */

#include <stdlib.h>

#include "Component.h"

Component::~Component() {
    free(settings);
}

//returns position of char going forwards
int Component::forwardsGetChar(int charNum) {
    charNum = (charNum + this->settings->at(charNum)) % 26 ;
    return charNum;
}

//returns position of char going backwards
int Component::backwardsGetChar(int charNum) {
    charNum = (charNum + 26 - this->settings->at(charNum)) % 26;
    return charNum;
}


