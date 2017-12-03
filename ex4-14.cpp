#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

vector<double> gaussJordan(
        vector<vector<double>> A,
        vector<double> b
        ){
    const int N = A.size();
    vector<int> origin(N);
    for(int i=0;i<N;i++) origin[i] = i;
    for(int i=0;i<N;i++){
        int pivot;
        
        // find pivot
        for(int j=i;j<N;j++){
            if(A[j][i] != 0){
                pivot = j; break;
            }
        }

        swap(A[i], A[pivot]); swap(b[i], b[pivot]); swap(origin[i], origin[pivot]);

        for(int j=i+1;j<N;j++){
            double w = A[j][i] / A[i][i];
            for(int k=i;k<N;k++) A[j][k] -= w * A[i][k];
            b[j] -= w * b[i];
        }
    }

    vector<double> ret(N);
    for(int i=N-1;i>=0;i--){
        ret[origin[i]] = b[i];
        for(int j=i+1;j<N;j++)
            ret[origin[i]] -= ret[origin[j]] * A[i][j];
        ret[origin[i]] /= A[i][i];
    }
    return ret;
}

ostream& operator<<(ostream& out, const vector<double>& poly){
    out << "(" << poly[0] << ")";
    for(int i=1;i<poly.size();i++){
        cout << "+(" << poly[i] << ")x";
        if(i>1) out << "^" << i;
    }
    return out;
}

pair<double,double> data[] = {
    {0,1},
    {1,2},
    {1,1},
    {2,4},
    {4,6},
    {5,3},
    {6,3}
};

int main(){
    cout << setprecision(12);
    vector<vector<double>> A(3, vector<double>(3));
    vector<double> b(3);
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(auto xy:data){
        A[i][j] += pow(xy.first, i)*pow(xy.first, j);
    }

    for(int i=0;i<3;i++) for(auto xy:data){
        b[i] += xy.second*pow(xy.first, i);
    }

    cout << "Least square approximation:" << endl;
    auto ret = gaussJordan(A, b);
    cout << ret << endl;
}
