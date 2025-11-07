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
    animal()                          { name = ""; age = 0; }
    // write three more constructors
    animal(string name)               { set_name(name);set_age(0)}
    animal(string name,int age, bool ispredator = false)               { set_name(name);set_age(age);isPredator = ispredator;}



    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    genRandName()

};

#endif