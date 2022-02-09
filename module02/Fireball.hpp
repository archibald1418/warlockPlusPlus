#include "ASpell.hpp"
#pragma once

class Fireball : public ASpell {
public:
    Fireball() : ASpell("Fireball", "burnt to a crisp")
    // name("Fireball"), effects("Fireballed")
    {};

    Fireball(const Fireball& other){ *this = other; };
    Fireball& operator=(const Fireball& other){
        if (this == &other)
            return *this;
        return *this;
    }
    ~Fireball(){}

    Fireball* clone()const{
        return new Fireball;
    }
};
