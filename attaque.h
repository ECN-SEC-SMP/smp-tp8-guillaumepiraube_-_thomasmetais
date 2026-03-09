#include <random>
#include <string>
#include <ctime>

class Attaque {
  private:
    int type; // 0 :pierre, 1: Feuille, 2:Ciseaux
  public:
    Attaque(); // crée une attaque aléatoire
    Attaque(int a); // crée une attaque spécifique
    int getTypeAttaque() const; // retourne le type de l'attaque
    bool resoudreAttaque(const Attaque& a) const; // retourne true si l'attaque courante gagne contre l'attaque a
    std::string getNomAttaque() const; // retourne le nom de l'attaque
    ~Attaque(); // destructeur
};