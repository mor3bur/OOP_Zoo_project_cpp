#ifndef TESTS_ANIMAL_H
#define TESTS_ANIMAL_H
#include <iostream>
#include <string>
#include<vector>
#include <sstream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

typedef enum { UNKNOWN = 0, MALE , FEMALE} Gender;
typedef enum {END=0,M,F} Option;
typedef enum {NAME,GENDER,ADULT,MOTHER,FATHER,CHILDREN} OutputEnum;
const string toPrint[]= {"Name: ", ", Gender: ",", Is adult: ", ", Mother name: ",", Father name: ",", Number of children: "};
const string option[]={"end","m","f"};
class Animal
{
public:
    Animal(Animal *motherPointer = NULL, Animal *fatherPointer = NULL,const string
    &animalName= "",Gender animalGender = UNKNOWN);
    //~Animal(){}
    void printAnimal();
    void grow();
    Animal* reproduce(Animal* partner,const string &descendantName, Gender descendantGender);
friend class Zoo;
private:
    Animal * _father;
    Animal *_mother;
    vector< Animal *> _children;
    Gender _gender;
    string _name;
    bool _isAdult;
};


#endif //TESTS_ANIMAL_H