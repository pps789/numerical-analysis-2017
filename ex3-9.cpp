#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


/*
 * f(x) = sin(e^x)
double _f(double x, int d){
    double ex = exp(x);
    double s = sin(ex), c = cos(ex);
    if(d==0){
        return s;
    }
    else if(d==1){
        return ex * c;
    }
    else if(d==3){
        return -3*exp(2*x)*s + ex*c - exp(3*x)*c;
    }
    else if(d==5){
        return -15*exp(2*x)*s + 10*exp(4*x)*s + ex*c - 25*exp(3*x)*c + exp(5*x)*c;
    }
}
*/

// y = e^x * sin(e^x)
double _f(double x, int d){
    double ex = exp(x);
    double s = sin(ex), c = cos(ex);
    if(d==-1){
        // integrate.
        return -c;
    }
    if(d==0){
        return ex * s;
    }
    else if(d==1){
        return ex*s + exp(2*x)*c;
    }
    else if(d==3){
        return ex*s
            - 6*exp(3*x)*s
            + 7*exp(2*x)*c
            - exp(4*x)*c;
    }
    else if(d==5){
        return ex*s
            - 90*exp(3*x)*s
            + 15*exp(5*x)*s
            + 31*exp(2*x)*c
            - 65*exp(4*x)*c
            + exp(6*x)*c;
    }
}

const double B[] = {1, -0.5, 1./6, 0, -1./30, 0, 1./42}; // Bernouilli Numbers
const double fact[] = {1, 1, 2, 6, 24, 120, 720};

double EMS(double (*f)(double, int), double a, double b, int M, int N){
    const double h = (b-a)/N;

    double ret = (f(a,0) + f(b,0))/2;
    double x = a;
    for(int i=0;i<N-1;i++){
        x += h;
        ret += f(x,0);
    }
    ret *= h;

    for(int i=1;i<=M;i++){
        ret += B[2*i] / fact[2*i] * pow(h, 2*i) * (f(a, 2*i-1) - f(b, 2*i-1));
    }
    return ret;
}

pair<int,int> ranges[] = {{0, 1}, {-1, 1}, {0, 2}};
int Ns[] = {1, 10};

int main(){
    cout << setprecision(12);
    cout << "Integrate e^x * sin(e^x) using Euler-Maclaruin summation formula" << endl << endl;

    for(int iter=0;iter<3;iter++){
        double lo, hi;
        tie(lo, hi) = ranges[iter];
        cout << "==========" << endl;
        cout << "Integrate from " << lo << " to " << hi << endl;
        const double exact = _f(hi, -1) - _f(lo, -1);
        cout << "Exact value: " << exact << endl << endl;

        for(int N:Ns) for(int m=1;m<=3;m++){
            cout << "N=" << N << " and m=" << m << endl;
            double approx = EMS(_f, lo, hi, m, N);
            cout << "Approx. value: " << approx << endl;
            cout << "Error: " << approx - exact << endl << endl;
        }
    }
}
