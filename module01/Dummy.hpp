#include "ATarget.hpp"

#pragma once 

class Dummy : public ATarget {
public:
    Dummy() : ATarget("Target Practice Dummy"){};

    Dummy(const Dummy& other){ *this = other; };
    Dummy& operator=(const Dummy& other){
        if (this == &other)
            return *this;
        return *this;
    }
    ~Dummy(){}

    Dummy*  clone()const{
        return  new Dummy;
    }

    

    
};