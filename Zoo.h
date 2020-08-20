//
// Created by menib on 5/22/2019.
//

#ifndef UNTITLED1_ZOO_H
#define UNTITLED1_ZOO_H

#include <iostream>
#include <string>
#include<vector>
#include <sstream>
#include "Animal.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;




class Zoo {
public:
    Zoo(string maleName, string femaleName);
    inline ~Zoo(){}
    bool animalReproduce(const string &firstParentName,const string &secondParentName
            ,const string &name, Gender gender);

    bool euthanize(const string&name);

    Animal*findAnimal(string name,bool &isItThere);

    vector<Animal*>::iterator findIter(vector<Animal*> &toSearch,Animal* toFind,bool &isItThere);

    void growUp();

    void printCommunity();

    void communitySize();

    void ancestorsPath(const vector<string> &travelOrders);



private:
    vector<Animal*>_members;
};


#endif //UNTITLED1_ZOO_H
