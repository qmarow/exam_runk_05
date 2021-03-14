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
    this->book = new SpellBook();
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
    
    delete (this->book);
}

void    Warlock::setTitle(const std::string &_title)
{
    this->title = _title;
}

void    Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void    Warlock::learnSpell(ASpell *other)
{
    if (other == NULL)
        return ;
    this->book->learnSpell(other);
}

void    Warlock::forgetSpell(const std::string nameSp)
{
    this->book->forgetSpell(nameSp);
}

void    Warlock::launchSpell(const std::string nameSp, ATarget const &other)
{
    ASpell  *a = this->book->createSpell(nameSp);
    
    if (a != NULL)
        a->launch(other);
}
