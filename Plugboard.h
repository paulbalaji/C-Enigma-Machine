/*
 * Plugboard.h
 *
 *  Created on: 19 Oct 2015
 *      Author: paul
 */

#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

#include <vector>

using namespace std;

class Plugboard {
public:
    Plugboard(vector<int>*);
    void blah();

private:
    vector<int>* settings;
};



#endif /* PLUGBOARD_H_ */
