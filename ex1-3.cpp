#include<cstdio>
using namespace std;

int main(){
    for(int i=10000;i<=100000;i+=10000){
        double S_real = 1. / (i+1);
        double upper_sum = 0, lower_sum = 0;
        for(int j=1;j<=i;j++) upper_sum += 1./j - 1./(j+1);
        for(int j=i;j>=1;j--) lower_sum += 1./j - 1./(j+1);
        printf("n: %d\n", i);
        printf("Exact S_n: %.16e\n", S_real);
        printf("Sum from largest value: %.16e\n", upper_sum);
        printf("Error: %.16e\n", upper_sum - S_real);
        printf("Relative error: %.16e\n", (upper_sum - S_real)/S_real);
        printf("Sum from smallest value: %.16e\n", lower_sum);
        printf("Error: %.16e\n", lower_sum - S_real);
        printf("Relative error: %.16e\n", (lower_sum - S_real)/S_real);
        printf("\n");
    }
}
