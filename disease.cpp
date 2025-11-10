


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
