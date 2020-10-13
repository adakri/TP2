#include "Player.h"
#include "Stone.h"
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Player::Player(int id, double size, std::vector<double> v0, int nbThrows, int nbStones )
{
  //l'aléatoire
  std::default_random_engine _generator(time(0));
  std::normal_distribution<double> _distribution(0.0,1.0);
  //les attributs
  _id = id;
  _size = size;
  _v0 = v0;
  _nbThrows = nbThrows;
  _nbStones = nbStones;
  //les constantes
  _g=10.;
  _dt=0.05;
  _coeff=1.;
  _meanMassStone=10+3*_distribution(_generator);

};




void Player::saveSolution(std::string nameSol, std::vector<std::vector<double> > sol)
{
  ofstream mystream;
  string file(nameSol);
  mystream.open(file, ios::out);
  for (int i=0; i<= sol.size(); i++)
  {
    mystream<<sol[0][i]<<" "<<sol[1][i]<<std::endl;
  }
  mystream.close();
};




// Player player(int nf, std::vector<double> size, std::vector<double> v0,int nbThrows,int nbStones);


void Player::play()
{
  for (int i=0; i<=_id; i++)
  {
    for (int j=0; j<=_nbThrows; j++)
    {
      for (int k=0; k<=_nbStones; k++)
      {
        std::vector<std::vector<double>> sol=twrowOneStone();

        ostringstream oss;
        oss<<"solution_mult_friends_nf_"<<_id<<" "<<i<<" "<<j<<" "<<k<<" "<<".txt"<<std::endl;
        string name_sol=oss.str();
        saveSolution(name_sol,sol);
      }
    }
  };

};

std::vector<std::vector<double> > Player::twrowOneStone()
{
  vector<double> x;
  vector<double> y;
  vector<double> vx;
  vector<double> vy;
  double temp1;
  double temp2;
  double t;
  double x0(0.);
  double cte=_coeff/_meanMassStone;
  ///////////////////
  double y0=_size;
  double vx0=_v0[0];
  double vy0=_v0[1];
  y.push_back(y0);
  x.push_back(x0);
  vy.push_back(vy0);
  vx.push_back(vx0);
  //one stone throw
  while(y.back()>0.)
  {

    temp1=vx.back();
    temp2=vy.back();

    x.push_back(x.back()+_dt*temp1);
    y.push_back(y.back()+_dt*temp2);

    vx.push_back(temp1-_dt*temp1*cte*sqrt(pow(temp1,2)+pow(temp2,2)));

    vy.push_back(temp2-_dt*temp2*cte*sqrt(pow(temp1,2)+pow(temp2,2))-_dt*_g);
    t+=_dt;

  };
  vx.clear();
  vy.clear();
  x.clear();
  y.clear();
  std::vector<std::vector<double> > sol;
  sol[0]=x;
  sol[1]=y;
  return sol;
};
