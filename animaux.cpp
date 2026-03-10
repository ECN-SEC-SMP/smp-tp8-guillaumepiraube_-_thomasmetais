#include "animaux.h"

const int MATRICE_LION[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
const int MATRICE_OURS[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

// Lion
Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY)
{
  this->nom = "Lion";
  setAttaque();
}
Lion::Lion(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
  this->nom = "Lion";
  setAttaque();
}

void Lion::setAttaque()
{
  this->typeAttaque = Attaque(rand() % 2 + 1); // 1 (feuille) ou 2 (ciseaux)
}

void Lion::deplace(int maxX, int maxY)
{
  int dir = rand() % 4;
  this->x += MATRICE_LION[dir][0];
  this->y += MATRICE_LION[dir][1];

  if (this->x < 0)
    this->x = maxX;
  else if (this->x > maxX)
    this->x = 0;

  if (this->y < 0)
    this->y = maxY;
  else if (this->y > maxY)
    this->y = 0;
}

// Ours
Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY)
{
  this->nom = "Ours";
  setAttaque();
}
Ours::Ours(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
  this->nom = "Ours";
  setAttaque();
}

void Ours::setAttaque()
{
  this->typeAttaque = Attaque(1); // L'ours choisit toujours la feuille
}

void Ours::deplace(int maxX, int maxY)
{
  int dir = rand() % 8;
  this->x += MATRICE_OURS[dir][0];
  this->y += MATRICE_OURS[dir][1];

  if (this->x < 0)
    this->x = maxX - (abs(this->x) - 1);
  else if (this->x > maxX)
    this->x = 0 + (abs(this->x) - 1);

  if (this->y < 0)
    this->y = maxY - (abs(this->x) - 1);
  else if (this->y > maxY)
    this->y = 0 + (abs(this->x) - 1);
}

// Pierre
Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY)
{
  this->nom = "Pierre";
  setAttaque();
}
Pierre::Pierre(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
  this->nom = "Pierre";
  setAttaque();
}

void Pierre::setAttaque()
{
  this->typeAttaque = Attaque(0); // La pierre choisit toujours la pierre
}

void Pierre::deplace(int maxX, int maxY)
{
  // La pierre ne se déplace pas
}

// Loup
Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY)
{
  this->nom = "Loup";
  setAttaque();
}
Loup::Loup(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
  this->nom = "Loup";
  setAttaque();
}

void Loup::setAttaque()
{
  this->typeAttaque = Attaque(rand() % 3); // Choix aléatoire entre pierre, feuille et ciseaux
}

void Loup::deplace(int maxX, int maxY)
{
  this->x += (rand() % (maxX + 1)); // Le loup peut se déplacer de 0 à maxX en x
  this->y += (rand() % (maxY + 1)); // Le loup peut se déplacer de 0 à maxY en y
}