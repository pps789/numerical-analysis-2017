#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<complex>
using namespace std;

const int ITER = 100000;

vector<double> div(const vector<double>& poly, double u, double v, double &c, double &d){
    const int N = poly.size();
    vector<double> ret(N);
    for(int i=N-3;i>=0;i--) ret[i] = poly[i+2] - u*ret[i+1] - v*ret[i+2];
    ret.resize(N-2);

    c = poly[1] - u*ret[0] - v*ret[1];
    d = poly[0] - v*ret[0];
    return ret;
}

pair<double,double> bairstow_step(const vector<double>& poly, pair<double, double> uv){
    double c, d, g, h;
    auto q = div(poly, uv.first, uv.second, c, d);
    auto r = div(q, uv.first, uv.second, g, h);

    double det = uv.second*g*g + h*(h-uv.first*g);
    double u = uv.first - (-h*c + g*d) / det;
    double v = uv.second - (-g*uv.second*c + (g*uv.first-h)*d) / det;

    return {u,v};
}

pair<double,double> bairstow(const vector<double>& poly){
    pair<double,double> uv(rand(), rand());
    for(int i=0;i<ITER;i++) uv = bairstow_step(poly, uv);
    return uv;
}

typedef complex<double> cd;
pair<cd, cd> solve_quad(pair<double,double> uv){
    cd a = 1, b = uv.first, c = uv.second;
    cd det = b*b-4.*a*c;
    return {(-b+sqrt(det))/2., (-b-sqrt(det))/2.};
}

int main(){
    cout << setprecision(12);
    vector<double> poly = {1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<cd> solutions;

    for(int i=0;i<4;i++){
        auto uv = bairstow(poly);
        auto cur = solve_quad(uv);
        solutions.push_back(cur.first); solutions.push_back(cur.second);
        
        double x, y;
        poly = div(poly, uv.first, uv.second, x, y);
    }

    auto last = solve_quad({poly[1], poly[0]});
    solutions.push_back(last.first); solutions.push_back(last.second);

    cout << "Zeros: " << endl;
    for(int i=0;i<10;i++) cout << solutions[i] << endl;
}

