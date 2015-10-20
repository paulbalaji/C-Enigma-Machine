#ifndef ROTOR_H_
#define ROTOR_H_

#include <vector>
#include <stdlib.h>

#include "Component.h"

using namespace std;

class Rotor : public Component {
public:
    Rotor(vector<int>*);
    ~Rotor();
    bool rotorTurn();
    int forwardsGetChar(int);
    int backwardsGetChar(int);

private:
    int numOfTurns;
    void calculateOffset();

};

#endif /* ROTOR_H_ */
