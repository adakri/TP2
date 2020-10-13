#include <iostream>
// Définition de votre classe
class Stone
{
  private:
  double _mass;
  
  public:
  Stone(double mass);
  Stone(const Stone& stone);

  const double& getMass() const;
  
};

//surcharge
std::ostream& operator<<(std::ostream& out, Stone const& stone);
// Permet de comparer deux cailloux entre eux
bool operator==(Stone const& stone1, Stone const& stone2);
