#ifndef ROTOR_H_
#define ROTOR_H_

#include <vector>
#include <stdlib.h>

#include "Component.h"

using namespace std;

class Rotor : public Component {
public:
    Rotor(vector<int>*);
    bool rotorTurn();
    int getNumOfTurns();

private:
    int numOfTurns;
    void calculateOffsets();
};

#endif /* ROTOR_H_ */
