#include "attaque.h"

Attaque::Attaque()
{
    this->type = rand() % 3;
}

Attaque::Attaque(int a)
{
    this->type = a;
}

int Attaque::getTypeAttaque() const
{
    return this->type;
}

bool Attaque::resoudreAttaque(const Attaque &a) const
{
    if ((this->type == 0 && a.getTypeAttaque() == 2) || (this->type == 1 && a.getTypeAttaque() == 0) || (this->type == 2 && a.getTypeAttaque() == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Attaque::getNomAttaque() const
{
    if (this->type == 0)
    {
        return "pierre";
    }
    else if (this->type == 1)
    {
        return "feuille";
    }
    else
    {
        return "ciseaux";
    }
}

Attaque::~Attaque()
{
}