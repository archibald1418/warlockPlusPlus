#ifndef WARLOCK_H
# define WARLOCK_H




#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <map>




using std::string;
using std::cout;
using std::endl;

class Warlock
{
    private:
        string name;
        string title;
        Warlock(const Warlock& other){ *this = other; };
        Warlock& operator=(const Warlock& other)
        {
            if (this == &other)
                return *this;
            return *this;
        }        
        // typedef std::pair<std::string, ASpell *> spellMap;
        // typedef std::map<std::string, ASpell*>::iterator spellsIter;
        // std::map<std::string, ASpell *> spells;
        
        SpellBook spellBook;

        
        
public:

    Warlock()
    {
    }
    ~Warlock(){
        cout << name << ": My job here is done!" << endl;
    }

    Warlock(string name, string title) : name(name)
    {
        setTitle(title);
        std::cout << name << ": This looks like another boring day." << std::endl;
    };
    
    void introduce()const{
        std::cout << this->name << ": I am " << this->name + ", " + this->title + "!" << endl;
    }
    
    const string& getTitle(void)const {
        return this->title;
    };

    const string& getName(void)const {
        return this->name;
    };

    void    setTitle(const string& title)
    {
        this->title = title;
    }

    void    learnSpell(ASpell* spell){
        if (spell)
            spellBook.learnSpell(spell->clone());
    }

    void    forgetSpell(string spellName){
        spellsIter it = spellBook.spells.find(spellName);
        if (it == spellBook.spells.end())
            return ;
        spellBook.forgetSpell(spellName);
    }

    void    launchSpell(std::string spellName, const ATarget& target){
        ASpell* spell = spellBook.spells[spellName];
        if (spell)
            spell->launch(target);
    }

    

};
#endif