#pragma once

#include <iostream>
#include <vector>
class SpellBook;
#include "ASpell.hpp"

class SpellBook
{
    private:
        SpellBook(const SpellBook &);
        SpellBook &operator=(const SpellBook &);
        std::vector<ASpell *> book;
    public:
        SpellBook();
        ~SpellBook();

        void    learnSpell(ASpell *);
        void    forgetSpell(const std::string &nameSp);
        ASpell  *createSpell(const std::string &nameSp);
};
