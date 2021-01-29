#include <iostream>
#include <string>

int cmd_reader(std::string cmd){
    int cmd_code = -1;
    if(cmd == "new"){
        cmd_code = 1;
    }
    else if(cmd.find("new") == 0){
        cmd_code = 2;
    }
    else if(cmd == "exit"){
        cmd_code = 0;
    }
    return cmd_code;
}

int main(){
    std::string cmd;
    while(std::getline(std::cin, cmd)){
        int cmd_code = cmd_reader(cmd);
        switch (cmd_code){
            case 0:
                exit(0);
                break;
            case 1:
            // request random new 
                std::cout << "rand new" << std::endl;
                break;
            case 2:
            // request new with either specified race / name
                std::cout << "spec new" << std:: endl;
                break;
            default:
                break;
        }
    }
    return 0;
}