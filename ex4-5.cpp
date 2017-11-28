#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

const double EPS = 1e-15;

double _f(double x, int d){
    if(d==1) return exp(x)*(pow(x-0.5, 5) + 5*pow(x-0.5, 4));
    return exp(x)*pow(x-0.5, 5);
}

void order_guess(const vector<double>& errors){
    vector<double> last(errors.rbegin(), errors.rbegin() + 3);
    double ord = (log(last[1]-last[0])) / (log(last[2]-last[1]));
    cout << "Guessing order: " << ord << endl;
}

void newton(double (*f)(double, int), int m, double x, double exact){
    vector<double> errors;
    errors.push_back(abs(x - exact));
    do{
        x = x - m * f(x, 0) / f(x, 1);
        cout << "Current guess: " << x;
        errors.push_back(abs(x - exact));
        if(errors.size() >= 3){
            cout << ", ";
            order_guess(errors);
        }
        else cout << endl;
    } while(abs(f(x,0)) > EPS);

    cout << "Number of iteration: " << errors.size() << endl;
    cout << "Solution using Newton method: " << x << endl;
}

int main(){
    cout << setprecision(15);
    newton(_f, 5, 1.23, 0.5);
}
