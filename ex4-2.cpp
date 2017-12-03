#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

const double EPS = 1e-15;

double _f(double x, int d){
    if(d==1) return exp(x); // derivative
    return exp(x) - 1;
}

void order_guess(const vector<double>& errors){
    if(errors.size() < 3){
        cout << "Guessing order failed: too fast conv." << endl;
    }
    else{
        vector<double> last(errors.rbegin(), errors.rbegin() + 3);
        double ord = (log(last[1]/last[0])) / (log(last[2]/last[1]));
        cout << "Guessing order: " << ord << endl;
    }
}

void newton(double (*f)(double, int), double x, double exact){
    vector<double> errors;
    errors.push_back(abs(x - exact));
    do{
        x = x - f(x, 0) / f(x, 1);
        errors.push_back(abs(x - exact));
    } while(abs(f(x,0)) > EPS);

    cout << "Number of iteration: " << errors.size() << endl;
    cout << "Solution using Newton method: " << x << endl;
    order_guess(errors);
}

void regula_falsi(double (*f)(double, int), double a, double b, double exact){
    vector<double> errors;
    double c;
    do{
        c = (a*f(b,0) - b*f(a,0)) / (f(b,0) - f(a,0));
        errors.push_back(abs(c - exact));
        if(f(a,0)*f(c,0) < 0) b = c;
        else a = c;
    } while(abs(f(c,0)) > EPS);

    cout << "Number of iteration: " << errors.size() << endl;
    cout << "Solution using Regula Falsi method: " << c << endl;
    order_guess(errors);
}

void secant(double (*f)(double, int), double a, double b, double exact){
    vector<double> errors;
    double c;
    do{
        c = b - f(b,0) / ((f(b,0)-f(a,0)) / (b-a));
        errors.push_back(abs(c - exact));
        a = b;
        b = c;
    } while(abs(f(c,0)) > EPS);

    cout << "Number of iteration: " << errors.size() << endl;
    cout << "Solution using Secant method: " << c << endl;
    order_guess(errors);
}

int main(){
    const double MAGIC = 1.23;
    cout << setprecision(15);
    newton(_f, MAGIC, 0);
    regula_falsi(_f, -MAGIC, MAGIC, 0);
    secant(_f, 2*MAGIC, MAGIC, 0);
}
