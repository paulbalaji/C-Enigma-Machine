/*
 * Reflector.cpp
 *
 *  Created on: 20 Oct 2015
 *      Author: paul
 */

#include "Reflector.h"

Reflector::Reflector() {
    //use the algorithm given in the spec
    settings = new vector<int>;
    for (int i = 0; i < 26; i++) {
        //offset is 13, so set each field to 13
        settings->push_back(13);
    }
}
