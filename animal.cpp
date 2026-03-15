//
// Created by pirau on 09/03/2026.
//
#include "animal.h"
#include <string>

Animal::Animal(int maxX, int maxY) : x(rand() % (maxX)), y(rand() % (maxY)), vivant(true) {}

Animal::Animal(int maxX, int maxY, int a, int b) : x(a), y(b), vivant(true) {}

std::string Animal::getNom() const
{
    return nom;
}

int Animal::getX() const
{
    return x;
}

int Animal::getY() const
{
    return y;
}

bool Animal::getVivant() const
{
    return vivant;
}

Attaque Animal::getAttaque() const
{
    return typeAttaque;
}

void Animal::setVivant(bool v)
{
    vivant = v;
}

bool Animal::attaque(Animal &a)
{
    return this->typeAttaque.resoudreAttaque(a.getAttaque());
}

Animal::~Animal()
{
}