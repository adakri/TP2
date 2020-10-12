#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>

int main()
{
  using namespace std;
  vector<double> x;
  vector<double> y;
  vector<double> vx;
  vector<double> vy;
  double temp1;
  double temp2;
  double t;
  double cte;
  // Gravity
  double g = 9.80665; // m.s^{-2}
  // Step time
  double dt = 0.005;
  // Initial conditions
  double x0(0), y0(1.8), vx0(6), vy0(4);
  // Turbulent friction
  double coeff = 1;
  // Mass
  double mass = 10; // g
  //constant
  cte=coeff/mass;
  t=0.;
  y.push_back(y0);
  x.push_back(x0);
  vy.push_back(vy0);
  vx.push_back(vx0);


  //file
  ofstream mystream;
  string file("solution_1_stone.txt");
  mystream.open(file, ios::out);

  //initialisation
  mystream<<t<<" "<<x.back()<<" "<<y.back()<<" "<<vx.back()<<" "<<vy.back()<<" "<<endl;

  while(y.back()>0.)
  {
    temp1=vx.back();
    temp2=vy.back();
    // cout<<x.back()<<endl;
    x.push_back(x.back()+dt*temp1);
    y.push_back(y.back()+dt*temp2);

    vx.push_back(temp1-dt*temp1*cte*sqrt(pow(temp1,2)+pow(temp2,2)));

    vy.push_back(temp2-dt*temp2*cte*sqrt(pow(temp1,2)+pow(temp2,2))-dt*g);
    t+=dt;
    mystream<<t<<" "<<x.back()<<" "<<y.back()<<" "<<vx.back()<<" "<<vy.back()<<" "<<endl;


  }
  return 0.;
}
