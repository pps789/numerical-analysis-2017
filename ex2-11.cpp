#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

double _f(double x, int d){
    // returns f^(d)(x)
    switch(d){
        case 0:
            return exp(-x)*sin(x);
        case 1:
            return exp(-x)*(cos(x)-sin(x));
        case 2:
            return -2*exp(-x)*cos(x);
        case 3:
            return 2*exp(x)*(sin(x)+cos(x));
        default:
            // unreachable
            return 0;
    }
}

double factorial(int n){
    int ret = 1;
    for(int i=1;i<=n;i++) ret *= i;
    return ret;
}

vector<double> newton_difference(double (*fun)(double, int), vector<double>& xlist){
    const int N = (int)xlist.size() - 1;
    sort(xlist.begin(), xlist.end());

    vector<double> ret(N+1);
    for(int i=0;i<=N;i++) ret[i] = fun(xlist[i], 0); // initialize

    for(int j=1;j<=N;j++) for(int k=N;k>=j;k--){
        if(xlist[k] == xlist[k-j])
            ret[k] = fun(xlist[k], j) / factorial(j);
        else ret[k] = (ret[k] - ret[k-1]) / (xlist[k] - xlist[k-j]);
    }

    return ret;
}

void print_x(int x, int deg){
    if(x==0) cout << "x";
    else cout << "(x-" << x << ")";
    if(deg) cout << "^" << deg;
}

void print_term(double coeff, const map<int,int>& order){
    cout << "(" << coeff << ")";
    for(const auto& kv:order) print_x(kv.first, kv.second);
}

int main(){
    vector<double> xlist = {0,0,0,0,1,1,1,2,2,3};
    auto nd = newton_difference(_f, xlist);

    map<int,int> order;
    cout << nd[0];
    for(int i=1;i<10;i++){
        cout << "+";
        order[xlist[i-1]]++;
        print_term(nd[i], order);
    }
    cout << endl;
}
