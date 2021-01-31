#ifndef NPC_H
#define NPC_H

#include <map>
#include <string>

class NPC{
    public:
        NPC();
        NPC(std::string name, std::string race, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
        void print();
        std::string getName();
        std::string getRace();
        std::map<std::string, int> getStats();
    private:
        std::map<std::string, int> m_stats;
        std::string m_name;
        std::string m_race;
};

#endif