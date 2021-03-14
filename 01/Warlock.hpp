#pragma once

#include <iostream>
#include <vector>
class Warlock;
#include "ASpell.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;
        Warlock();
        Warlock(const Warlock &);
        Warlock &operator=(const Warlock &);
        std::vector<ASpell *> book;
    public:
        Warlock(const std::string &_name, const std::string &_title);
        ~Warlock();

        const std::string &getName() const {return (this->name);};
        const std::string &getTitle() const {return (this->title);};

        void    setTitle(const std::string &_title);

        void    introduce() const;
        void    learnSpell(ASpell *);
        void    forgetSpell(const std::string nameSp);
        void    launchSpell(const std::string nameSp, ATarget const &);
        
};