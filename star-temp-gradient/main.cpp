#include <iostream>
#include <math.h>
using namespace std;
typedef long double ld;

// constants in standard mks
ld pi = 3.141592654;
ld grav_const = 6.67408*pow(10,-11);

ld k = 1.38*pow(10,-23);
ld u = 0.61;
ld m_h = 1.67*pow(10,-27);
ld T_eighty_r = 1*pow(10,6);

ld a = 7.56*pow(10,-16);
ld r_sun = 638000000;
ld kappa_star = 0.001;

ld c_p = 2.5;
ld c_v = 1.5;
ld gamma_star = c_p/c_v;

ld initialDensity = 150000; // 150 kg/m^3

ld c_light = 3*pow(10,8);

ld L = 3.86*pow(10,26);

// calculate density at given radius
ld density(long double radius){
    return initialDensity * (1-radius/r_sun);
}

// calculate mass of sphere at given radius
ld mass(long double radius){
    return 4*pi*initialDensity*( pow(radius,3)/3 - pow(radius,4)/(4*r_sun) );
}

// calculate pressure of sphere at given radius
ld pressure(long double r){
    return -4*pi*grav_const*initialDensity*initialDensity*((r*r*r*r)/(16*r_sun*r_sun)-(7*r*r*r)/(36*r_sun)+(r*r)/6)+(5/36*pi*grav_const*initialDensity*initialDensity*r_sun*r_sun);
    //return pi*grav_const*pow(initialDensity,2) * ( -4*( pow(r,4)/(16*pow(r_sun,2)) - 7*pow(r,3)/(36*r_sun) + pow(r,2)/6 ) + (5/36)*pow(r_sun,2) );
}

// calculate final temperature at given radius
ld temperature(long double r){
    //return u*m_h*pressure(radius)/k/density(radius);
    return 0.1*(5*pi*grav_const*u*m_h)/(36*k)*initialDensity*r_sun*r_sun*(1+r/(r_sun*r_sun)-(19*r*r)/(5*r_sun*r_sun)+(9*r*r*r)/(5*r_sun*r_sun*r_sun))+1.3125*pow(10,7);

}

int main(int argc, const char * argv[]) {
    
//  temperature = (0.1*pressure(r)*u*m_h)/(k*density(r));
    
    for (int x = 0; x < r_sun; x += 2000){
        cout << temperature(x);
        cout << "\n";
    }
    
    return 0;
}
