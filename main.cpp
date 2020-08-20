#include <iostream>
#include <string>
#include<vector>
#include <sstream>
#include "Zoo.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

typedef enum {REPRODUCE,EUTHANIZE,GROW_UP,PRINT_COMMUNITY,COMMUNITY_SIZE,
    ANCESTORS_PATH, ANCESTORS_PATH_END,QUIT_CODE} CommandsEnum;
const std::string consoleCommands[]= {"animalReproduce", "euthanize", "growUp", "printCommunity",
                                      "communitySize","ancestorsPath", "end","quit"};

int main() {
    string firstMale, firstFemale;
    cin>> firstMale >> firstFemale;

    Zoo* zoo = new Zoo(firstMale, firstFemale);

    std::string input;
    std::cin >> input;

    while ( input != consoleCommands[QUIT_CODE] ){

        if (  input == consoleCommands[REPRODUCE] ){
            string firstParentName,  secondParentName,  name_, gender;
            cin >>firstParentName>>secondParentName>>name_>>gender;
            if (gender == "male"){
                zoo->animalReproduce(firstParentName, secondParentName, name_, MALE);
            }
            else if (gender == "female"){
                zoo->animalReproduce(firstParentName, secondParentName, name_, FEMALE);
            }
        }
        else if (input == consoleCommands[EUTHANIZE] ){
            string name_;
            cin >>name_;
            zoo->euthanize(name_);
        }
        else if(input == consoleCommands[GROW_UP]){
            zoo->growUp();
        }
        else if(input == consoleCommands[PRINT_COMMUNITY]){
            zoo->printCommunity();

        }
        else if(input == consoleCommands[COMMUNITY_SIZE]){
            zoo->communitySize();
        }
        else if(input == consoleCommands[ANCESTORS_PATH]){
            vector<string> pathOrders;
            string name;
            cin >> name;
            while (name != consoleCommands[ANCESTORS_PATH_END]) {
                pathOrders.push_back(name);
                cin >> name;
            }
            zoo->ancestorsPath(pathOrders);
        }
        std::cin >> input;
    }

    delete zoo;
    return 0;
}