#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

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
        typedef std::pair<std::string, ASpell *> spellMap;
        typedef std::map<std::string, ASpell*>::iterator spellsIter;

        std::map<std::string, ASpell *> spells;
        
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
            spells.insert(spellMap(spell->getName(), spell->clone()));
    }

    void    forgetSpell(string spellName){
        spellsIter it = spells.find(spellName);
        if (it == spells.end())
            return ;
        spells.erase(spellName);
    }

    void    launchSpell(std::string spellName, const ATarget& target){
        ASpell* spell = spells[spellName];
        if (spell)
            spell->launch(target);
    }

    

};
#endif
