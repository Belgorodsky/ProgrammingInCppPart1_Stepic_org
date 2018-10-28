#pragma once
#include <string> // std::string

struct Character
{
    std::string const & name() const;
    unsigned health() const;
};

struct LongRange : Character
{
    unsigned range() const;
};

struct SwordsMan : Character
{
    unsigned strength() const;
};

struct Wizard : LongRange
{
    unsigned mana() const;
};

struct Archer : LongRange
{
    unsigned accuracy() const;
};
