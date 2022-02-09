#include "ATarget.hpp"

#pragma once 

class BrickWall : public ATarget {
public:
    BrickWall() : ATarget("Inconspicuous Red-brick Wall"){};

    BrickWall(const BrickWall& other){ *this = other; };
    BrickWall& operator=(const BrickWall& other){
        if (this == &other)
            return *this;
        return *this;
    }
    ~BrickWall(){}

    BrickWall*  clone()const{
        return  new BrickWall;
    }
    
};