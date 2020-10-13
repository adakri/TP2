#include "Stone.h"

Stone::Stone(double mass)
{
}

Stone::Stone(const Stone& stone)
{
}

const double& Stone::getMass() const
{
}

//
std::ostream& operator<<(std::ostream &out, Stone const& stone)
{
  out <<"( la masse du caillou est "<<stone.getMass()<<" )"<< std::endl;
  return out;
}


// Permet de comparer deux cailloux entre eux
bool operator==(Stone const& stone1, Stone const& stone2)
{
  // Effectuer la comparaison (même masse)
  if (stone1.getMass()== stone2.getMass() )
    return true;
  else
    return false;
}
