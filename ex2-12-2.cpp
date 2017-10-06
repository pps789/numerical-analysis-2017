#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<double> vd;
typedef pair<double,double> pdd;

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

vd newton_difference(const vector<pdd>& points){
    const int N = points.size();
    vector<double> ret(N);

    for(int i=0;i<N;i++) ret[i] = points[i].second; // initialize
    
    for(int i=1;i<N;i++) for(int j=N-1;j>=i;j--){
        // phi(x_0, ..., x_i-1, x_j)
        ret[j] = (ret[j] - ret[j-1]) / (points[j].first - points[j-i].first);
    }
    return ret;
}

vd newton(const vector<pdd>& points, const vd& nt_diff, int index = 0){
    if(nt_diff.size() == index + 1)
        return {nt_diff[index]};
    vd term = {-points[index].first, 1};
    return add({nt_diff[index]}, mult(term, newton(points, nt_diff, index+1)));
}

ostream& operator<<(ostream& out, const vd& poly){
    out << "(" << poly[0] << ")";
    for(int i=1;i<poly.size();i++){
        cout << "+(" << poly[i] << ")x";
        if(i>1) out << "^" << i;
    }
    return out;
}

int main(){
    cout << "Type number of points: ";
    int N; cin >> N;

    vector<pdd> points;
    for(int i=1;i<=N;i++){
        cout << "Type x-value of " << i << "th point: ";
        double x; cin >> x;

        cout << "Type y-value of " << i << "th point: ";
        double y; cin >> y;

        points.push_back({x,y});
    }

    auto poly = newton(points, newton_difference(points));
    cout << "Result:" << endl;
    cout << poly << endl;
}
