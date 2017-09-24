#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double f(double t){
    return 1/(1+t*t);
}

double g(double t){
    return sqrt(t);
}

vector<double> newton_difference(double (*fun)(double), const vector<double>& xlist){
    // assume that xlist.size() >= 2
    const int N = (int)xlist.size() - 1;

    vector<double> ret(N+1);
    for(int i=0;i<=N;i++) ret[i] = fun(xlist[i]); // initialize

    for(int j=1;j<=N;j++) for(int k=N;k>=j;k--)
        ret[k] = (ret[k] - ret[k-1]) / (xlist[k] - xlist[k-j]);

    return ret;
}

vector<double> expansion(const vector<double>& newton, const vector<double>& xlist){
    // also assume that xlist.size() >= 2
    const int N = (int)xlist.size() - 1;
    vector<double> ret(N+1), psi(N+1);

    psi[0] = 1;
    ret[0] = newton[0];
    for(int i=1;i<=N;i++){
        // psi: coeff. of (x-x0)...(x-x_i-1)
        for(int j=i;j>0;j--) psi[j] = psi[j-1] - psi[j]*xlist[i-1];
        psi[0] = -psi[0]*xlist[i-1];

        for(int j=0;j<=i;j++)
            ret[j] += psi[j]*newton[i];
    }
    return ret;
}

double get_value_from_newton(const vector<double>& newton, const vector<double>& xlist, double x){
    const int N = (int)xlist.size() - 1;
    double ret = newton[0], multiplier = 1;
    for(int i=1;i<=N;i++){
        multiplier *= x - xlist[i-1];
        ret += newton[i]*multiplier;
    }
    return ret;
}

void process(double (*fun)(double), double a, double b, int steps){
    double h = (b-a)/steps;
    vector<double> xlist(1, a);
    for(int i=0;i<steps;i++) xlist.push_back(a + (i+1)*h);

    cout << "Finding the interpolation polynomial degree " << steps << " with following points:" << endl;
    for(double x:xlist) cout<< "(" << x << ", " << fun(x) << ") "; cout << endl;

    auto newton = newton_difference(fun, xlist);
    cout << "Found newton coefficients:" << endl;
    for(double nd:newton) cout << nd << " "; cout << endl;

    cout << "Polynomial degree " << steps << ":" << endl;
    cout << newton[0] << endl;
    for(int i=1;i<=steps;i++){
        cout << "+(" << newton[i] << ")";
        for(int j=0;j<i;j++) cout << "(x" << (xlist[j] >= 0 ? "-" : "+") << abs(xlist[j]) << ")";
        cout << endl;
    }

    auto expanded = expansion(newton, xlist);
    cout << "Expanded polynomial degree " << steps << ":" << endl;

    cout << expanded[0] << endl;
    for(int i=1;i<=steps;i++) cout << "+(" << (abs(expanded[i]) < 1e-10 ? 0 : expanded[i])  << ")x^" << i << endl;

    const int M = 1000000;
    cout << "Discrete maximum error with M = 10^6:" << endl;
    double err = 0, h_m = (b-a)/M;
    for(int i=0;i<=M;i++){
        double x = a + h_m * i;
        err = max(err, abs(fun(x) - get_value_from_newton(newton, xlist, x)));
    }
    cout << err << endl << endl;
}

int main(){
    cout << "i) f(t) = 1/(1+t*t) on [-5, 5]" << endl << endl;
    for(int n=1;n<=10;n++){
        double a = -5, b = 5;
        process(f, a, b, n);
        cout << endl;
    }

    cout << endl << endl << "ii) f(t) = sqrt(t) on [0, 1]" << endl << endl;
    for(int n=1;n<=10;n++){
        double a = 0, b = 1;
        process(g, a, b, n);
    }
}
