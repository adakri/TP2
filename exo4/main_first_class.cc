#include <iostream>
#include "Stone.h"
#include "Player.h"
int main()
{
  int nbFriends(4);
  std::vector<double> size(nbFriends);
  std::vector<std::vector<double> > v0(nbFriends, std::vector<double>(2));
  // Ines, taille moyenne, lanceuse de poids
  size[0] = 1.63; v0[0][0] = 6; v0[0][1] = 5;
  // Mael, taille moyenne, pas de sport connu
  size[1] = 1.75; v0[1][0] = 5; v0[1][1] = 4.2;
  // Abdel, taille supérieure à la moyenne, nageur
  size[2] = 1.83; v0[2][0] = 6; v0[2][1] = 4;
  // Jeanne, taille inférieure à la moyenne, pas de sport connu
  size[3] = 1.58; v0[3][0] = 4.5; v0[3][1] = 3.5;
  // Nombre de lancer
  int nbThrows(10);
  // Nombre de cailloux lancés à chaque lancer
  int nbStones(10);
  // Boucle sur les joueurs
  for (int nf = 0 ; nf < nbFriends ; nf++)
  {
  // Définir le player
  Player player(nf, size[nf], v0[nf], nbThrows, nbStones);
  // Le faire jouer
  player.play();
  }
  return 0;
}
