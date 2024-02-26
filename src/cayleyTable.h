#pragma once

#include <vector>
#include <string>
#include <unordered_map>

class CayleyTable {

public:
    CayleyTable(std::string filename);
    std::string operation(std::string elem1, std::string elem2) const;
    bool isCommutative() const;
    bool hasInverses() const;
    bool hasIdentity() const;
    bool isAssociative() const;
    bool isGroup() const;
    
private: 
    // note that internally, this table is
    std::vector<std::vector<std::string>> table_;
    std::unordered_map<std::string, unsigned> elem_to_index_;

    // internal variables that serve as a pseudo-caching 
    // to avoid repeated calls from the user and other methods
    mutable int* identity_idx_ = nullptr;
    mutable bool* inverses_ = nullptr;
    mutable bool* commutative_ = nullptr;
    mutable bool* associative_ = nullptr;
};