#pragma once
//
// Created by pirau on 09/03/2026.
//
#include <string>
#include "attaque.h"

class Animal
{
protected:
    std::string nom;
    int x;
    int y;
    bool vivant;
    Attaque typeAttaque;

public:
    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int a, int b);
    std::string getNom() const;
    int getX() const;
    int getY() const;
    bool getVivant() const;
    Attaque getAttaque() const;
    void setVivant(bool v);
    bool attaque(Animal &a);
    virtual void setAttaque() = 0;                // virtuel pure
    virtual void deplace(int maxX, int maxY) = 0; // virtuel pure
    virtual ~Animal();
};
