#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    const long double GAMMA = .577215664901532860606512090082L;
    const int N = 1e9;

    long double sum = 0, lgn = log((long double)N);
    long double extra = 1.L/252/N/N/N/N/N/N - 1.L/120/N/N/N/N + 1.L/12/N/N - 1.L/2/N;
    for(int i=N;i>=1;i--) sum += 1./i;

    long double gamma_n = sum + extra - lgn;
    long double gamma_n_noex = sum - lgn;

    long double error = GAMMA - gamma_n_noex, error_new = GAMMA - gamma_n;
    printf("error without extra: %.16Le\n", error);
    printf("error with extra: %.16Le\n", error_new);
    if(fabs(error) > fabs(error_new))
        printf("gamma with extra term is better\n");
    else printf("gamma without extra term is better\n");
}
