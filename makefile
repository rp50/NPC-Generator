NPC_Generator: main.o npc.o json.hpp
	g++ main.o npc.o json.hpp -o NPC_Generator

main.o: main.cpp
	g++ -c main.cpp

npc.o: npc.cpp
	g++ -c npc.cpp
	
clean: 
	rm *.o NPC_Generator

target: dependencies
	action