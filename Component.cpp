/*
 * Component.cpp
 *
 *  Created on: 20 Oct 2015
 *      Author: pmb14
 */

#include "Component.h"

//returns position of char going forwards
int Plugboard::forwardsGetChar(int charNum) {
    charNum = (charNum + this->settings->at(charNum)) % 26 ;
    return charNum;
}

//returns position of char going backwards
int Plugboard::backwardsGetChar(int charNum) {
    charNum = (charNum + 26 - this->settings->at(charNum)) % 26;
    return charNum;
}


