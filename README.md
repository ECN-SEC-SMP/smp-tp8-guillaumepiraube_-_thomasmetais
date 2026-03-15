# SMP – TP8 – Classes-bis

## 1) Introduction
Objectif : Réaliser le jeu de la vie articifielle avec des animaux qui s'attaquent au travers du chifoumi.

---
## 2) Fichiers utilisés
- `animal.h/.cpp` : Contient les méthodes et la structure de l'objet animal.
- `animaux.h/.cpp` : Contient les méthodes et les structures des différents animaux.
- `main.cpp` : Jeux d'essais des différentes méthodes.
- `attaque.h/.cpp` : Contient les méthodes d'attaques.

---
## 3) Structures
### A. `Animal(string nom, int x, int y, bool vivant, Attaque typeAttaque)`
- **Spécification** : Structure pour un animal qui contient un nom, deux entiers x et y pour la position, un booléen pour s'avoir si il est vivant et son type d'attaque.
- **Principe** : Structure de base pour un animal.

### B. `Lion(int maxX, int maxY)`
- **Spécification** : Structure du lion avec maxX et maxY pour les déplacements.
- **Principe** : Le lion se déplace aléatoirement dans 4 directions et attaque aléatoirement avec soit la feuille ou le ciseaux.

### C. `Ours(int maxX, int maxY)`
- **Spécification** : Structure de l'ours avec maxX et maxY pour les déplacements.
- **Principe** : L'ours se déplace aléatoirement dans 8 directions et attaque uniquement avec feuille.

### D. `Pierre(int maxX, int maxY)`
- **Spécification** : Structure de la pierre avec maxX et maxY pour les déplacements.
- **Principe** : La pierre ne se déplace pas et attaque uniquement avec la pierre.

### E. `Loup(int maxX, int maxY)`
- **Spécification** : Structure du loup avec maxX et maxY pour les déplacements.
- **Principe** : Le loup se déplace aléatoirement sur tout le plateau et attaque aléatoirement.

### F. `Attaque(int type)`
- **Spécification** : Structure de l'attaque avec le type d'attaque.
- **Principe** : Type = 0 : pierre; Type = 1 : feuille; Type = 2 : ciseaux;

---
## 4) Fonctions
### A. `void Lion::setAttaque()`
- **Spécification** : Permet de générer aléatoirement une attaque pour le lion entre la feuille ou le ciseau.

### B. `void Lion::deplace(int maxX, int maxY)`
- **Spécification** : Permet de se déplacer aléatoirement dans 4 directions (1, 1), (1, -1), (-1, 1) et (-1, -1).

### C. `Ours::deplace(int maxX, int maxY)`
- **Spécification** : Permet de se déplacer aléatoirement dans 8 directions (2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2) et (2, -1).

### D. `bool Attaque::resoudreAttaque(const Attaque &a) const`
- **Spécification** : Permet de définir qui gagne le combat entre deux attaques. Si égalité alors l'un des deux attaquants gagne au hasard. 

### E. `std::string Attaque::getNomAttaque() const`
- **Spécification** : Permet de renvoyer le nom d'une attaque en fonction du type.

### F. `void afficherPlateau(std::vector<Animal *> &animaux)`
- **Spécification** : Permet d'afficher le plateau avec les animaux dessus en sortie.

### G. `void jouerTour(std::vector<Animal *> &animaux)`
- **Spécification** : Execute les déplacements des animaux et réalise les différentes attaques.

---
## 5) Validations

Dans notre fichier main.cpp, nous avons fait en sorte de remplir 25% du plateau avec des animaux aléatoires.
L'utilisateur doit ensuite appuyer sur entrée pour pouvoir passer un tour jusqu'à ce qu'il ne reste plus qu'un seul animal vivant.

---
## 5) Conclusion
Ce TP nous a permis de mettre en pratique les notions vues lors du dernier CM et TD sur le parcours des listes et la déclaration et manipulation des objets. 
