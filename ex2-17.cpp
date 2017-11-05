#include<complex>
#include<iostream>
#include<algorithm>
using namespace std;

typedef complex<double> cd;
typedef vector<double> vd;

double f(double x){return pow(sin(x), 5);}
const double PI = atan2(1, 0)*2;

cd fourier_navie(int j, int N){
    // returns jth fourier coeff.
    cd ret(0,0);
    for(int k=0;k<N;k++){
        double x = 2*PI*k/N;
        ret += f(x) * cd(cos(-j*x), sin(-j*x));
    }
    return ret/(double)N;
}

vector<cd> fourier_navie(int N){
    vector<cd> ret;
    for(int i=0;i<N;i++) ret.push_back(fourier_navie(i, N));
    return ret;
}

void FFT(vector<cd>& A){
    const int N = A.size();
    if(N==1) return;

    vector<cd> even(N>>1), odd(N>>1);
    for(int i=0;i<(N>>1);i++)
        even[i] = A[i*2], odd[i] = A[i*2+1];
    FFT(even); FFT(odd);

    double theta = -2*PI/N;
    cd w = 1;

    for(int i=0;i<(N>>1);i++){
        A[i] = even[i] + w * odd[i];
        A[i+(N>>1)] = even[i] - w * odd[i];
        w *= cd(cos(theta), sin(theta));
    }
    for(int i=0;i<N;i++) A[i] /= 2;
}

vector<cd> FFT(int N){
    vector<cd> A;
    for(int i=0;i<N;i++) A.push_back(f(2*PI*i/N));
    FFT(A);
    return A;
}

/*
void chk(const vector<cd>& v, int N){
    for(int i=0;i<N;i++){
        double x = 2*PI*i/N;
        cd cur(0,0);
        for(int j=0;j<N;j++)
            cur += v[j] * cd(cos(j*x), sin(j*x));
        double optimal = f(x);
        cout << cur << " " << optimal << endl;
    }
}
*/

int main(){
    int N; scanf("%d",&N);
    auto naive = fourier_navie(1<<N), fast = FFT(1<<N);
    
    cout << "Naive method" << "\t\t" << "FFT" << endl;

    for(int i=0;i<(1<<N);i++){
        cout << naive[i] << "\t\t" << fast[i] << endl;
    }
}
