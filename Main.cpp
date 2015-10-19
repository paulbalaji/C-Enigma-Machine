#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include <typeinfo> //TESTING

#include "Rotor.h"

using namespace std;

int main(int argc, char **argv)
{
    //keep track of all rotors
//    vector<shared_ptr<Rotor>> rotors;
    vector<Rotor> rotors;

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
//        shared_ptr<vector<int>> rotor_config;
        vector<int> *rotor_config = new vector<int>;
        for (int j = 0; j < 26; j++) {
//        while (!rotor.eof()) {
            string value;
            rotor >> value;
            cout << "before: " << typeid(value).name() << endl; //TESTING
            int x = stoi(value);
            cout << "after: " << typeid(x).name() << endl; //TESTING
            rotor_config->push_back(x); //CAUSING PROBLEMS
            cout << "doesn't reach this statement" << endl;
        }

        cout << "got here?" << endl;
//        shared_ptr<Rotor> r(new Rotor(rotor_config));
        Rotor r = new Rotor(rotor_config);
        cout << "adding to rotors" << endl;
        rotors.push_back(r);

        rotor.close();
    }

    //Make a plugboard object
    ifstream plugboard(argv[argc-1]);
    
    //error handling if file can't be opened
    if (!plugboard) {
        runtime_error("Error opening the plugboard file.");
        exit(1);
    }

    //get plugboard information from file, add to vector
//    shared_ptr<vector<int>> plugboard_config;
    vector<int> *plugboard_config = new vector<int>;
    while (!plugboard.eof()) {
        string plug;
        plugboard >> plug;
        cout << "before: " << typeid(plug).name() << endl; //TESTING
        int x = stoi(plug);
        cout << "after: " << typeid(x).name() << endl; //TESTING
        plugboard_config->push_back(x);
    }

    plugboard.close();

    return 0;
}
