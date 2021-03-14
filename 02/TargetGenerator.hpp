#pragma once

#include <iostream>
#include <vector>
class TargetGenerator;
#include "ATarget.hpp"

class TargetGenerator
{
    private:
        TargetGenerator(const TargetGenerator &);
        TargetGenerator &operator=(const TargetGenerator &);
        std::vector<ATarget *> book;
    public:
        TargetGenerator();
        ~TargetGenerator();

        void    learnTargetType(ATarget *);
        void    forgetTargetType(const std::string &nameSp);
        ATarget  *createTarget(const std::string &nameSp);
};
