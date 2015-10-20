#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>

#include "Rotor.h"
#include "Plugboard.h"

using namespace std;

void getRotors(int, char**, vector<Rotor*>);
Plugboard* getPlugboard(int, char**);

int main(int argc, char** argv)
{
	//make plugboard
	Plugboard* plugboard = getPlugboard(argc, argv);

	//keep track of all rotors
    vector<Rotor*> rotors;

    getRotors(argc, argv, rotors);

    return 0;
}

void getRotors(int argc, char** argv, vector<Rotor*> rotors) {
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
            string value;
            rotorFile >> value;
            rotor_config->push_back(stoi(value)); //CAUSING PROBLEMS
        }

        rotors.push_back(new Rotor(rotor_config));

        rotorFile.close();
    }
}

Plugboard* getPlugboard(int argc, char** argv) {
    //Make a plugboard object
    ifstream plugboardFile(argv[argc-1]);

    //error handling if file can't be opened
    if (!plugboardFile) {
        runtime_error("Error opening the plugboard file.");
        exit(1);
    }

    //get plugboard information from file, add to vector
    vector<int>* plugboard_config = new vector<int>;
    while (!plugboardFile.eof()) {
        string plug;
        plugboardFile >> plug;
        plugboard_config->push_back(stoi(plug));
    }

    plugboardFile.close();

    return new Plugboard(plugboard_config);
}
