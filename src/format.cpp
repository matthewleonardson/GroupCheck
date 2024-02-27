#include "format.h"

void printHelp() {
    std::cout << "Usage: groupCheck [options] filename" << std::endl;
    std::cout << "Options:" << std::endl;

    std::cout << " -group" << std::endl;
    std::cout << "      prints whether the given table is a group" << std::endl;

    std::cout << " -abelian, -commutative" << std::endl;
    std::cout << "      prints whether the given table is commutative" << std::endl;

    std::cout << " -inverses" << std::endl;
    std::cout << "      prints whether the given table has inverses" << std::endl;

    std::cout << " -identity" << std::endl;
    std::cout << "      prints whether the given table has an identity element" << std::endl;

    std::cout << " -associative" << std::endl;
    std::cout << "      prints whether the given table is associative" << std::endl;

    std::cout << std::endl << "When no options are passed, -group is the default argument." << std::endl;

}

void printUsage() {
    std::cout << "Usage: groupCheck [options] filename" << std::endl;
    std::cout << "Run groupCheck --help to see all options" << std::endl;
}

void printUnknownArgument(char* arg) {

    std::cout << "Unrecognized argument: " << arg << std::endl;
    std::cout << "Run with --help to see valid options" << std::endl;

}

void printCommutative(CayleyTable* magma) {

    if(magma->isCommutative()) {
        std::cout << "The table is commutative." << std::endl;
    } else {
        std::cout << "The table is not commutative." << std::endl;
    }

}

void printInverses(CayleyTable* magma) {
    
    if(magma->hasInverses()) {
        std::cout << "The table has inverses for all elements." << std::endl;
    } else {
        std::cout << "The table does not have inverses for all elements." << std::endl;
    }

}

void printIdentity(CayleyTable* magma) {

    if(magma->hasIdentity()) {
        std::cout << "The table has an identity element." << std::endl;
    } else {
        std::cout << "The table does not have an identity element." << std::endl;
    }

}

void printAssociative(CayleyTable* magma) {

    if(magma->isAssociative()) {
        std::cout << "The table is associative." << std::endl;
    } else {
        std::cout << "The table is not associative." << std::endl;
    }

}

void printGroup(CayleyTable* magma) {

     if(magma->isGroup()) {
        std::cout << "The table defines a group." << std::endl;
    } else {
        std::cout << "The table does not define a group." << std::endl;
    }

}