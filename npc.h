#ifndef NPC_H
#define NPC_H

#include <map>
#include <string>

class NPC{
    public:
        NPC();
        void print();
        std::string getName();
    private:
        std::map<std::string, int> m_stats;
        std::string m_name;
        std::string m_race;
};

#endif