#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// variables constantes globales
const float m=2.0;
const float x=1.0;
const float v=0.0;
const float k=100.0;
float deltaT;
float t_0=0.0;

// funciones
void Euler_m(float m,float x, float v, float k, float deltaT,string name);

//metodo
void Euler_m(float m,float x, float v, float k, float deltaT, string name){
  ofstream outfile;
  outfile.open(name);
    
  float yn=1.0;
    
  for(t_0=0.0 ;t_0<=17.0;t_0+=deltaT){
      double x_n=x;
      double v_n=v;
      
      x += (deltaT*v_n);
      v -= (deltaT*(k/m)*x_n);
      
      outfile<<t_0<<"  "<<x<<"  "<<v<<"\n";
  }  
   outfile.close();
}

int main(){
string name="exe_14.dat";
Euler_m(2.0,1.0,0.0,10.0,0.01,name);
return 0;
}
