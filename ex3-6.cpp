#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;

const double PI = atan2(1,0)*2;

double _f(double x){
    return abs(sin(x));
}

double trapezoidel(double (*f)(double), double lo, double hi, int N){
    const double h = (hi - lo)/N;
    double ret = 0;
    double x = lo;
    for(int i=0;i<=N;i++){
        if(i==0 || i==N) ret += f(x)/2;
        else ret += f(x);
        x += h;
    }
    return h*ret;
}

double simpson(double (*f)(double), double lo, double hi, int N){
    const double h = (hi - lo)/N;
    double ret = 0;
    double x = lo;
    for(int i=0;i<=N;i++){
        if(i==0 || i==N) ret += f(x);
        else if(i%2) ret += 4*f(x);
        else ret += 2*f(x);
        x += h;
    }
    return h*ret/3;
}

double hermite(double (*f)(double), double lo, double hi, int N){
    const double h = (hi - lo)/N;
    return trapezoidel(f, lo, hi, N) + h*h/6; // hard-coded
}

int ns[] = {10, 20, 40, 80};

int main(){
    const double LO = -PI/2, HI = PI/2;
    cout << setprecision(12);

    cout << "Trapezoidal Rule" << endl;
    for(int n:ns){
        cout << "Case n=" << n << ":" << endl;
        double v = trapezoidel(_f, LO, HI, n);
        cout << "Value of integral: " << v << endl;
        cout << "Error: " << v-2 << endl;
    }
    cout << endl;
    cout << "Simpson Rule" << endl;
    for(int n:ns){
        cout << "Case n=" << n << ":" << endl;
        double v = simpson(_f, LO, HI, n);
        cout << "Value of integral: " << v << endl;
        cout << "Error: " << v-2 << endl;
    }
    cout << endl;
    cout << "Hermite Rule" << endl;
    for(int n:ns){
        cout << "Case n=" << n << ":" << endl;
        double v = hermite(_f, LO, HI, n);
        cout << "Value of integral: " << v << endl;
        cout << "Error: " << v-2 << endl;
    }
}
