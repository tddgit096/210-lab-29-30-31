// animal.h

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <vector>
#include <list>
//#include "disease.h" //do not include, causes circular dependency
using namespace std;

const int HUNTATTEMPTSPERYEAR = 2, HUNTSUCCESSCHANCE = 10, TRANSMISSIONCHANCE = 50;
const int MAXAGE = 10;

class disease; //forward declaration instead of include header. I had to research this.


class animal {
private:
    string name;
    int age;
    vector<disease*> DiseaseHolder; //a vector of pointers
    bool isPredator;

public:
    void print();
    string genRandName();
    void lifetick();
    void diseasetick();
    void hunt(list<animal> &p);
    void die();
    // Constructors
    animal()                          { name = genRandName(); age = 0; }
    animal(bool ispred)               { name = genRandName(); age = 0; isPredator=ispred;}
    animal(string name)               { set_name(name);set_age(0);isPredator=false;}
    animal(string name, bool ispred)  { set_name(name);set_age(0); isPredator=ispred;}
    animal(string name,int age, bool ispredator = false)               { set_name(name);set_age(age);isPredator = ispredator;}
    ~animal(); 

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name()               { return name; };
    void set_age(int a)             { age = a; };
    int get_age()                   { return age; }
    const vector<disease*>& getDisease() const  { return DiseaseHolder;}
    void setDisease(disease *disease) {DiseaseHolder.push_back(disease);}
};
#endif