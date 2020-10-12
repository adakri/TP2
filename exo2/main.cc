#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <sstream>

using namespace std;

int main()
{
  // Normal distribution
  std::default_random_engine generator(time(0));
  std::normal_distribution<double> distribution(0.0,1.0);
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
  // Turbulent friction
  double coeff = 1;
  // Initial conditions
  double x0(0);
  for (int j=0; j<=2; j++)
  {
    for (int i=0; i<=9; i++)
    {
      cout<<"boucle commencé"<<endl;


      // Initial conditions
      double y0=1.7+0.05*0.05*distribution(generator);
      cout<<y0<<endl;
      double vx0=6.+0.5*0.5*distribution(generator)+0.1*0.1*distribution(generator);
      double vy0=4.+0.5*0.5*distribution(generator)+0.1*0.1*distribution(generator);
      // Mass
      double mass = 10+3*3*distribution(generator); // g
      //constant
      cte=coeff/mass;
      t=0.;
      y.push_back(y0);
      x.push_back(x0);
      vy.push_back(vy0);
      vx.push_back(vx0);


      //file
      ofstream mystream;
      ostringstream oss;
      oss<<"solution_mult_throws_mult_stones_nl_"<<j<<"ns_"<<i<<".txt";
      string file=oss.str();
      mystream.open(file, ios::out);

      //initialisation
      mystream<<t<<" "<<x.back()<<" "<<y.back()<<" "<<vx.back()<<" "<<vy.back()<<" "<<endl;
      cout<<"while commencé"<<endl;
      while(y.back()>0.)
      {

        temp1=vx.back();
        temp2=vy.back();

        x.push_back(x.back()+dt*temp1);
        y.push_back(y.back()+dt*temp2);

        vx.push_back(temp1-dt*temp1*cte*sqrt(pow(temp1,2)+pow(temp2,2)));

        vy.push_back(temp2-dt*temp2*cte*sqrt(pow(temp1,2)+pow(temp2,2))-dt*g);
        t+=dt;


        mystream<<t<<" "<<x.back()<<" "<<y.back()<<" "<<vx.back()<<" "<<vy.back()<<" "<<endl;


      }
      vx.clear();
      vy.clear();
      x.clear();
      y.clear();
      mystream.close();
    }
  }


  return 0.;
}
