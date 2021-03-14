#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::SpellBook(const SpellBook &other)
{
    *this = other;
}

SpellBook &SpellBook::operator=(const SpellBook &other)
{
    this->book = other.book;
    return (*this);
}

SpellBook::~SpellBook()
{
    std::vector<ASpell *>::iterator i_begin = this->book.begin();
    std::vector<ASpell *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        delete (*i_begin);
        ++i_begin;
    }
    this->book.clear();
}

void    SpellBook::learnSpell(ASpell *other)
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

void    SpellBook::forgetSpell(const std::string &nameSp)
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

ASpell  *SpellBook::createSpell(const std::string &nameSp)
{
    std::vector<ASpell *>::iterator i_begin = this->book.begin();
    std::vector<ASpell *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        if ((*i_begin)->getName() == nameSp)
        {
           return (*i_begin)->clone();
        }
        ++i_begin;
    }
    return (NULL);
}
