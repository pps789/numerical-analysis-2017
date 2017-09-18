## Ex1-1
```
min_expo of double precision: -1022
smallest positive value of double precision: 2.2250738585072014e-308
largest negative value of double precision: -2.2250738585072014e-308
DBL_MIN value in header <cfloat>: 2.2250738585072014e-308
min_expo of quadruple precision: -16382
smallest positive value of quadruple precision: 3.362103143112093506262677817321753e-4932
largest negative value of quadruple precision: -3.362103143112093506262677817321753e-4932
LDBL_MIN value in header <cfloat>: 3.362103143112093506262677817321753e-4932
```

## Ex1-4
작은 수 부터 먼저 더해야 오차가 작음을 확인할 수 있다.
```
n: 10000
Exact S_n: 9.9990000999900015e-05
Sum from largest value: 9.9990000999900042e-01
Error: 9.9980001999800050e-01
Relative error: 9.9990000000000018e+03
Sum from smallest value: 9.9990000999900008e-01
Error: 9.9980001999800017e-01
Relative error: 9.9990000000000000e+03

n: 20000
Exact S_n: 4.9997500124993749e-05
Sum from largest value: 9.9995000249987676e-01
Error: 9.9990000499975173e-01
Relative error: 1.9999000000000036e+04
Sum from smallest value: 9.9995000249987509e-01
Error: 9.9990000499975007e-01
Relative error: 1.9999000000000000e+04

n: 30000
Exact S_n: 3.3332222259258028e-05
Sum from largest value: 9.9996666777774268e-01
Error: 9.9993333555548347e-01
Relative error: 2.9999000000000058e+04
Sum from smallest value: 9.9996666777774079e-01
Error: 9.9993333555548158e-01
Relative error: 2.9999000000000000e+04

n: 40000
Exact S_n: 2.4999375015624608e-05
Sum from largest value: 9.9997500062499034e-01
Error: 9.9995000124997468e-01
Relative error: 3.9999000000000240e+04
Sum from smallest value: 9.9997500062498434e-01
Error: 9.9995000124996869e-01
Relative error: 3.9999000000000000e+04

n: 50000
Exact S_n: 1.9999600007999841e-05
Sum from largest value: 9.9998000039999790e-01
Error: 9.9996000079998992e-01
Relative error: 4.9999000000000291e+04
Sum from smallest value: 9.9998000039999202e-01
Error: 9.9996000079998404e-01
Relative error: 4.9999000000000000e+04

n: 60000
Exact S_n: 1.6666388893518441e-05
Sum from largest value: 9.9998333361111358e-01
Error: 9.9996666722222005e-01
Relative error: 5.9999000000000422e+04
Sum from smallest value: 9.9998333361110647e-01
Error: 9.9996666722221295e-01
Relative error: 5.9999000000000000e+04

n: 70000
Exact S_n: 1.4285510206997042e-05
Sum from largest value: 9.9998571448980589e-01
Error: 9.9997142897959890e-01
Relative error: 6.9999000000000902e+04
Sum from smallest value: 9.9998571448979301e-01
Error: 9.9997142897958602e-01
Relative error: 6.9999000000000000e+04

n: 80000
Exact S_n: 1.2499843751953100e-05
Sum from largest value: 9.9998750015626170e-01
Error: 9.9997500031250974e-01
Relative error: 7.9999000000001091e+04
Sum from smallest value: 9.9998750015624804e-01
Error: 9.9997500031249609e-01
Relative error: 7.9999000000000000e+04

n: 90000
Exact S_n: 1.1110987655692714e-05
Sum from largest value: 9.9998888901236027e-01
Error: 9.9997777802470456e-01
Relative error: 8.9999000000001441e+04
Sum from smallest value: 9.9998888901234428e-01
Error: 9.9997777802468857e-01
Relative error: 8.9999000000000000e+04

n: 100000
Exact S_n: 9.9999000009999908e-06
Sum from largest value: 9.9999000010001171e-01
Error: 9.9998000020001077e-01
Relative error: 9.9999000000001266e+04
Sum from smallest value: 9.9999000009999905e-01
Error: 9.9998000019999811e-01
Relative error: 9.9999000000000000e+04
```

## Ex1-5
```
step 10^0:
standard order error -4.2278433509846714e-01
reverse order error -4.2278433509846714e-01
step 10^1:
standard order error -4.9167496072675398e-02
reverse order error -4.9167496072675398e-02
step 10^2:
standard order error -4.9916667499959842e-03
reverse order error -4.9916667499959842e-03
step 10^3:
standard order error -4.9991666667494918e-04
reverse order error -4.9991666667494831e-04
step 10^4:
standard order error -4.9999166666594812e-05
reverse order error -4.9999166666608690e-05
step 10^5:
standard order error -4.9999916664289837e-06
reverse order error -4.9999916666189359e-06
step 10^6:
standard order error -4.9999991604335325e-07
reverse order error -4.9999991658892379e-07
step 10^7:
standard order error -4.9999998110589194e-08
reverse order error -4.9999999076830171e-08
step 10^8:
standard order error -5.0000068130967579e-09
reverse order error -4.9999996469540786e-09
step 10^9:
standard order error -5.0000049760245968e-10
reverse order error -5.0000023739393828e-10
```
d=1, c=-0.5정도로 계산할 수 있다.

## Ex1-6
```
error without extra: -5.0000023712288774e-10
error with extra: -2.3738606566570120e-16
gamma with extra term is better
```
문제의 부등식에 대한 증명은 사진으로 대체한다.
