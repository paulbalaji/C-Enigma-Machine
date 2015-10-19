#ifndef ROTOR_H_
#define ROTOR_H_

#include <vector>
#include <memory>

using namespace std;

class Rotor {
public:
    Rotor(vector<int>);
    bool rotorTurn();
    int forwardsGetChar(int);
    int backwardsGetChar(int);

private:
    int numOfTurns;
    vector<int> settings;
    void calculateOffset();

};


#endif /* ROTOR_H_ */
