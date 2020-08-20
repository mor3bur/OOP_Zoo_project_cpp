//
// Created by menib on 5/22/2019.
//

#include "Animal.h"




/**
 * Constuctor, Default constructor for Animal Objects.
 * @param motherPointer : pointer to the animal's mother.
 * @param fatherPointer : pointer to the animal's mother.
 * @param animalName : animal's name.
 * @param animalGender : UNKNOWN or MALE or FEMALE - 0/1/2
 */
Animal::Animal(Animal *motherPointer, Animal *fatherPointer, const string &animalName,
               Gender animalGender)
{
    this->_mother = motherPointer;
    this->_father = fatherPointer;
    this->_name = animalName;
    this->_gender = animalGender;
    this->_children = vector<Animal*>();
    this->_isAdult = bool(false);
}
/**
 * destructor for animals.
 */


/**
 * prints the animal's members details.
 */
void Animal::printAnimal()
{
    cout<<toPrint[NAME] + this->_name;
    cout<<toPrint[GENDER];
    cout<< this->_gender;
    cout<<toPrint[ADULT];
    cout<< (int) this->_isAdult;
    cout<<toPrint[MOTHER];
    if (_mother)
    {
        cout<<this->_mother->_name;
    }
    cout<<toPrint[FATHER];
    if (_father)
    {
        cout<<this->_father->_name;
    }
    cout<<toPrint[CHILDREN];
    cout<<this->_children.size();
    cout<<endl;
}
/**
 * changes the _isAdult member of the animal to true.
 */
void Animal::grow()
{
    this->_isAdult = true;
}

/**
 * gets the animal's partner, checks if it possible to reproduce with (both are adult
 * and one is male, the other is female) and if possible, builds there descendant.
 * @param partner : partner to reproduce.
 * @param descendantName : name for the descendant.
 * @param descendantGender : Gender for the descendant.
 * @return pointer to animal in heap, or null if failed to reproduce.
 */
Animal* Animal::reproduce(Animal *partner, const string &descendantName,Gender descendantGender)
{

    bool bothAdults=false;
    bool genders= false;
    Animal* child= NULL;
    Animal* mother;
    Animal* father;
    if (this->_isAdult && partner->_isAdult)
    {
        bothAdults = true;
    }

    if(bothAdults)
    {
        if (this->_gender == MALE && partner->_gender == FEMALE)
        {
            father = this;
            mother = partner;
            genders = true;
        } else if (this->_gender == FEMALE && partner->_gender == MALE)
        {
            father = partner;
            mother = this;
            genders = true;
        }


        if (genders)
        {
            child = new Animal(mother, father, descendantName, descendantGender);
            mother->_children.push_back(child);
            father->_children.push_back(child);
        }
    }
    return child;
}