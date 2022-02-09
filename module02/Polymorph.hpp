#include "ASpell.hpp"
#pragma once

class Polymorph : public ASpell {
public:
    Polymorph() : ASpell("Polymorph", "turned into a critter")
    // name("Polymorph"), effects("Polymorphed")
    {};

    Polymorph(const Polymorph& other){ *this = other; };
    Polymorph& operator=(const Polymorph& other){
        if (this == &other)
            return *this;
        return *this;
    }
    ~Polymorph(){}

    Polymorph* clone()const{
        return new Polymorph;
    }
};
