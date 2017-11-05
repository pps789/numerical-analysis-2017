## Ex3-6

`ex3-6.cpp`를 컴파일 후 실행하면 다음 쪽과 같은 결과를 확인할 수 있다. Hermite Rule에서, `x=0`에서 주어진 함수는 미분 불가능하므로 이 부근에서 미분계수항을 잘 더해주어야 한다.
전체적으로 오차의 크기는 Trapezoidal > Simpson > Hermite이다. N(interval 개수)을 2배로 늘리면서 테스트했는데, Trapzoidal의 경우 오차가 4배씩 줄었고, Simson/Hermite는 16배씩 줄었다.
따라서, Trapezoidal method의 오차는 interval크기의 제곱, Simson/Hermite method의 오차는 네제곱임을 확인할 수 있다.
또한 Hermite method의 오찬츤 Simson의 약 1/4인것도 확인 가능하다. Simson n=10 case의 값이 튀는데, x=0 지점에서의 미분불가능성 때문에 그렇다.

```
Trapezoidal Rule
Case n=10:
Value of integral: 1.98352353751
Error: -0.0164764624905
Case n=20:
Value of integral: 1.99588597271
Error: -0.00411402729129
Case n=40:
Value of integral: 1.9989718105
Error: -0.00102818950293
Case n=80:
Value of integral: 1.99974297245
Error: -0.000257027554164

Simpson Rule
Case n=10:
Value of integral: 1.9669375577
Error: -0.0330624422961
Case n=20:
Value of integral: 2.00000678444
Error: 6.7844418008e-06
Case n=40:
Value of integral: 2.00000042309
Error: 4.23093182267e-07
Case n=80:
Value of integral: 2.00000002643
Error: 2.6428758737e-08

Hermite Rule
Case n=10:
Value of integral: 1.99997287818
Error: -2.71218220631e-05
Case n=20:
Value of integral: 1.99999830788
Error: -1.69212416479e-06
Case n=40:
Value of integral: 1.99999989429
Error: -1.05711154275e-07
Case n=80:
Value of integral: 1.99999999339
Error: -6.60621934934e-09
```
