#include "cayleyTable.h"
#include "format.h"
#include <iostream>
#include <cstring>

int main(int argc, char** argv) {

    if(argc == 1) {
        printUsage();
        return -1;
    }

    bool checkCommutative = false;
    bool checkInverses = false;
    bool checkIdentity = false;
    bool checkAssociative = false;
    bool checkGroup = false;

    // parse arguments
    for(int n = 1; n < argc-1; n++) {
        
        if(strcmp(argv[n], "--help") == 0) {
            printHelp();
            return 0;
        }

        if(strcmp(argv[n], "-abelian") == 0 || strcmp(argv[n], "-commutative") == 0) {
            checkCommutative = true;
            continue;
        }

        if(strcmp(argv[n], "-inverses") == 0) {
            checkInverses = true;
            continue;
        }

        if(strcmp(argv[n], "-identity") == 0) {
            checkIdentity = true;
            continue;
        }

        if(strcmp(argv[n], "-associative") == 0) {
            checkAssociative = true;
            continue;
        }

        if(strcmp(argv[n], "-group") == 0) {
            checkGroup = true;
            continue;
        }

        printUnknownArgument(argv[n]);
        return -1;

    }
    
    // default behavior
    if(argc == 2) {
        checkGroup = true;
    }

    std::string filename = std::string(argv[argc-1]);

    CayleyTable* magma = new CayleyTable(filename);
    
    // prints

    if(checkCommutative) printCommutative(magma);

    if(checkIdentity) printIdentity(magma);

    if(checkInverses) printInverses(magma);

    if(checkAssociative) printAssociative(magma);

    if(checkGroup) printGroup(magma);

    return 0;
}