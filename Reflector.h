/*
 * Reflector.h
 *
 *  Created on: 20 Oct 2015
 *      Author: paul
 */

#ifndef REFLECTOR_H_
#define REFLECTOR_H_

#include "Component.h"

class Reflector : public Component {
public:
    Reflector();
    bool rotorTurn() {
        return false;
    }
};

#endif /* REFLECTOR_H_ */
