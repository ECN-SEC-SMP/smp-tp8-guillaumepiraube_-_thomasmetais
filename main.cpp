#include "attaque.h"
#include "animaux.h"
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#define maxX 10
#define maxY 10

void afficherPlateau(std::array<std::array<std::vector<Animal *>, maxY>, maxX> &plateau)
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
      for (Animal *a : plateau[i][j])
      {
        if (a != nullptr && a->getVivant())
        {
          cellContent += a->getNom().at(0);
          animalsInLife++;
        }
      }
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

int main(int argc, char **argv)
{
  srand(time(NULL));
  Attaque *attaque1 = new Attaque();
  Attaque *attaque2 = new Attaque(2);
  std::cout << "Attaque 1: " << attaque1->getNomAttaque() << std::endl;
  std::cout << "Attaque 2: " << attaque2->getNomAttaque() << std::endl;

  std::array<std::array<std::vector<Animal *>, maxY>, maxX> plateau;

  for (int i = 0; i < maxX; i++)
  {
    for (int j = 0; j < maxY; j++)
    {
      if (rand() % 4 == 0) // 25% de chance de créer un animal
      {
        int typeAnimal = rand() % 4;
        switch (typeAnimal)
        {
        case 0:
          plateau[i][j].push_back(new Lion(maxX, maxY));
          break;
        case 1:
          plateau[i][j].push_back(new Ours(maxX, maxY));
          break;
        case 2:
          plateau[i][j].push_back(new Pierre(maxX, maxY));
          break;
        case 3:
          plateau[i][j].push_back(new Loup(maxX, maxY));
          break;
        }
      }
    }
  }

  afficherPlateau(plateau);

  while (true)
  {
    std::cout << "Appuyez sur Entrée pour jouer un tour..." << std::endl;
    std::cin.get();
    afficherPlateau(plateau);
  }
  return 0;
}