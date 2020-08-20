//
// Created by menib on 5/22/2019.
//

#include "Zoo.h"
/**
 * Zoo constructor
 * Adds 2 animals to the zoo
 * @param maleName
 * @param femaleName
 */
Zoo::Zoo(string maleName, string femaleName)
{
    Animal* first= new Animal;
    Animal* second=new Animal;
    first->_name=maleName;
    first->_gender=MALE;
    second->_name=femaleName;
    second->_gender=FEMALE;
    _members.push_back(first);
    _members.push_back(second);
}

/**
 * Finds animal in the Zoo
 * @param name
 * @return Animal pointer
 */
Animal* Zoo::findAnimal(string name,bool &isItThere)
{
    isItThere= false;
    for(vector<Animal*>::iterator iter=_members.begin();iter!=_members.end();iter++)
    {
        if((*iter)->_name==name)
        {
            isItThere= true;
            return (*iter);
        }
    }
}

/**
 *
 * @param toFind
 * @return pointer to Animal pointer
 */
vector<Animal*>::iterator Zoo::findIter(vector<Animal*> &toSearch,Animal *toFind, bool &isItThere)
{
    isItThere= false;
    for(vector<Animal*>::iterator iter=toSearch.begin();iter!=toSearch.end();iter++)
    {
        if(*iter==toFind)
        {
            isItThere= true;
            return iter;
        }
    }
}
/**
 * checks if possible to give birth and returns a new animal which is the descendant of two animals.
 * the name and gender will be the given params.
 * @param firstParentName :first animal's name.
 * @param secondParentName : second animal's name.
 * @param name : name of the descendant.
 * @param gender : gender of the descendant.
 * @return true if reproduce process worked, else false.
 */
bool Zoo::animalReproduce(const string &firstParentName, const string &secondParentName,
        const string &name, Gender gender)
{
    bool isItThere;
    Animal* parent =findAnimal(firstParentName,isItThere);
    if (!isItThere)
    {
        return false;
    }
    Animal* descendant=parent->reproduce(findAnimal(secondParentName,isItThere)
            ,name,gender);
    if (descendant!=NULL)
    {
        _members.push_back(descendant);
    }
    return descendant!=NULL;
}
/**
 * kills an animal and delete all pointer to it in zoo, the animal's parents and children.
 * @param name : name of animal that died.
 * @return true if died, false if there was no animal was with this name.
 */
bool Zoo::euthanize(const string &name)
{
    bool isItThere;
    Animal* toKill = findAnimal(name,isItThere);
    if (!isItThere)
    {
        return false;
    }
    vector<Animal*> children = toKill->_children;
    for (vector<Animal *>::iterator iter = children.begin();
         iter != children.end(); iter++)
    {
        if (toKill->_gender == MALE)
        {
            (*iter)->_father=NULL;
            if ((*iter)->_mother==NULL && !(*iter)->_isAdult)
                {
                    delete(*iter);
                    _members.erase(findIter(_members,*iter,isItThere));
                }
        } else if (toKill->_gender == FEMALE)
        {
            (*iter)->_mother=NULL;
            if ((*iter)->_father==NULL && !(*iter)->_isAdult)
            {
                delete(*iter);
                _members.erase(findIter(_members,*iter,isItThere));
            }
        }
    }
    if(toKill->_mother!=NULL)
    {
        toKill->_mother->_children.erase(findIter(toKill->_mother->_children, toKill, isItThere));
    }
    if(toKill->_father!=NULL)
    {
        toKill->_father->_children.erase(findIter(toKill->_father->_children, toKill, isItThere));
    }
    delete(toKill);
    _members.erase(findIter(_members,toKill,isItThere));
    return true;
}
/**
 * makes all animals in zoo adults.
 */
void Zoo::growUp()
{
    for(vector<Animal*>::iterator iter=_members.begin();iter!=_members.end();iter++)
    {


        (*iter)->grow();

    }
}
/**
 * prints the size of zoo.
 */
void Zoo::communitySize()
{
    size_t size=_members.size();
    cout<<"number of animals in the community is: "<<size<<endl;
}
/**
 * prints the names of all animals in the zoo.
 */
void Zoo::printCommunity()
{
        for(vector<Animal*>::iterator iter=_members.begin();iter!=_members.end();iter++)
    {
        cout<<(*iter)->_name<<endl;
    }
}
/**
 * gets a vector of the of the input line, prints the details of the animal and
 * than prints the details of the fathers/mothers of it by  the travel order of the family tree.
 * if the animal was not found in the zoo prints that.
 * if a father/mother is dead prints failed.
 * @param travelOrders: vector of the of the input line
 */
void Zoo::ancestorsPath(const vector<string> &travelOrders)
{
    bool isItThere;
    Animal* animal = findAnimal(travelOrders[0],isItThere);
    if(isItThere)
    {
        animal->printAnimal();
        for (vector<string>::const_iterator iter = travelOrders.begin()+1;
             iter != travelOrders.end(); iter++)
        {

            if (*iter == option[END])
            {
                break;
            }
            else if (*iter == option[M] && animal->_mother!=NULL)
            {
                animal = animal->_mother;
            }
            else if (*iter == option[F] && animal->_father!=NULL)
            {
                animal = animal->_father;
            }
            else
            {
                cout << "failed"<<endl;
                continue;
            }
            animal->printAnimal();
        }
    }
    else
        {
            cout<<"The animal was not found"<<endl;
        }
}
