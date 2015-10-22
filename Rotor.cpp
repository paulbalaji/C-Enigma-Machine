#include "Rotor.h"

#include <algorithm>

Rotor::Rotor(vector<int>* settings) {
    this->forward = settings;
    this->numOfTurns = 0;
    calculateOffsets();
}

//converts vector of configuration into offsets for easier use
void Rotor::calculateOffsets() {
    for (int i = 0; i < 26; i++) {
        int temp = forward->at(i);
        temp = (temp + 26 - i) % 26;
        forward->at(i) = temp;
    }

    backward = new vector<int>;
    for (int i = 0; i < 26; i++) {
        backward->push_back(0);
    }

    calculateBackwardSettings();
}

//return true if need to turn next rotor
bool Rotor::rotorTurn() {
    rotate(forward->begin(), forward->begin()+1, forward->end());
    calculateBackwardSettings();

    ++numOfTurns;
    if (numOfTurns == 26) {
        numOfTurns = 0;
        return true;
    }

    return false;
}

int Rotor::getNumOfTurns() {
    return numOfTurns;
}
