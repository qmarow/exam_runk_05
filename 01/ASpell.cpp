#include "ASpell.hpp"

ASpell::ASpell()
{}

ASpell::ASpell(const ASpell &other)
{
    *this = other;
}

ASpell::ASpell(const std::string &_name, const std::string &_effects)
{
    this->name = _name;
    this->effects = _effects;
}

ASpell::~ASpell()
{}

ASpell  &ASpell::operator=(const ASpell &other)
{
    this->name = other.getName();
    this->effects = other.getEffects();
    return (*this);
}

void    ASpell::launch(ATarget const &other) const
{
    other.getHitBySpell(*this);
}
