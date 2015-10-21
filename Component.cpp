/*
 * Component.cpp
 *
 *  Created on: 20 Oct 2015
 *      Author: pmb14
 */

#include <iostream>
#include <stdlib.h>

#include "Component.h"

Component::~Component() {
    free(forward);
    free(backward);
}

//returns position of char going forwards
int Component::forwardsGetChar(int charNum) {
    charNum = (charNum + forward->at(charNum)) % 26 ;
    return charNum;
}

//returns position of char going backwards
int Component::backwardsGetChar(int charNum) {
    charNum = (charNum + 26 - backward->at(charNum)) % 26;
    return charNum;
}

void Component::calculateBackwardSettings() {
    for (unsigned int start = 0; start < forward->size(); start++) {
        int end = (start + forward->at(start)) % 26;
        backward->at(end) = forward->at(start);
    }
}
