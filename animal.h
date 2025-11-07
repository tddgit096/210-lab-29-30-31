// animal.h

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;

class animal {
private:
    string name;
    int age;
    disease DiseaseHolder;
    bool isPredator;

public: 
    string genRandName();
    // Constructors
    animal()                          { name = genRandName(); age = 0; }
    animal(bool ispred)               { name = genRandName(); age = 0; isPredator=ispred;}
    animal(string name)               { set_name(name);set_age(0);isPredator=false;}
    animal(string name, bool ispred)  { set_name(name);set_age(0); isPredator=ispred;}
    animal(string name,int age, bool ispredator = false)               { set_name(name);set_age(age);isPredator = ispredator;}


    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    disease* getDisease()           { return &DiseaseHolder;}
    void setDisease(disease)        {}//TODO, make a instantiated copy of the class type, transfer the info, but set disease incubation time to 0;

    string genRandName(){
        string name;
        if(isPredator){
            name+="PRDTR_ID(";
        }
        else{
            name+="PREY_ID(";
        }
        name+=rand()%1000;
        name+=")";
        return name;
    }
};

#endif