#pragma once

#include <iostream>
#include <vector>
class ATarget;
#include "ASpell.hpp"

class ATarget
{
    private:
        std::string type;
    public:
        ATarget();
        ATarget(const ATarget &);
        ATarget(const std::string &_type);
        virtual ~ATarget();
        ATarget  &operator=(const ATarget &);

        const std::string &getType() const {return (this->type);};

        virtual ATarget  *clone() const = 0;

        void    getHitBySpell(ASpell const &) const;
};