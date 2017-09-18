#include<cstdio>
#include<cfloat>
#include<cmath>
using namespace std;

int main(){
    printf("min_expo of double precision: %d\n", DBL_MIN_EXP-1); // -1022
    printf("smallest positive value of double precision: %.16e\n", pow(2, -1022));
    printf("largest negative value of double precision: %.16e\n", -pow(2, -1022));
    printf("DBL_MIN value in header <cfloat>: %.16e\n", DBL_MIN);

    printf("min_expo of quadruple precision: %d\n", LDBL_MIN_EXP-1); // -16382
    printf("smallest positive value of quadruple precision: %.33Le\n", pow(2.L, -16382));
    printf("largest negative value of quadruple precision: %.33Le\n", -pow(2.L, -16382));
    printf("LDBL_MIN value in header <cfloat>: %.33Le\n", LDBL_MIN);
}
