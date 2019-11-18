// RK4

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


// variables constantes globales
const float m=2.0;
const float x=1.0;
const float v=0.0;
const float k=50.0;
const double lambda =1.0;
double DeltaT=0.01;
double t_0=0.0;



// declaracion de funciones

double fy0(double t, double y0, double y1); // derivada de y0
double fy1(double t, double y0, double y1); // derivada de y1

void rk(double t, double h, double & y0, double & y1); // metodo de runge kutta 4 orden 


// metodo de runge kutta 4 orden

double fy0(double t, double y0, double y1)
{
  return y1;
}

double fy1(double t, double y0, double y1)
{
  return (-k/m)*pow(y0, lambda);
}


//sacado del metodo del lab: https://raw.githubusercontent.com/JoseMontanaC/Laboratorio-Metodos-Computacionales/master/c_tests??///Rungekutta_Nvars.cpp
void rk(double t, double h, double & y0, double & y1) // metodo de runge kutta 4 orden
{
  double ky10, ky11, ky20, ky21, ky30, ky31, ky40, ky41;
	
  ky10 = h*fy0(t, y0, y1);
  ky11 = h*fy1(t, y0, y1);
  ky20 = h*fy0(t+h/2, y0 + ky10/2, y1 + ky11/2);
  ky21 = h*fy1(t+h/2, y0 + ky10/2, y1 + ky11/2);
  ky30 = h*fy0(t+h/2, y0 + ky20/2, y1 + ky21/2);
  ky31 = h*fy1(t+h/2, y0 + ky20/2, y1 + ky21/2);
  ky40 = h*fy0(t + h, y0 + ky30, y1 + ky31);
  ky41 = h*fy1(t + h, y0 + ky30, y1 + ky31);
	
  y0 = y0 + (1.0/6.0)*(ky10 + 2*ky20 + 2*ky30 + ky40);
  y1 = y1 + (1.0/6.0)*(ky11 + 2*ky21 + 2*ky31 + ky41);
}

int main(void)
{
  ofstream fout("exe_rk14.dat");
  double x = 1, v =0;
  double time;
  for(time = 0; time <= 17.0; time += DeltaT) {
    fout << time << "   " << x << "   " << v << endl;
      
    rk(time, DeltaT, x, v);
  }
  fout.close();

  return 0;
}