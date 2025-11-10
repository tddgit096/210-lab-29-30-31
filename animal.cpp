#include "animal.h"
#include "disease.h" 
#include <list>

void animal::hunt(list<animal> &p){
    if (p.empty()) {
        return;
    }
    for(int i = 0; i<HUNTATTEMPTSPERYEAR;i++){ //how many attempts to hunt? 
        if(rand()%100<HUNTSUCCESSCHANCE){
            int index = rand()%p.size() -1;//get random index
            auto it = p.begin();    //make an iterator at start of the list
            advance(it,index);       //advance to the index we gen'd
            vector<disease*>& targetDiseases = it->getDisease();
            if(!targetDiseases.empty()){ //target is sick
                for (disease* d : targetDiseases) {  
                    if(rand()%100<TRANSMISSIONCHANCE)
                        setDisease(d); 
                }
            }
            it->die();
        }
    }
}

void animal::lifetick(){
    age++;
    if (age>MAXAGE){
        die();
    }
    diseasetick();
}

void animal::diseasetick(){
    for (auto it = DiseaseHolder.begin(); it != DiseaseHolder.end(); ){
        disease* d = *it; //disease pointer to dereferenced iterator
        d->set_currentDuration(d->get_currentDuration()+1);
        if(d->get_currentDuration()>d->get_maxduration()){ //cured with time
            delete d;
            it = DiseaseHolder.erase(it); //erases it and gets the next iterator, I had to research this.
        }
        if (rand()%100 < d->get_lethalityChance()){
            die();
        }
        else if (rand()%100 < d->get_cureChance()) {
            delete d;
            it = DiseaseHolder.erase(it); //erases it and gets the next iterator, I had to research this.
        }
    }
}

string animal::genRandName(){
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
void animal::print(){
    cout<<"["<<get_name()<<" / AGE:"<<get_age<<" : ";
    if(DiseaseHolder.size()>0){
        cout<<"DISEASES: ";
        for (disease * d : DiseaseHolder) {
            cout<<d->get_name()<<" ";
        }
    }
    cout<<"]";
}

void animal::die(){
    delete this;
}

animal::~animal(){
    //delete all pointers for diseases vector
    for (disease* d : DiseaseHolder) {
        delete d;
    }
    //clear the pointers in the vector.
    DiseaseHolder.clear();
}