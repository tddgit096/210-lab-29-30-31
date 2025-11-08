// disease.h

#ifndef DISEASE_H
#define DISEASE_H
#include <iostream>
#include <animal.h>
#include <list>
using namespace std;

class disease {
private:
    string name;
    int massOutbreakChance; //percentile val between 0-100. Chance every year a mass outbreak occurs.
    int currentDuration;//used by animal class to track time spent sick 
    int maxDuration; //maxDuration a disease can be active in an animal.
    int lethalityChance;
    int cureChance;



public: 
    string genRandName();
    void infectRandomPopulation(list<animal> &p);
    void copyDisease(disease d){
        
    }
    // Constructors
    disease();
    

    // setters and getters


    // Methods
    string genRandName(){
        srand(time(NULL));
        string name = "";
        name += ('A' + rand() % 26); //random character 1
        name += ('A' + rand() % 26); //random character 2
        name += to_string(rand()%100);
        return name;
    }
    void infectRandomPopulation(list<animal> &p){
        if (rand() > massOutbreakChance){
            return ;//no one was infected by this disease this year
        }  
        for(auto P : p){
            //P.setDisease(this);
        }
    }
};

#endif