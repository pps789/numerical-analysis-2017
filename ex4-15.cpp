#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

double phi(double m, double x, int d){
    if(d == 0) return x/(1+m*x);
    else if(d == 1) return 1 / pow(1+m*x, 2);
    else return -2*m / pow(1+m*x, 3);
}

double f1(double m, double lambda, double a, double b, double x1, double x2, int d1, int d2){
    if(d1 == 0 && d2 == 0){
        return lambda*x1 - a*pow(x1, 2) + b*phi(m, x1, 0)*x2;
    }
    
    if(d1 == 1 && d2 == 0){
        return lambda - 2*a*x1 + b*phi(m, x1, 1)*x2;
    }

    if(d1 == 0 && d2 == 1){
        return b*phi(m, x1, 0);
    }

    if(d1 == 2 && d2 == 0){
        return -2*a + b*phi(m, x1, 2)*x2;
    }

    if(d1 == 0 && d2 == 2){
        return 0;
    }

    if(d1 == 1 && d2 == 1){
        return b*phi(m, x1, 1);
    }
}

double f2(double m, double mu, double d, double c, double x1, double x2, int d1, int d2){
    if(d1 == 0 && d2 == 0){
        return mu*x2 - d*pow(x2, 2) - c*phi(m, x1, 0)*x2;
    }

    if(d1 == 1 && d2 == 0){
        return -c*phi(m, x1, 1)*x2;
    }

    if(d1 == 0 && d2 == 1){
        return mu - 2*d*x2 - c*phi(m, x1, 0);
    }

    if(d1 == 2 && d2 == 0){
        return -c*phi(m, x1, 2)*x2;
    }

    if(d1 == 0 && d2 == 2){
        return -2*d;
    }

    if(d1 == 1 && d2 == 1){
        return -c*phi(m, x1, 1);
    }
}

const double EPS = 1e-6;

void newton_method(double m, double lambda, double a, double b, double mu, double d, double c, double& x1, double& x2){
    while(1){
        double v1 = f1(m, lambda, a, b, x1, x2, 0, 0), v2 = f2(m, mu, d, c, x1, x2, 0, 0);
        double err = hypot(v1, v2);
        cout << "Newton Method Error: " << err << endl;
        if(err < EPS) return;

        double
            D11 = f1(m, lambda, a, b, x1, x2, 1, 0),
            D12 = f1(m, lambda, a, b, x1, x2, 0, 1),
            D21 = f2(m, mu, d, c, x1, x2, 1, 0),
            D22 = f2(m, mu, d, c, x1, x2, 0, 1);

        double det = D11*D22 - D12*D21;
        x1 -= (D22*v1 - D12*v2)/det;
        x2 -= (-D21*v1 + D11*v2)/det;
    }
}

pair<double, double> gradf(double m, double lambda, double a, double b, double mu, double d, double c, double x1, double x2){
    double v1 = f1(m, lambda, a, b, x1, x2, 0, 0);
    double v2 = f2(m, mu, d, c, x1, x2, 0, 0);
    return {
        2*(v1*f1(m, lambda, a, b, x1, x2, 1, 0) + v2*f2(m, mu, d, c, x1, x2, 1, 0)),
        2*(v1*f1(m, lambda, a, b, x1, x2, 0, 1) + v2*f2(m, mu, d, c, x1, x2, 0, 1))
    };
}

pair<pair<double, double>, pair<double, double>> Hf(double m, double lambda, double a, double b, double mu, double d, double c, double x1, double x2){
    double v1 = f1(m, lambda, a, b, x1, x2, 0, 0);
    double v2 = f2(m, mu, d, c, x1, x2, 0, 0);
    double
        D11 = f1(m, lambda, a, b, x1, x2, 1, 0),
        D12 = f1(m, lambda, a, b, x1, x2, 0, 1),
        D21 = f2(m, mu, d, c, x1, x2, 1, 0),
        D22 = f2(m, mu, d, c, x1, x2, 0, 1);

    return {
        {
            2*(D11*D11 + v1*f1(m, lambda, a, b, x1, x2, 2, 0) + D21*D21 + v2*f2(m, mu, d, c, x1, x2, 2, 0)),
            2*(D11*D12 + v1*f1(m, lambda, a, b, x1, x2, 1, 1) + D21*D22 + v2*f2(m, mu, d, c, x1, x2, 1, 1))
        },
        {
            2*(D12*D11 + v1*f1(m, lambda, a, b, x1, x2, 1, 1) + D22*D21 + v2*f2(m, mu, d, c, x1, x2, 1, 1)),
            2*(D12*D12 + v1*f1(m, lambda, a, b, x1, x2, 0, 2) + D22*D22 + v2*f2(m, mu, d, c, x1, x2, 0, 2))
        }
    };
}

void steepest_descent_method(double m, double lambda, double a, double b, double mu, double d, double c, double& x1, double& x2){
    // let f = f1*f1 + f2*f2!
    while(1){
        auto v = gradf(m, lambda, a, b, mu, d, c, x1, x2);
        double err = hypot(v.first, v.second);
        cout << "Steepest Descent Method Err: " << err << endl;
        if(err < EPS) return;

        double s = 1;
        while(1){
            auto p = gradf(m, lambda, a, b, mu, d, c, x1 - s*v.first, x2 - s*v.second);
            double g1 = -p.first*v.first - p.second*v.second;
            if(abs(g1) < EPS*EPS) break;

            auto H = Hf(m, lambda, a, b, mu, d, c, x1 - s*v.first, x2 - s*v.second);
            double g2
                = H.first.first*v.first*v.first
                + H.first.second*v.first*v.second
                + H.second.first*v.second*v.first
                + H.second.second*v.second*v.second;

            s -= g1/g2;
        }
        x1 -= s*v.first;
        x2 -= s*v.second;
    }
}

double _rand(){return 1;}

int main(){
    cout << setprecision(12);
    double m = _rand(), lambda = _rand(), a = _rand(), b = _rand(), mu = _rand(), d = _rand(), c = _rand();
    const double X1 = _rand(), X2 = _rand(); // initial values

    cout << "PARAMETERS" << endl;
    cout << "m: " << m << endl;
    cout << "lambda: " << lambda << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "mu: " << mu << endl;
    cout << "d: " << d << endl;
    cout << "c: " << c << endl << endl;
    cout << "INITIAL VALUES" << endl;
    cout << "(" << X1 << ", " << X2 << ")" << endl << endl;

    double x1 = X1, x2 = X2;
    newton_method(m, lambda, a, b, mu, d, c, x1, x2);
    cout << "Newton Method Result: (" << x1 << ", " << x2 << ")" << endl << endl;

    x1 = _rand(), x2 = _rand();
    steepest_descent_method(m, lambda, a, b, mu, d, c, x1, x2);
    cout << "Steepest Descent Method Result: (" << x1 << ", " << x2 << ")" << endl << endl;
}
