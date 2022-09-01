#pragma once 

#include <iostream>

class ASpell;

class ATarget {

    private:
        std::string type;

    public:
        ATarget()
        {
        }
        ATarget(const ATarget& other){ *this = other; };
        ATarget& operator=(const ATarget& other){
            if (this == &other)
                return *this;
            return *this;
        }
        ~ATarget(){}

        ATarget(std::string type) : type(type){};

        const std::string& getType()const{
            return this->type;
        }

        virtual ATarget* clone()const = 0;
        // virtual ATarget* create(std::string spellName) = 0;

        void   getHitBySpell(const ASpell& spell)const;
        // Do not define this in a header - compiler throws include error
};

