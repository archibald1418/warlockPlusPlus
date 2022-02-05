#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Warlock 
{
    private:
        string name;
        string title;
        Warlock(const Warlock& other){ *this = other; };
        Warlock& operator=(const Warlock& other){
            if (this == &other)
                return *this;
            return *this;
        }        
        
public:

    Warlock()
    {
    }
    ~Warlock(){
        cout << name << ": My job here is done!" << endl;
    }

    Warlock(string name, string title) : name(name){
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

};