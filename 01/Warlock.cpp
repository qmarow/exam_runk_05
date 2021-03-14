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
    std::vector<ASpell *>::iterator i_begin = this->book.begin();
    std::vector<ASpell *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        delete (*i_begin);
        ++i_begin;
    }
    this->book.clear();
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
    std::vector<ASpell *>::iterator i_begin = this->book.begin();
    std::vector<ASpell *>::iterator i_end = this->book.end();

    if (other == NULL)
        return ;
    while (i_begin != i_end)
    {
        if ((*i_begin)->getName() == other->getName())
        {
            return ;
        }
        ++i_begin;
    }
    this->book.push_back(other->clone());
}

void    Warlock::forgetSpell(const std::string nameSp)
{
    std::vector<ASpell *>::iterator i_begin = this->book.begin();
    std::vector<ASpell *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        if ((*i_begin)->getName() == nameSp)
        {
            delete (*i_begin);
            this->book.erase(i_begin);
            return ;
        }
        ++i_begin;
    }
}

void    Warlock::launchSpell(const std::string nameSp, ATarget const &other)
{
    std::vector<ASpell *>::iterator i_begin = this->book.begin();
    std::vector<ASpell *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        if ((*i_begin)->getName() == nameSp)
        {
           (*i_begin)->launch(other);
            return ;
        }
        ++i_begin;
    }
}
