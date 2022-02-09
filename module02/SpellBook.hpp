#pragma once

#include <iostream>
#include <map>
using std::string;
// using std::map;


#include "ASpell.hpp"
class ASpell;



typedef std::pair<std::string, ASpell *> spellMap;
typedef std::map<std::string, ASpell*>::iterator spellsIter;

class SpellBook
{

private:
    SpellBook::SpellBook (const SpellBook& other)
    {
        *this = other;
    }
    SpellBook& SpellBook::operator=(const SpellBook& other)
    {
        if (this == &other)
            return (*this);
        return (*this);
    }
public:
    
    std::map<std::string, ASpell *> spells;

    SpellBook::SpellBook(){ }
    SpellBook::~SpellBook(){ }

    void    learnSpell(ASpell* spell){
        if (spell)
            spells.insert(spellMap(spell->getName(), spell->clone()));
    }

    void    forgetSpell(string spellName){
        spellsIter it = spells.find(spellName);
        if (it == spells.end())
            return ;
        spells.erase(spellName);
    }
    
    ASpell* createSpell(string const &);

    

};