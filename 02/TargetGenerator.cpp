#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::TargetGenerator(const TargetGenerator &other)
{
    *this = other;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &other)
{
    this->book = other.book;
    return (*this);
}

TargetGenerator::~TargetGenerator()
{
    std::vector<ATarget *>::iterator i_begin = this->book.begin();
    std::vector<ATarget *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        delete (*i_begin);
        ++i_begin;
    }
    this->book.clear();
}

void    TargetGenerator::learnTargetType(ATarget *other)
{
    std::vector<ATarget *>::iterator i_begin = this->book.begin();
    std::vector<ATarget *>::iterator i_end = this->book.end();

    if (other == NULL)
        return ;
    while (i_begin != i_end)
    {
        if ((*i_begin)->getType() == other->getType())
        {
            return ;
        }
        ++i_begin;
    }
    this->book.push_back(other->clone());
}

void    TargetGenerator::forgetTargetType(const std::string &nameSp)
{
    std::vector<ATarget *>::iterator i_begin = this->book.begin();
    std::vector<ATarget *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        if ((*i_begin)->getType() == nameSp)
        {
            delete (*i_begin);
            this->book.erase(i_begin);
            return ;
        }
        ++i_begin;
    }
}

ATarget  *TargetGenerator::createTarget(const std::string &nameSp)
{
    std::vector<ATarget *>::iterator i_begin = this->book.begin();
    std::vector<ATarget *>::iterator i_end = this->book.end();

    while (i_begin != i_end)
    {
        if ((*i_begin)->getType() == nameSp)
        {
           return (*i_begin)->clone();
        }
        ++i_begin;
    }
    return (NULL);
}
