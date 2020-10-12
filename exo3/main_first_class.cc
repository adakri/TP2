#include <iostream>
#include "Stone.h"
int main()
{

  Stone stone(9.3);
  std::cout << "La masse du caillou 1 est : " << stone.getMass() << std::endl;
  Stone stone2(11.5);
  std::cout << "La masse du caillou 2 est : " << stone2.getMass() << std::endl;
  Stone stone3(stone);
  std::cout << "La masse du caillou 3 est : " << stone3.getMass() << std::endl;
  std::cout << stone;
  std::cout << stone2;
  // Comparaison entre les deux caillous
  if (stone == stone2)
  {
  std::cout << "Les cailloux sont les memes !" << std::endl;
  }
  else
  {
  std::cout << "Les cailloux sont differents !" << std::endl;
  }
  return 0;
}
