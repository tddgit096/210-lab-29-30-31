#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <tuple>
#include <array>
#include <animal.h>
using namespace std;

const int TOTALYEARS=25;
const int BIRTHCHANCEPREDATORS = 10, MAXAGEPREDATORS = 10 , PREDATORBIRTHAGE = 5, MAXHUNGER = 2, HUNTEFFECIENCY = 20;
const int BIRTHCHANCEPREY = 35, MAXAGEPREY = 7, PREYBIRTHAGE = 3;

class disease{
    private:
    string name;
    int outbreakChance;
    int infectionChance;
    int currentDuration;
    int maxDuration;
    int lethalityPreyChance;
    int lethalityPredatorChance;
    int cureChance;
    //METHODS=====
    public:
    //setters and getters
    void setName(string n){name=n;}
    void setOutbreakChance(int c){outbreakChance=c;}

    //constructors

    //class functions    
    void infectRandomPopulation(list<prey> &p){
        if (rand() > outbreakChance){
            return //no one was infected by this disease this year
        }  
        for(auto P : p){
            P.setDisease(this);
        }
    }
};



//class predator{
    //MEMBERS=====
    //string name;
    //int huntefficiency; //% to succeed in a hunt
    //int BIRTHCHANCEPREDATORS;
    //int age;
    //disease diseaseHolder;
    //int hunger;
    //METHODS=====
    //lifetick()
        //if age>MAXAGEPREDATORS || hunger>=MAXHUNGER
            //die
        //resolveDisease()
        //if age>PREDATORBIRTHAGE && !hunger
            //if rand() < birthchance
    //die
    //birth
        //if rand()%100 < birthChance() && hunger==0
            //new Predator
    //hunt(&list)
        //auto it = list.begin(), list.end()
            //int currentfood = 1
            // if (rand()%100 <huntefficiency)
                //if it->disease
                    //disease = it->disease
                //delete element from list
                //currentfood++
            //if currentfood==yearlyfood
                //hunger--
                //return
        // else
            //hunger++
    //resolveDisease()
        //if disease
            //if disease.currentDuration >= disease.maxDuration
                //delete disease
                //disease = null
            //else 
                //resolveDisease
        //if rand()%100+1 < lethalityPredatorChance
            //die
}
//prey class
    //MEMBERS=====
    //name
    //age
    //Disease disease
    //METHODS=====
    //die
    //birth
    //resolveDisease

//RunSimluation(&map)
    //print(map)
    //int i = 1
    //while(<TOTALYEARS)
        //For all diseases:
            //disease.infectRandomPopulation(list of prey)
        //For all predators:
            //predator.hunt(list of prey)
        //for all prey
            //prey.lifetick
            //birthChance
        //for all predators
            //predator.lifetick
            //birthChance

        //print(map)

//print(map)
    //iterate through, print every element. neatly organized

int main(){
    //make map, holding tuple of animal and disease types.
    map<string,tuple<animal,animal,disease>> predatorMap ={
        {"Coyotes", make_tuple(list<animal>(), list<animal>(), list<disease>())},
        {"Lions", make_tuple(list<animal>(), list<animal>(), list<disease>())},
        {"Orcas", make_tuple(list<animal>(), list<animal>(), list<disease>())}
    };
    ifstream finPred("dataPred.txt");
    ifstream finPrey("dataPrey.txt");
    ifstream finDiseas("dataDiseas.txt");
    if(!finPred){cout<<"dataPred.txt not found. Terminating.";return 0;}
    while (true)
    fin.close();   


    return 0;
}
    //map containing {Coyotes, Lions, Orcas}
        //3 arrays of lists. List 1 contains members of predator population, with a name, their age, whether they are sick, and when they have last eaten.
        //list 2 conatins members of the prey population, with a name, with an age, and whether they have a disease.
        //list 3 contains diseases, which may infect and decrease the predator population
    //read from data to enter the population of predators, prey, and disease vectors.
        //populate predators by name and age. hunger starts at 0
        //populate prey by name and age.
        //populate diseaseVectors
    //RunSimluation(&map)