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
const string OUTPUTBAR = "=========================================================";
//const int BIRTHCHANCEPREDATORS = 10, MAXAGEPREDATORS = 10 , PREDATORBIRTHAGE = 5, MAXHUNGER = 2, HUNTEFFECIENCY = 20;
//const int BIRTHCHANCEPREY = 35, MAXAGEPREY = 7, PREYBIRTHAGE = 3;

void run_simulation(map<string,tuple<list<animal>,list<animal>,list<disease>>> &mapMaster);
void print(map<string,tuple<list<animal>,list<animal>,list<disease>>> mapMaster, int year);



int main(){
    //make map, holding tuple of animal and disease types.
    map<string,tuple<list<animal>,list<animal>,list<disease>>> predatorMap ={
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

    run_simulation(predatorMap);
    return 0;
}


//FUNCTIONS=======================================
//runs the simulation for duration of TOTALYEARS 
void run_simulation(map<string,tuple<list<animal>,list<animal>,list<disease>>> &mapMaster){
    int year = 1;
    while(year<TOTALYEARS){
        for (auto it = mapMaster.begin(); it != mapMaster.end(); ++it) {
            auto &tempTuple = it->second;
            list<animal>& predatorList = get<0>(tempTuple);
            list<animal>& preyList = get<1>(tempTuple);
            list<disease>& diseaseList = get<2>(tempTuple);
            //iterate through diseases:
            for (disease & d : diseaseList) {
                d.infectRandomPopulation(preyList);//potentially infect the prey population     
            }         
            //iterate through predators   
            for (animal & a : predatorList) {
                //a.hunt()//TODO, make hunt proc and call it on all predators.
                //same with lifetick, which calls diseaseresolve
            }
            //iterate through prey
            for (animal & a : predatorList) {
                //just call lifetick
            }
        }
        year++;
    }
    print(mapMaster);
}

//prints the function.
void print(map<string,tuple<list<animal>,list<animal>,list<disease>>> mapMaster, int year){
    cout<<OUTPUTBAR<<endl;
    cout<<"YEAR - "<<year<<endl;
    for (auto it = mapMaster.begin(); it != mapMaster.end(); ++it){
        cout<<"CATEGORY: "<<it->first<<":\n";
        auto tempTuple = it->second;
        list<animal> predatorList = get<0>(tempTuple);
        list<animal> preyList = get<1>(tempTuple);
        list<disease> diseaseList = get<2>(tempTuple);
        cout<<"PREDATORS: ";
        for (animal a : predatorList) {
            a.print();
        }
        cout<<"PREY: ";
        for (animal a : preyList) {
            a.print();
        }
        cout<<"ACTIVE DISEASES: ";
        for (disease d : diseaseList) {
            d.print();
        }
        cout<<endl;
    }
}