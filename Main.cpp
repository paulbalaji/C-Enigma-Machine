#include <stdexcept>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
    //Make rotor objects here
    for (int i = 1; i < argc - 1; i++) {
        //input stream
        ifstream rotor(argv[i]);

        //error handling if file can't be opened
        if (!rotor) {
            runtime_error("Error opening a rotor file.");
            exit(1);
        }

        //get rotor information from file, add to vector
        vector<int> rotor_config;
        for (int j = 0; j < 26; j++) {
            string value;
            rotor >> value;
            rotor_config.push_back(stoi(value));
        }
    }

    //Make a plugboard object
    ifstream plugboard(argv[argc-1]);
    
    //error handling if file can't be opened
    if (!plugboard) {
        runtime_error("Error opening the plugboard file.");
        exit(1);
    }

    //get plugboard information from file, add to vector
    vector<int> plugboard_config;
    while (!plugboard.eof()) {
        string plug;
        plugboard >> plug;
        plugboard_config.push_back(stoi(plug));
    }

    return 0;
}
