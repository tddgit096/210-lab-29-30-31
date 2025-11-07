// disease.h

#ifndef DISEASE_H
#define DISEASE_H
#include <iostream>
using namespace std;

class disease {
private:
    string name;
    int massOutbreakChance; //percentile val between 0-100. Chance every year a mass outbreak occurs.
    int currentDuration;//used by animal class to track time spent sick 
    int maxDuration;


public: 
    string genRandName();
    // Constructors
    disease()

    // setters and getters

    string genRandName(){
        srand(time(NULL));
        string name = "";
        name += ('A' + rand() % 26); //random character 1
        name += ('A' + rand() % 26); //random character 2
        name += to_string(rand()%100);
        return name;
    }
};

#endif