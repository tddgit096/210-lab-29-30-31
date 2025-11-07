#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <tuple>
#include <array>
#include <animal.h>
#include <disease.h>
#include <algorithm>
using namespace std;

const int TOTALYEARS=25;
const int BIRTHCHANCEPREDATORS = 10, MAXAGEPREDATORS = 10 , PREDATORBIRTHAGE = 5, MAXHUNGER = 2, HUNTEFFECIENCY = 20;
const int BIRTHCHANCEPREY = 35, MAXAGEPREY = 7, PREYBIRTHAGE = 3;


void runSimluation(map<string,tuple<animal,animal,disease>> &mapMaster){
    //print(map)
    int year = 1;
    while(year<TOTALYEARS){
        for (map<string,tuple<animal,animal,disease>>::iterator it = mapMaster.begin(); it != mapMaster.end(); ++it) {
            //get<0>(it->second); //predatorlist   
            for (list<animal>::iterator predatorIt = it.begin(); predatorIt != it.end(); ++predatorIt){
                
            }
            
            
            for (list<animal>::iterator predatorIt = it.begin(); predatorIt != it.end(); ++predatorIt){
                
            }
           
            for_each(get<0>(it->second).begin(), get<0>(it->second).end(), ),
            get<1>(it->second); //preylist

            get<2>(it->second); //diseaselist 
            for_each(get<3>(it->second)){

            }
            for (list<animal>::iterator predatorIt = predatorIt.begin(); it != predatorIt.end(); ++it){
                
            }

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
        year++;
    }
    //print(map)
    }
}
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
    if(!finPrey){cout<<"dataPrey.txt not found. Terminating.";return 0;}
    if(!finDiseas){cout<<"dataDiseas.txt not found. Terminating.";return 0;}
    while (true){
        //while(finPred.)   
            //TODO;
    }

    RunSimluation(&map);
    return 0;
}
