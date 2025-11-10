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
    void infectRandomPopulation(list<animal*> &p);
    void print();

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
    disease(disease& d){
        //if a disease is passed, it will be copied, except current duration will be 0.
        set_name(d.get_name());
        set_massOutbreakChance(d.get_massOutbreakChance());
        set_currentDuration(0);
        set_maxduration(d.get_maxduration());
        set_lethalityChance(d.get_lethalityChance());
        set_cureChance(d.get_cureChance());
    }
        //default constructor
    disease(string name = "empty",
        int massOutbreakChance = DEFAULTMASSOUTBREAKCHANCE ,
        int maxDuration = DEFAULTMAXDURATION,
        int lethalityChance = DEFAULTLETHALITYCHANCE,
        int cureChance = DEFAULTCURECHANCE)
        {
        if(name == "empty"){
            name = genRandName();
        }
        this->set_name(name);
        this->set_massOutbreakChance(massOutbreakChance);
        this->set_currentDuration(0);
        this->set_maxduration(maxDuration);
        this->set_lethalityChance(lethalityChance);
        this->set_cureChance(cureChance);
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

    void infectRandomPopulation(list<animal*> &popList){
        if (rand() > massOutbreakChance){
            return ;//no one was infected by this disease this year
        }  
        for(auto P : popList){
            disease *dptr = this;
            P.setDisease(dptr);
        }
    }

    void print(){
        cout<<"["<<get_name()<<"]";
    }
};

#endif