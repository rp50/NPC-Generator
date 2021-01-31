#include "npc.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include "json.hpp"


using json = nlohmann::json;

NPC::NPC(){
    srand(time(NULL));
    std::ifstream namesFile("./resources/names.json");
    if(!namesFile.is_open()){
        throw 0;
    }
    json names;
    namesFile >> names;
    namesFile.close();
    int rand_num = rand() % 100;
    if(rand_num < 30){
        m_race = "Human";
    }
    else if(rand_num < 45){
        m_race = "Elf";
    }
    else if(rand_num < 60){
        m_race = "Dwarf";
    }
    else if(rand_num < 67){
        m_race = "Gnome";
    }
    else if(rand_num < 72){
        m_race = "Dragonborn";
    }
    else if(rand_num < 79){
        m_race = "Halfling";
    }
    else if(rand_num < 85){
        m_race = "Half-Elf";
    }
    else if(rand_num < 91){
        m_race = "Half-Orc";
    }
    else if(rand_num < 100){
        m_race = "Tiefling";
    }
    if(m_race == "Half-Orc" || m_race == "Half-Elf"){
        m_name = names.at("Human_first").at(rand() % names.at("Human_first").size());
    }
    else{
        m_name = names.at(m_race+"_first").at(rand() % names.at(m_race+"_first").size());
    }
    if((m_race != "Elf" && m_race != "Tiefling") && (rand() % 2) == 0){
        m_name += " ";
        m_name += names.at(m_race+"_last").at(rand() % names.at(m_race+"_last").size());
    }
    m_stats.emplace("str", 6+(rand() % 9));
    m_stats.emplace("dex", 6+(rand() % 9));
    m_stats.emplace("con", 6+(rand() % 9));
    m_stats.emplace("int", 6+(rand() % 9));
    m_stats.emplace("wis", 6+(rand() % 9));
    m_stats.emplace("cha", 6+(rand() % 9));
}

NPC::NPC(std::string name, std::string race, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma){
    m_name = name;
    m_race = race;
    m_stats.emplace("str", strength);
    m_stats.emplace("dex", dexterity);
    m_stats.emplace("con", constitution);
    m_stats.emplace("int", intelligence);
    m_stats.emplace("wis", wisdom);
    m_stats.emplace("cha", charisma);
}

void NPC::print(){
    std::cout << m_name << ", " << m_race << std::endl;
    std::cout << "STR: " << m_stats["str"] << ", DEX: " << m_stats["dex"] <<", CON: " << m_stats["con"] << ", INT: " << m_stats["int"] << ", WIS: " << m_stats["wis"] << ", CHA: " << m_stats["cha"]  << std::endl;
}

std::string NPC::getName(){
    return m_name;
}

std::string NPC::getRace(){
    return m_race;
}

std::map<std::string, int> NPC::getStats(){
    return m_stats;
}