#include "cayleyTable.h"
#include <exception>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

CayleyTable::CayleyTable(std::string filename) {

    std::ifstream file;
    file.open(filename);

    if(!file.good()) {
        throw std::runtime_error("CayleyTable constructor could not open file");
    }
    
    // this code just reads a csv verbatim
    std::string line, element;
    std::getline(file, line);
    std::stringstream ss(line);
    unsigned index = 0;

    // TODO: fix bug when "first" value is blank
    while(std::getline(ss, element, ',')) {
        table_.push_back(std::vector<std::string> {element});
        elem_to_index_[element] = index;
        index++;
    }

    // technically its redundant to do 2 while loops here, but whatever
    while(std::getline(file, line)) {        
        ss = std::stringstream(line);
        std::string value;
        int index = 0;

        while(std::getline(ss, value, ',')) {
            table_.at(index).push_back(value);
            index++;
        }

    }

    file.close();
    
    // set the topleft to nothing
    table_[0][0] = "";

}

std::string CayleyTable::operation(std::string elem1, std::string elem2) const {
   
    return table_[elem_to_index_.at(elem2)][elem_to_index_.at(elem1)];

}

bool CayleyTable::isCommutative() const {
    
    if(commutative_) {
        return *commutative_;
    }

    for(unsigned i = 1; i < table_.size(); i++) {
        for(unsigned j = 1; j < table_.size(); j++) {
            if(table_[i][j] != table_[j][i]) {
                commutative_ = new bool(false);
                return false;
            }
        }
    }

    commutative_ = new bool(true);
    return true;

}

bool CayleyTable::hasInverses() const {

    if(!hasIdentity()) {
        return false;
    }

    std::string identity = table_[0][*identity_idx_];

    for(unsigned i = 1; i < table_.size(); i++) {
        bool escape_condition = true;
        for(unsigned j = 1; j < table_.size(); j++) {
            if(operation(table_[0][i], table_[0][j]) == identity) {
                escape_condition = false;
                break;
            }
        }
        if(escape_condition) return false;
    }

    return true;

}

bool CayleyTable::hasIdentity() const {

    if(identity_idx_) {
        return true;
    }

    for(unsigned n = 1; n < table_.size(); n++) {

        if(std::equal(table_[0].begin() + 2, table_[0].end(), table_[n].begin() + 2, table_[n].end())) {
            identity_idx_ = new int(n);
            return true;
        }


    }

    return false;

}

bool CayleyTable::isAssociative() const {

    if(associative_) {
        return *associative_;
    }

    for(unsigned a = 1; a < table_.size(); a++) {

        std::string elemA = table_[0][a];

        for(unsigned x = 1; x < table_.size(); x++) {
            
            if(identity_idx_ && x == *identity_idx_) continue;
            std::string elemX = table_[0][x];

            for(unsigned y = 1; y < table_.size(); y++) {

                if(identity_idx_ && y == *identity_idx_) continue;
                
                std::string elemY = table_[0][y];

                if(operation(elemX, operation(elemA, elemY)) != operation(operation(elemX, elemA), elemY)) {
                    associative_ = new bool(false);
                    return false;
                }

            }

        }

    }

    associative_ = new bool(true);
    return true;

}

bool CayleyTable::isGroup() const {
    return hasIdentity() && isAssociative() && hasInverses();
}