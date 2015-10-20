#include "Rotor.h"

Rotor::Rotor(vector<int>* settings) {
    this->settings = settings;
    this->numOfTurns = 0;
    calculateOffset();
}

//converts vector of configuration into offsets for easier use
void Rotor::calculateOffset() {
    for (int i = 0; i < 26; i++) {
        int temp = this->settings->at(i);
        temp = (temp + 26 - i) % 26;
        this->settings->at(i) = temp;
    }
}

//return true if need to turn next rotor
bool Rotor::rotorTurn() {
    for (int i = 0; i < 26; i++) {
        int temp = this->settings->at(i);
        temp = (temp + 1) % 26;
        this->settings->at(i) = temp;
    }

    numOfTurns++;
    if (numOfTurns == 26) {
        numOfTurns = 0;
        return true;
    }

    return false;
}
