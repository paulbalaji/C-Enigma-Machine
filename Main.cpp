#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "Component.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

using namespace std;

void getRotors(int, char**, vector<Component*>*);
Component* getPlugboard(int, char**);
char runMachine(vector<Component*>*, char);
void turnRotors(vector<Component*>*);
int charToInt(char);
char intToChar(int);

int main(int argc, char** argv)
{
    //need a way to keep track of all the components
    vector<Component*> components;

	//get plugboard settings
	Component* plugboard = getPlugboard(argc, argv);
	components.push_back(plugboard);

	//get the rotors and all their settings
    getRotors(argc, argv, &components);

    //get the reflector
    Component* reflector = new Reflector();
    components.push_back(reflector);

    while (!cin.eof()) {
        char test;
        cin >> test;
        if (cin.eof()) {
            break;
        }
        while (test == ' ' || test == '\n' || test == '\t' || test == '\r') {
            cin >> test;
        }
        char output = runMachine(&components, test);
        turnRotors(&components);
        cout << output;
    }

    //free components
    for (Component* c : components) {
        free(c);
    }

    //free list of arguments
    for (int i = 0; i < argc; i++) {
        free(argv[argc]);
    }

    return 0;
}

void getRotors(int argc, char** argv, vector<Component*>* components) {
    //Make rotor objects here
    for (int i = 1; i < argc - 1; i++) {
        //input stream
        ifstream rotorFile(argv[i]);

        //error handling if file can't be opened
        if (!rotorFile) {
            runtime_error("Error opening a rotor file.");
            exit(1);
        }

        //get rotor information from file, add to vector
        vector<int>* rotor_config = new vector<int>;
        for (int j = 0; j < 26; j++) {
            int value;
            rotorFile >> value;
            rotor_config->push_back(value);
        }

        components->push_back(new Rotor(rotor_config));

        rotorFile.close();
    }
}

Component* getPlugboard(int argc, char** argv) {
    //Make a plugboard object
    ifstream plugboardFile(argv[argc-1]);

    //error handling if file can't be opened
    if (!plugboardFile) {
        runtime_error("Error opening the plugboard file.");
        exit(1);
    }

    //get plugboard information from file, add to vector
    vector<int>* plugboard_config = new vector<int>;
    while (!(plugboardFile.peek() == EOF)) {
        string plug;
        plugboardFile >> plug;
        if (plug[plug.length()-1] >= '0' && plug[plug.length()-1] <= '9') {
            plugboard_config->push_back(stoi(plug));
        }
    }

    plugboardFile.close();

    return new Plugboard(plugboard_config);
}

int charToInt(char character) {
    if (character >= 'A' || character <= 'Z') {
        return character - 'A';
    }

    runtime_error("Only allowed to enter capital A-Z.");
    exit(1);
}

char intToChar(int charNum) {
    //no checks needed here as charToInt sorts everything out first
    return 'A' + charNum;
}

char runMachine(vector<Component*>* components, char character) {
    int charNum = charToInt(character);

    //go forwards in the machine
    for (unsigned int i = 0; i < components->size(); i++) {
        charNum = components->at(i)->forwardsGetChar(charNum);
    }

    //go backwards in the machine
    for (int i = components->size() - 2; i >= 0; i--) {
        charNum = components->at(i)->backwardsGetChar(charNum);
    }

    //return translated int back into encoded character
    return intToChar(charNum);
}

void turnRotors(vector<Component*>* components) {
    bool needToTurn = true;
    for (unsigned int i = 1; i < components->size() - 1; i++) {
        if (needToTurn) {
            needToTurn = components->at(i)->rotorTurn();
//            cout << components->at(i)->getNumOfTurns();
        } else {
            //if don't need to turn, nothing else needs to turn
            break;
        }
    }
}
