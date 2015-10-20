/*
 * Plugboard.cpp
 *
 *  Created on: 19 Oct 2015
 *      Author: paul
 */

#include "Plugboard.h"

Plugboard::Plugboard(vector<int>* settings) {
    this->settings = settings;
}

Plugboard::~Plugboard() {
	free(settings);
}
