#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

vd add(const vd& f, const vd& g){
    const int N = max(f.size(), g.size());
    vd ret(N);
    for(int i=0;i<f.size();i++) ret[i] += f[i];
    for(int i=0;i<g.size();i++) ret[i] += g[i];
    return ret;
}

vd mult(const vd& f, const vd& g){
    const int N = f.size() + g.size() - 1;
    vd ret(N);
    for(int i=0;i<f.size();i++) for(int j=0;j<g.size();j++)
        ret[i+j] += f[i] * g[j];
    return ret;
}

vd pow(const vd& f, int n){
    if(n==0) return vd(1,1);
    return mult(pow(f, n-1), f);
}

ostream& operator<<(ostream& out, const vd& poly){
    out << "(" << poly[0] << ")";
    for(int i=1;i<poly.size();i++){
        cout << "+(" << poly[i] << ")x";
        if(i>1) out << "^" << i;
    }
    return out;
}

vd tridiagonal_matrix_algorithm(const vd& a, const vd& b, const vd& c, const vd& d){
    // https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm
    const int N = a.size();

    vd c2(N), d2(N), x(N);
    c2[0] = c[0]/b[0];
    for(int i=1;i<N;i++)
        c2[i] = c[i] / (b[i] - a[i]*c2[i-1]);
    d2[0] = d[0]/b[0];
    for(int i=1;i<N;i++)
        d2[i] = (d[i] - a[i]*d2[i-1]) / (b[i] - a[i]*c2[i-1]);

    x.back() = d2.back();
    for(int i=N-2;i>=0;i--)
        x[i] = d2[i] - c2[i]*x[i+1];
    return x;
}

vvd natural_spline(const vd& xlist, const vd& ylist){
    // assume that xlist.size() >= 2
    const int N = xlist.size() - 1;

    // so N >= 1.
    vd h(N);
    for(int i=0;i<N;i++) h[i] = xlist[i+1] - xlist[i];

    // apply tridiagonal matrix algorithm.
    vd a(N-1), b(N-1, 2.), c(N-1), d(N-1);

    for(int i=0;i<N-1;i++)
        a[i] = h[i] / (h[i]+h[i+1]);
    for(int i=0;i<N-1;i++)
        c[i] = h[i+1] / (h[i]+h[i+1]);
    for(int i=0;i<N-1;i++)
        d[i] = 6/(h[i]+h[i+1])
            * ((ylist[i+2]-ylist[i+1])/h[i+1] - (ylist[i+1]-ylist[i])/h[i]);
    
    vd x = tridiagonal_matrix_algorithm(a,b,c,d);
    vd M(N+1);
    for(int i=1;i<N;i++) M[i] = x[i-1];

    // boundary condition of natural spline is M[0]=M[N]=0.
    // so, there is nothing to do.

    // now we need to compute array A and B.
    vd A(N), B(N);
    for(int i=0;i<N;i++)
        A[i] = (ylist[i+1]-ylist[i])/h[i] + h[i]/6*(M[i]-M[i+1]);
    for(int i=0;i<N;i++)
        B[i] = ylist[i] - M[i]*h[i]*h[i]/6;

    // now we can compute each cubic polynomials!
    vvd ret;
    for(int i=0;i<N;i++){
        vd cubic_0 = mult(
                vd(1, M[i]/6/h[i]),
                pow({xlist[i+1], -1}, 3));
        vd cubic_1 = mult(
                vd(1, M[i+1]/6/h[i]),
                pow({-xlist[i], 1}, 3));
        vd rest = add(
                mult(
                    vd(1, A[i]),
                    {-xlist[i], 1}),
                vd(1, B[i]));
        ret.push_back(add(add(rest, cubic_1), cubic_0));
    }
    return ret;
}

const double PI = atan2(1, 0)*2;

int main(){
    vd xlist = {-3,-1,0,1,3};
    vd ylist = {3,1,0,1,3};
    const int N = 4;

    vvd spline = natural_spline(xlist, ylist);
    for(int i=0;i<N;i++){
        cout << xlist[i] << " <= x <= " << xlist[i+1] << " :" << endl;
        cout << '\t' << spline[i] << endl;
    }
    cout << endl;
}
