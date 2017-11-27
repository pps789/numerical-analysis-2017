#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<double,double>> quad[6] = {
    // (point, weight)
    {},
    {
        {0, 2}
    },
    {
        {sqrt(1./3), 1},
        {-sqrt(1./3), 1}
    },
    {
        {0, 8./9},
        {sqrt(3./5), 5./9},
        {-sqrt(3./5), 5./9}
    },
    {
        {sqrt(3./7 - 2./7*sqrt(6./5)), (18 + sqrt(30)) / 36},
        {-sqrt(3./7 - 2./7*sqrt(6./5)), (18 + sqrt(30)) / 36},
        {sqrt(3./7 + 2./7*sqrt(6./5)), (18 - sqrt(30)) / 36},
        {-sqrt(3./7 + 2./7*sqrt(6./5)), (18 - sqrt(30)) / 36}
    },
    {
        {0, 128./225},
        {1./3*sqrt(5 - 2*sqrt(10./7)), (322 + 13*sqrt(70)) / 900},
        {-1./3*sqrt(5 - 2*sqrt(10./7)), (322 + 13*sqrt(70)) / 900},
        {1./3*sqrt(5 + 2*sqrt(10./7)), (322 - 13*sqrt(70)) / 900},
        {-1./3*sqrt(5 + 2*sqrt(10./7)), (322 - 13*sqrt(70)) / 900}
    }
};

double _f(double x){
    return exp(x);
}

double _g(double x){
    return 1+3*pow(x,5)+5*pow(x,9);
}

double gaussian_quadrature(double f(double), double a, double b, int N){
    double ret = 0;
    for(auto& p:quad[N]){
        ret += f((b-a)/2 * p.first + (a+b)/2) * p.second;
    }
    return ret * (b-a)/2;
}

int main(){
    cout << setprecision(12);
    double exact;

    cout << "==========" << endl;
    cout << "Integrate f(x) = e^x from 0 to 1" << endl;
    exact = exp(1) - 1;
    cout << "Exact value: " << exact << endl << endl;
    for(int N=1;N<=5;N++){
        cout << "Number of points: " << N << endl;
        double approx = gaussian_quadrature(_f, 0, 1, N);
        cout << "Approx. value: " << approx << endl;
        cout << "Error: " << approx - exact << endl << endl;
    }

    cout << "==========" << endl;
    cout << "Integrate f(x) = 1 + 3x^5 + 5x^9 from 0 to 1" << endl;
    exact = 2;
    cout << "Exact value: " << exact << endl << endl;
    for(int N=1;N<=5;N++){
        cout << "Number of points: " << N << endl;
        double approx = gaussian_quadrature(_g, 0, 1, N);
        cout << "Approx. value: " << approx << endl;
        cout << "Error: " << approx - exact << endl << endl;
    }
}
