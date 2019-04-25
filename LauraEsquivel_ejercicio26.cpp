#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

void solve_equation_euler(float t_init, float t_end, float delta_t, float omega, string filename){
    int steps=100;
    freopen("euler.dat","w",stdout);

    double y_actual=0;
    double yn;


    double y[steps];
    double y1[steps];
    double dt=15.0/steps;
    y[0]=0.0;

    for(int i=1;i<steps;i++){
        yn=y_actual-dt*cos(dt*i);
        y[i]=yn;
        y_actual=yn;
    }

    y1[0]=1.0;
    y_actual=1.0;

    for(int i=1;i<steps;i++){
        yn=y_actual+dt*y[i-1];
        y1[i]=yn;
        y_actual=yn;
    }
    for(int i=0;i<steps;i++){
        cout<<y1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<steps;i++){
        cout<<y[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<steps;i++){
        cout<<dt*i<<" ";
    }

}
void solve_equation_rk4(float t_init, float t_end, float delta_t, float omega, string filename){
    int steps=500;
    freopen("rk4.dat","w",stdout);
    double y_actual=0.0;
    double k1,k2,k3,k4;
    double y[steps];
    double y1[steps];
    y[0]=y_actual;
    double dt=15.0/steps;
    for(int i=1;i<steps;i++){
        k1=-cos(dt*i);
        k2=-cos(dt*i+(dt/2.0));
        k3=-cos(dt*i+(dt/2.0));
        k4=-cos(dt*(i+1));
        y[i]=y[i-1]+(dt*(k1+2*k2+2*k3+k4)/(6.0));
    }
    y_actual=1.0;
    y1[0]=y_actual;
    for(int i=1;i<steps;i++){
        k1=y[i];
        k2=(y[i]+y[i+1])/2.0;
        k3=(y[i]+y[i+1])/2.0;
        k4=y[i+1];
        y1[i]=y1[i-1]+(dt*(k1+2*k2+2*k3+k4)/(6.0));
    }
    for(int i=0;i<steps;i++){
        cout<<y1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<steps;i++){
        cout<<y[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<steps;i++){
        cout<<dt*i<<" ";
    }

};
void solve_equation_leapfrog(float t_init, float t_end, float delta_t, float omega, string filename){
    freopen("leapfrog.dat","w",stdout);
    int steps=500;
    double y_actual=1;
    double yn;


    double y[steps];
    double y1[steps];
    double dt=15.0/steps;
    y[0]=1.0;
    y1[0]=0.0;
    y_actual=0;

    for(int i=1;i<steps;i++){
        y[i]=y[i-1]+y1[i-1]*dt-dt*dt*cos(dt*(i-1))/2.0;
        y1[i]=y1[i-1]+dt*(-cos(dt*i)-cos(dt*(i-1)))/2.0;
        y_actual=yn;
    }
    for(int i=0;i<steps;i++){
        cout<<y[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<steps;i++){
        cout<<y1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<steps;i++){
        cout<<dt*i<<" ";
    }


};


int main(){
  float omega=1.0;

   solve_equation_rk4(0.0, 10000.0, omega/2, omega, "rk4.dat");
  solve_equation_leapfrog(0.0, 10000.0, omega/2, omega, "leapfrog.dat");
  solve_equation_euler(0.0, 10000.0, omega/2, omega, "euler.dat");
  return 0;
}
