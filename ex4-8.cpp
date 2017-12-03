#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

const double EPS = 1e-12;

double _f(double x){
    return exp(cos(4*x)) - x*x;
}

void fixed_point(double (*f)(double), double alpha, double x){
    int iter = 0;
    do{
        iter++;
        x = alpha * f(x) + x;
    } while(abs(f(x)) > EPS);

    cout << "Number of iteration: " << iter << endl;
    cout << "Solution using Fixed Point method: " << x << endl;
}

void bisection(double (*f)(double), double a, double b){
    int iter = 0;
    double c;
    do{
        iter++;
        c = (a+b)/2;
        if(f(a)*f(c) < 0) b = c;
        else a = c;
    } while(abs(f(c)) > EPS);

    cout << "Number of iteration: " << iter << endl;
    cout << "Solution using Bisection method: " << c << endl;
}

void regula_falsi(double (*f)(double), double a, double b){
    int iter = 0;
    double c;
    do{
        iter++;
        c = (a*f(b) - b*f(a)) / (f(b) - f(a));
        if(f(a)*f(c) < 0) b = c;
        else a = c;
    } while(abs(f(c)) > EPS);

    cout << "Number of iteration: " << iter << endl;
    cout << "Solution using Regula Falsi method: " << c << endl;
}

int main(){
    cout << setprecision(12);
    const double PI = atan2(1,0)*2;
    double a = PI/2, b = 2;
    double alpha =  0.1;
    fixed_point(_f, alpha, (a+b)/2);
    bisection(_f, a, b);
    regula_falsi(_f, a, b);
}
