#include "ATarget.hpp"

ATarget::ATarget()
{}

ATarget::ATarget(const ATarget &other)
{
    *this = other;
}

ATarget::ATarget(const std::string &_type)
{
    this->type = _type;
}

ATarget::~ATarget()
{}

ATarget  &ATarget::operator=(const ATarget &other)
{
    this->type = other.getType();
    return (*this);
}

void    ATarget::getHitBySpell(ASpell const &other) const
{
    std::cout << this->type << " has been " << other.getEffects() << "!" << std::endl;
}
