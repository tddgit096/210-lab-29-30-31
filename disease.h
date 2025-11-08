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
    // Constructors
    disease();
    

    // setters and getters
    void set_name(string n)                     { name = n; };
    string get_name() const                     { return name; };
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
    disease(const disease& d){
        set_name(d.get_name());
        set_massOutbreakChance(d.get_massOutbreakChance());
        set_currentDuration(d.get_currentDuration());
        set_maxduration(d.get_maxdurat)
        set_lethalityChance
        set_cureChance
    }
    }

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