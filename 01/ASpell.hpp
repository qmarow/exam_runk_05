#pragma once

#include <iostream>
#include <vector>
class ASpell;
#include "ATarget.hpp"

class ASpell
{
    private:
        std::string name;
        std::string effects;
    public:
        ASpell();
        ASpell(const ASpell &);
        ASpell(const std::string &_name, const std::string &_effects);
        virtual ~ASpell();
        ASpell  &operator=(const ASpell &);

        const std::string &getName() const {return (this->name);};
        const std::string &getEffects() const {return (this->effects);};

        virtual ASpell  *clone() const = 0;
        void    launch(ATarget const &) const;
};