#include "ASpell.hpp"
#pragma once

class Fwoosh : public ASpell {
public:
    Fwoosh() : ASpell("Fwoosh", "fwooshed")
    // name("Fwoosh"), effects("fwooshed")
    {};

    Fwoosh(const Fwoosh& other){ *this = other; };
    Fwoosh& operator=(const Fwoosh& other){
        if (this == &other)
            return *this;
        return *this;
    }
    ~Fwoosh(){}

    Fwoosh* clone()const{
        return new Fwoosh;
    }
};
