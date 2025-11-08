// animal.h

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <vector>
#include <disease.h>
using namespace std;

const int HUNTATTEMPTSPERYEAR = 2, HUNTSUCCESSCHANCE = 10, TRANSMISSIONCHANCE = 50;


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
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    vector<disease*> getDisease()   { return DiseaseHolder;}
    void setDisease(disease *disease) {DiseaseHolder.push_back(disease);}

    void hunt(list<animal> &p){
        if (p.empty()) {
            return;
        }
        for(int i = 0; i<HUNTATTEMPTSPERYEAR;i++){ //how many attempts to hunt? 
            if(rand()%100<HUNTSUCCESSCHANCE){
                int index = rand()%p.size() -1;//get random index
                auto it = p.begin();    //make an iterator at start of the list
                advance(it,index);       //advance to the index we gen'd
                if(it->getDisease().size()>0){ //target is sick
                    for (auto diseaseIt = (it->getDisease()).begin(); diseaseIt != (it->getDisease()).end(); ++diseaseIt) {
                        if(rand()%100<TRANSMISSIONCHANCE)
                           setDisease(*diseaseIt); 
                    }
                }
                it->die();
            }
        }
    }

    void lifetick(){
        //TODO
    }

    string genRandName(){
        srand(time(NULL));
        string name="";
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
    void print(){
        cout<<"["<<get_name()<<" / AGE:"<<get_age<<" : ";
        if(DiseaseHolder.size()>0){
            cout<<"DISEASES: ";
            for (disease * d : DiseaseHolder) {
                cout<<d->get_name()<<" ";
            }
        }
        cout<<"]";
    }
    
    void die(){
        delete this;
    }

    ~animal(){
        //delete all pointers for diseases vector
        for (disease* d : DiseaseHolder) {
            delete d;
        }
        //clear the pointers in the vector.
        DiseaseHolder.clear();
    }
}

#endif