#include<cstdio>
#include<cmath>
#include<cfloat>
using namespace std;

int main(){
    const long double GAMMA = .577215664901532860606512090082L;
    const long long N = 1e10;

    int step = 0;
    for(long long i=1;i<=N;i*=10,step++){
        long double lower_sum = 0, upper_sum = 0;
        for(long long j=1;j<=i;j++) upper_sum += 1./j;
        for(long long j=i;j>=1;j--) lower_sum += 1./j;
        long double lgn = log((long double)i);
        printf("step 10^%d: standasrd order error %.16Le, reverse order error %.16Le\n",
                step, GAMMA - upper_sum + lgn, GAMMA - lower_sum + lgn);
    }
}
