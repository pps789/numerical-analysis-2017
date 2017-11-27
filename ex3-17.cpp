#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

ostream& operator<<(ostream& out, const vector<int>& poly){
    out << "(" << poly[0] << ")";
    for(int i=1;i<poly.size();i++){
        cout << "+(" << poly[i] << ")x";
        if(i>1) out << "^" << i;
    }
    return out;
}

double compute(const vector<int>& poly, double x){
    double ret = 0;
    for(int i=0;i<poly.size();i++){
        ret += pow(x, i) * poly[i];
    }
    return ret;
}

double integrate(const vector<int>& poly, double x){
    double ret = 0;
    for(int i=0;i<poly.size();i++){
        ret += pow(x, i+1) * poly[i] / (i+1);
    }
    return ret;
}

vector<pair<double,double>> quad = {
    {0, 32./45},
    {sqrt(3./7), 49./90},
    {-sqrt(3./7), 49./90},
    {1, 1./10},
    {-1, 1./10}
};

double GLL(const vector<int>& poly, int a, int b){
    double ret = 0;
    for(auto& p:quad){
        ret += compute(poly, (b-a)/2. * p.first + (a+b)/2.) * p.second;
    }
    return ret * (b-a)/2.;
}

int main(){
    srand(time(NULL));

    cout << setprecision(12);
    cout << "Integrate random polynomial (degree 7), random range using GLL rule" << endl;
    vector<int> poly;
    for(int i=0;i<8;i++){
        poly.push_back(rand() % 20 + 1); // coeff: 1 to 20
    }

    int lo = -9 + rand() % 10;
    int hi = rand() % 10;

    cout << "Integrate function: " << poly << endl;
    cout << "Integrate range: from " << lo << " to " << hi << endl;
    double exact = integrate(poly, hi) - integrate(poly, lo);
    cout << "Exact value: " << exact << endl;
    double approx = GLL(poly, lo, hi);
    cout << "Approx. value: " << approx << endl;
    cout << "Relative error: " << (approx - exact) / exact << endl;
}
