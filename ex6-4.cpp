#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

double f(double t, double u){
    return 2 + 2*u + t + t*u;

    // so, solution is u(t) = c*exp(t*t/2 + 2*t) - 1
}

vector<vector<double>> betas = {
    {},
    {1},
    {-1./2, 3./2},
    {5./12, -16./12, 23./12},
    {-9./24, 37./24, -59./24, 55./24}
};

double adams_bashforth_step(const vector<double>& ts, const vector<double>& us, double dt, int r){
    r = min(r, (int)ts.size());
    int K = ts.size();
    
    double ret = us.back();
    const auto& beta = betas[r];
    for(int i=0;i<r;i++){
        ret += dt*beta[i]*f(ts[K-r+i], us[K-r+i]);
    }

    return ret;
}

double adams_bashforth(int N, int R){
    vector<double> ts(1, 0), us(1, 1); // initial values

    double dt = 1. / N;
    for(int i=0;i<N;i++){
        double u = adams_bashforth_step(ts, us, dt, R);
        ts.push_back(ts.back() + dt);
        us.push_back(u);
    }

    return us.back();
}

int main(){
    cout << setprecision(12);
    cout << "Solve f(t, u) = 2 + 2u + t + tu, 0<=t<=1, u(0) = 1" << endl;
    cout << "Exact solution of t=1: " << 2*exp(2.5) - 1 << endl;

    for(int R=2;R<=4;R++){
        cout << "==========" << endl;
        cout << "R=" << R << endl;
        cout << "==========" << endl;
        for(int N=10;N<=100000;N*=10){
            cout << "N=" << N << endl;
            double cur = adams_bashforth(N, R);
            double exact = 2*exp(2.5) - 1;
            cout << "Solution: " << cur << endl;
            double err = cur - exact;
            cout << "Absolute Error: " << err << endl;
            cout << "Relative Error: " << abs(err) / exact << endl;
        }
        cout << endl << endl;
    }
}

