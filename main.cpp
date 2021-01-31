#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "npc.h"
#include "json.hpp"

using json = nlohmann::json;

void saveNPC(json &npcJson, std::map<std::string, NPC> &npcMap, NPC currentNPC){
    npcMap.emplace(currentNPC.getName(), currentNPC);
    npcJson[currentNPC.getName()].emplace("Name", currentNPC.getName());
    npcJson[currentNPC.getName()].emplace("Race", currentNPC.getRace());
    for(auto stat : currentNPC.getStats()){
        npcJson[currentNPC.getName()]["Stats"].emplace(stat.first, stat.second);
    }
}

void writeNPCstoFile(json npcJson){
    std::ofstream npcOutputFile("./resources/npcs.json",  std::ios::out | std::ios::trunc);
    npcOutputFile << npcJson;
}

void readNPCstoMap(json npcJson, std::map<std::string, NPC> &npcMap){
    if(!npcJson.empty()){
        for(json readNPC : npcJson){
            NPC currentNPC(readNPC["Name"], readNPC.at("Race"), readNPC.at("Stats").at("str"), readNPC.at("Stats").at("dex"), readNPC.at("Stats").at("con"), readNPC.at("Stats").at("int"), readNPC.at("Stats").at("wis"), readNPC.at("Stats").at("cha"));
            npcMap.emplace(readNPC.at("Name"), currentNPC);
        }
    }
}

int main(){
    std::string cmd;
    std::ifstream npcInputFile("./resources/npcs.json");
    if(!npcInputFile.is_open()){
        std::cerr << "npcs.json is missing, check that it is in the resources folder." << std::endl;
        exit(-1);
    }
    json npcJson;
    std::map<std::string, NPC> npcMap;
    npcInputFile >> npcJson;
    npcInputFile.close();
    readNPCstoMap(npcJson, npcMap);
    while(std::getline(std::cin, cmd)){
        try{
            if(cmd == "exit"){ // Exit command, exits the program
                writeNPCstoFile(npcJson);
                exit(0);
            }
            else if(cmd == "new") { // New command, generates a new NPC, and gives the option to add it to the json file
                NPC currentNPC;
                currentNPC.print();
                std::cout << "Save NPC? (y/n)" << std::endl;
                bool askAgain = false;
                do{
                    std::getline(std::cin, cmd);
                        if(cmd == "y"){
                            saveNPC(npcJson, npcMap, currentNPC);
                            //writeNPCstoFile(npcFile, npcJson);
                        }
                        else if(cmd != "n"){
                            std::cout << "Input not recognized, answer \"y\" for yes, or \"n\" for no." << std::endl;
                            continue;
                        }
                    } while(false);
            }
            else if(cmd.find("get") == 0){ // Get command, retrieves an NPC by their name
                if(cmd.length() > 4){
                    std::string name = cmd.substr(4, cmd.length());
                    if(npcMap.find(name) != npcMap.end()){
                        npcMap.at(name).print();
                    }
                    else{
                        std::cout << "NPC \"" << name << "\" not found." << std::endl;
                    }
                }
                else{
                    std::cout << "Please give a name for the command to get." << std::endl;
                }
            }
            else{
                std::cout << "Unrecognized command \"" << cmd << "\", type help to see a list of commands." << std::endl;
            }
        } catch(int i){
            switch (i)
            {
            case 0: // Thrown by the NPC constructor, signals that names.json is missing.
                std::cerr << "names.json is missing, check that it is in the resources folder." << std::endl;
                exit(-1);
                break;
            default:
                break;
            }
        }
    }
    return 0;
}