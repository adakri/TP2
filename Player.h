#include <vector>
#include <random>
#include <string>
class Player 
{
    private: 
    int _id;
    
    double _size;
    
    std::vector<double> _v0;
    int _nbThrows;
    int _nbStones;
    double _g;
    double _dt;
    double _coeff;
    double _meanMassStone;
    std::default_random_engine _generator;
    std::normal_distribution<double> _distribution;
    public: 
    Player(int id, double size, std::vector<double> v0, int nbThrows, int nbStones);
   
    void play();
  
    std::vector<std::vector<double> > twrowOneStone();
    void saveSolution(std::string nameSol, std::vector<std::vector<double> > sol);


    //get_prop
    const double& get_id() const;
    const double& get_size() const;
    const double& get_speed() const;

   

};