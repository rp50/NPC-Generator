#include "npc.h"
#include <iostream>

const std::string NPC_RACES[] = {"Human", "Elf", "Dwarf", "Gnome", "Dragonborn", "Halfling", "Half-Elf", "Half-Orc", "Tiefling"};
const int NPC_RACE_COUNT = 9;

NPC::NPC(){
    // random name
    // random race (enum???)
    // random stats max of plus 2 to any given stat
}

void NPC::print(){
    std::cout << m_name << ", " << m_race << std::endl;
    std::cout << "STR: " << m_stats["str"] << ", DEX: " << m_stats["dex"] <<", CON: " << m_stats["con"] << ", INT: " << m_stats["int"] << ", WIS: " << m_stats["wis"] << ", CHA: " << m_stats["cha"]  << std::endl;
}

std::string NPC::getName(){
    return m_name;
}