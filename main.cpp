#include <iostream>
#include <string>
#include <map>
#include "npc.h"



int main(){
    std::string cmd;
    std::map<std::string, NPC> NPC_List;
    while(std::getline(std::cin, cmd)){
        if(cmd == "exit"){
            exit(0);
        }
        else if(cmd == "new") {
            NPC current_NPC;
            current_NPC.print();
            NPC_List.emplace(current_NPC.getName(), current_NPC);
        }
        else{
            std::cout << "Unrecognized command \"" << cmd << "\", type help to see a list of commands." << std::endl;
        }
    }
    return 0;
}