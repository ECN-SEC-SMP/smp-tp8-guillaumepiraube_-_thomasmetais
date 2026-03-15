#include "attaque.h"
#include "animaux.h"
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#define maxX 10
#define maxY 10

void afficherPlateau(std::vector<Animal *> &animaux)
{
  int animalsInLife = 0;
  for (int i = 0; i < maxX; i++)
  {
    for (int j = 0; j < maxY; j++)
      std::cout << "|----";
    std::cout << "|" << std::endl;

    for (int j = 0; j < maxY; j++)
    {
      std::string cellContent = "";
      for (Animal *a : animaux)
      {
        if (a != nullptr && a->getVivant() && a->getX() == i && a->getY() == j)
        {
          cellContent += a->getNom().at(0);
          animalsInLife++;
        }
      }
      // for (Animal *a : plateau[i][j])
      // {
      //   if (a != nullptr && a->getVivant())
      //   {
      //     cellContent += a->getNom().at(0);
      //     animalsInLife++;
      //   }
      // }
      cellContent.resize(4, ' ');
      std::cout << "|" << cellContent;
    }
    std::cout << "|" << std::endl;
  }
  for (int j = 0; j < maxY; j++)
    std::cout << "|----";
  std::cout << "|" << std::endl;
  std::cout << "Il y a " << animalsInLife << (animalsInLife <= 1 ? " animal vivant" : " animaux vivants") << std::endl;
}

void jouerTour(std::vector<Animal *> &animaux)
{
  // déplacement de tous les animaux
  for (Animal *a : animaux)
  {
    if (a != nullptr && a->getVivant())
      a->deplace(maxX, maxY);
  }

  // résolution des combats
  for (size_t i = 0; i < animaux.size(); i++)
  {
    for (size_t j = i + 1; j < animaux.size(); j++)
    {
      if (animaux[i] != nullptr && animaux[j] != nullptr && animaux[i]->getVivant() && animaux[j]->getVivant() &&
          animaux[i]->getX() == animaux[j]->getX() && animaux[i]->getY() == animaux[j]->getY())
      {
        if (animaux[i]->attaque(*animaux[j]))
          animaux[j]->setVivant(false);
        else
          animaux[i]->setVivant(false);
      }
    }
  }
}

int main(int argc, char **argv)
{
  srand(time(NULL));
  Attaque *attaque1 = new Attaque();
  Attaque *attaque2 = new Attaque(2);
  std::cout << "Attaque 1: " << attaque1->getNomAttaque() << std::endl;
  std::cout << "Attaque 2: " << attaque2->getNomAttaque() << std::endl;

  int nombreAnimaux;

  std::cout << "Debut du jeu, combien d'animaux voulez-vous ? (max " << (int)(maxX * maxY) << ") ";
  std::cin >> nombreAnimaux;

  // création d'anaimaux aléatoires
  std::vector<Animal *> animaux;
  for (int i = 0; i < 20; i++)
  {
    int typeAnimal = rand() % 4;
    switch (typeAnimal)
    {
    case 0:
      animaux.push_back(new Lion(maxX, maxY));
      break;
    case 1:
      animaux.push_back(new Ours(maxX, maxY));
      break;
    case 2:
      animaux.push_back(new Pierre(maxX, maxY));
      break;
    case 3:
      animaux.push_back(new Loup(maxX, maxY));
      break;
    }
    // std::cout << i << std::endl;
  }

  afficherPlateau(animaux);

  while (true)
  {
    std::cout << "Appuyez sur Entrée pour jouer un tour..." << std::endl;
    std::cin.get();
    jouerTour(animaux);
    afficherPlateau(animaux);
    if (std::count_if(animaux.begin(), animaux.end(), [](Animal *a)
                      { return a != nullptr && a->getVivant(); }) <= 1)
    {
      std::cout << "Le jeu est terminé !" << std::endl;
      break;
    }
  }
  return 0;
}