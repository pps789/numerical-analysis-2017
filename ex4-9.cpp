#include<iostream>
#include<complex>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

const double EPS = 1e-12;

double _f(double x, int d){
    if(d==2 || d==1) return exp(x);
    return exp(x)-1;
}

double _g(double x, int d){
    if(d==2) return 2;
    if(d==1) return 2*x-1;
    return x*x-x-1;
}

double _h(double x, int d){
    if(d==2) return 6*x-2;
    if(d==1) return 3*x*x-2*x;
    return x*x*x-x*x-x-1;
}

void improved_newton(double (*f)(double, int), double x){
    int iter = 0;
    do{
        iter++;
        x = x - ((f(x,1) - sqrt(pow(f(x,1),2) - 2*f(x,2)*f(x,0))) / f(x,2));
    } while(abs(f(x,0)) > EPS);

    cout << "Number of iteration: " << iter << endl;
    cout << "Solution using Improved Newton method: " << x << endl;
}

vector<double> newton_difference(double (*fun)(double, int), const vector<double>& xlist){
    // assume that xlist.size() >= 2
    const int N = (int)xlist.size() - 1;

    vector<double> ret(N+1);
    for(int i=0;i<=N;i++) ret[i] = fun(xlist[i], 0); // initialize

    for(int j=1;j<=N;j++) for(int k=N;k>=j;k--)
        ret[k] = (ret[k] - ret[k-1]) / (xlist[k] - xlist[k-j]);

    return ret;
}

void order_guess(const vector<double>& errors){
    if(errors.size() < 3){
        cout << "Guessing order failed: too fast conv." << endl;
    }
    else{
        vector<double> last(errors.rbegin(), errors.rbegin() + 3);
        double ord = (log(last[1]-last[0])) / (log(last[2]-last[1]));
        cout << "Guessing order: " << ord << endl;
    }
}

void muller(double (*f)(double,  int), double x0, double x1, double x2){
    int iter = 0;
    double x;
    vector<double> errors;
    do{
        iter++;
        double a = newton_difference(f, {x2, x1, x0}).back();
        double b = newton_difference(f, {x2, x1}).back()
            + newton_difference(f, {x2, x0}).back()
            - newton_difference(f, {x1, x0}).back();
        double c = f(x2, 0);

        x = x2 + (-b + sqrt(b*b-4*a*c)) / (2*a);
        x0 = x1;
        x1 = x2;
        x2 = x;
        errors.push_back(x);
    } while(abs(f(x, 0)) > EPS);

    double solution = x;
    for(auto& e:errors) e = abs(e-solution);

    cout << "Number of iteration: " << iter << endl;
    cout << "Solution using Muller method: " << x << endl;
    order_guess(errors);
}

int main(){
    cout << setprecision(12);
    improved_newton(_f, -0.5);
    improved_newton(_g, 0.5);
    improved_newton(_h, 1.5);

    muller(_f, -3, -2, -1);
    muller(_g, -1, 0, 1);
    muller(_h, 0, 0.5, 1);
}
