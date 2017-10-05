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

vd inverse_difference(const vector<pdd>& points){
    const int N = points.size();
    vector<double> ret(N);

    for(int i=0;i<N;i++) ret[i] = points[i].second; // initialize
    
    for(int i=1;i<N;i++) for(int j=N-1;j>=i;j--){
        // phi(x_0, ..., x_i-1, x_j)
        ret[j] = (points[j].first - points[i-1].first) / (ret[j] - ret[i-1]);
    }
    return ret;
}

pair<vd,vd> thiele(const vector<pdd>& points, const vd& inv_diff, int index = 0){
    if(inv_diff.size() == index + 1)
        return pair<vd,vd>(vd(1, inv_diff[index]), vd(1, 1));
    auto pq = thiele(points, inv_diff, index+1);
    auto p = pq.first, q = pq.second;
    vd term = {-points[index].first, 1};
    return pair<vd,vd>(
            add(mult(p, vd(1, inv_diff[index])), mult(q, term)),
            p
            );
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

    auto pq = thiele(points, inverse_difference(points));
    cout << "Result:" << endl;
    cout << "(" << pq.first << ")/(" << pq.second << ")" << endl;
}
