#include "cayleyTable.h"
#include <iostream>

int main(int argc, char** argv) {

    if(argc == 1) {
        std::cout << "usage: .\\groupCheck.exe [filename]" << std::endl;
        return -1;
    }

    CayleyTable magma = CayleyTable(std::string(argv[1]));
    
    if(magma.isGroup()) {
        std::cout << argv[1] << " defines a group." << std::endl; 
    } else {
        std::cout << argv[1] << " doesn't define a group." << std::endl; 
    }

    return 0;
}