#include "attaque.h"
#include <iostream>

int main(int argc, char** argv) {
  Attaque *attaque1 = new Attaque();
  Attaque *attaque2 = new Attaque(2);
  std::cout << "Attaque 1: " << attaque1->getNomAttaque() << std::endl;
  std::cout << "Attaque 2: " << attaque2->getNomAttaque() << std::endl;
  return 0;
}