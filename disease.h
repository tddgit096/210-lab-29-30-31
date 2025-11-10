// disease.h

#ifndef DISEASE_H
#define DISEASE_H
//#include "animal.h" causes error, I have to use forward declaration
#include <iostream>
#include <list>
using namespace std;

class animal; //forward declaration instead of include header. I had to research this.

const int DEFAULTMASSOUTBREAKCHANCE = 10, DEFAULTMAXDURATION =5, DEFAULTLETHALITYCHANCE = 10, DEFAULTCURECHANCE = 10;

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
    void print();

    // setters and getters
    void set_name(string n)                     { name = n; };
    string get_name()                           { return name; };
    void set_massOutbreakChance(int chance)     { massOutbreakChance = chance;};
    int get_massOutbreakChance()                { return massOutbreakChance;}
    void set_currentDuration(int duration)      { currentDuration = duration;};
    int get_currentDuration()                   { return currentDuration;}
    void set_maxduration(int chance)            { maxDuration = chance;};
    int get_maxduration()                       { return maxDuration;}
    void set_lethalityChance(int chance)        { lethalityChance = chance;};    
    int get_lethalityChance()                   { return lethalityChance;}
    void set_cureChance(int chance)             { cureChance=chance;}
    int get_cureChance()                        { return cureChance;}
    //constructors
    disease(string name = "empty",
    int massOutbreakChance = DEFAULTMASSOUTBREAKCHANCE ,
    int maxDuration = DEFAULTMAXDURATION,
    int lethalityChance = DEFAULTLETHALITYCHANCE,
    int cureChance = DEFAULTCURECHANCE); //parametric and also default
    disease(disease& d);//pass self to duplicate

};
#endif