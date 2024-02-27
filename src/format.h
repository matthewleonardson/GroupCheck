#include "cayleyTable.h"
#include <string>
#include <iostream>

void printHelp();

void printUsage();

void printUnknownArgument(char* arg);

void printCommutative(CayleyTable* magma);

void printInverses(CayleyTable* magma);

void printIdentity(CayleyTable* magma);

void printAssociative(CayleyTable* magma);

void printGroup(CayleyTable* magma);
