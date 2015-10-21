/*
 * Plugboard.cpp
 *
 *  Created on: 19 Oct 2015
 *      Author: paul
 */

#include "Plugboard.h"

Plugboard::Plugboard(vector<int>* tempSettings) {
    //need to transform this temp settings into the style used before
    //free tempSettings before closing the constructor
    firstTimeConfig(tempSettings);
}

void Plugboard::firstTimeConfig(vector<int>* temp) {
    //make settings config in similar format to others
    forward = new vector<int>;
    for (int i = 0; i < 26; i++) {
        //fill everything with 0 to start off with
        forward->push_back(0);
    }

    for (unsigned int j = 0; j < temp->size(); j+=2) {
        int first = temp->at(j);
        int second = temp->at(j+1);
        forward->at(first) = second - first;
        forward->at(second) = -1 * forward->at(first);
    }

    backward = new vector<int>;
    for (int i = 0; i < 26; i++) {
        //fill everything with 0 to start off with
        backward->push_back(0);
    }
    calculateBackwardSettings();
}
