#pragma once

#include "ATarget.hpp"
#include <iostream>

class ASpell {

    protected:
        std::string name;
        std::string effects;

    public:
        ASpell()
        {
        }
        ASpell(const ASpell& other){ *this = other; };
        ASpell& operator=(const ASpell& other){
            if (this == &other)
                return *this;
            return *this;
        }
        ~ASpell(){};
        
        ASpell(std::string name, std::string effects) : name(name), effects(effects){};

        const std::string&  getName()const {
            return this->name;
        }
        
        void setName (std::string& name)
        {
            this->name = name;
        }

        const std::string& getEffects()const{
            return this->effects;
        }  

        void    setEffects(std::string& effects)
        {
            this->effects = effects;
        }

        virtual ASpell* clone()const = 0;

        void    launch(const ATarget& target)
        {
            target.getHitBySpell(*this);
        }
};
