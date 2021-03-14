#include "Warlock.hpp"

Warlock::Warlock()
{}

Warlock::Warlock(const Warlock &other)
{
    *this = other;
}

Warlock &Warlock::operator=(const Warlock &other)
{
    this->name = other.getName();
    this->title = other.getTitle();
    return (*this);
}

Warlock::Warlock(const std::string &_name, const std::string &_title)
{
    this->name = _name;
    this->title = _title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
}

void    Warlock::setTitle(const std::string &_title)
{
    this->title = _title;
}

void    Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}