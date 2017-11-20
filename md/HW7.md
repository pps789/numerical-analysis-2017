## Ex3-9

정확한 적분 값을 사용하기 위해 `e^t sin(e^t)`를 적분했다.
`ex3-9.cpp`를 컴파일 후 실행한 결과는 다음과 같다.
(a,b)=(0,2), N=1일 때 값이 튀는 이유는 적분 근사 단위가 1보다 크기 때문이다.

```
Integrate e^x * sin(e^x) using Euler-Maclaruin summation formula

==========
Integrate from 0 to 1
Exact value: 1.45203622066

N=1 and m=1
Approx. value: 1.56254573587
Error: 0.110509515212

N=1 and m=2
Approx. value: 1.50032156573
Error: 0.0482853450788

N=1 and m=3
Approx. value: 1.40402199875
Error: -0.0480142219054

N=10 and m=1
Approx. value: 1.45204253909
Error: 6.31843584764e-06

N=10 and m=2
Approx. value: 1.45203631667
Error: 9.60188342169e-08

N=10 and m=3
Approx. value: 1.45203622037
Error: -2.80732770364e-10

==========
Integrate from -1 to 1
Exact value: 1.84482599039

N=1 and m=1
Approx. value: 3.20852834175
Error: 1.36370235136

N=1 and m=2
Approx. value: 2.17166863428
Error: 0.326842643896

N=1 and m=3
Approx. value: -3.81909699965
Error: -5.66392299004

N=10 and m=1
Approx. value: 1.84493558952
Error: 0.000109599137752

N=10 and m=2
Approx. value: 1.84483190355
Error: 5.91316700538e-06

N=10 and m=3
Approx. value: 1.84482591279
Error: -7.75986286339e-08

==========
Integrate from 0 to 2
Exact value: 0.0919460640494

N=1 and m=1
Approx. value: -2.45458210057
Error: -2.54652816462

N=1 and m=2
Approx. value: -76.2600452381
Error: -76.3519913021

N=1 and m=3
Approx. value: -604.970180593
Error: -605.062126657

N=10 and m=1
Approx. value: 0.099839273876
Error: 0.00789320982662

N=10 and m=2
Approx. value: 0.0924587275623
Error: 0.000512663512872

N=10 and m=3
Approx. value: 0.0919300174269
Error: -1.60466224833e-05
```

## Ex3-15

`ex3-15.cpp`를 컴파일 후 실행하면 다음과 같은 적분 결과와 오차를 확인할 수 있다.
두 번째 적분의 경우, 9차 다항식이므로 5-point case에서 정확해야 한다.
실행 결과를 참고하면, C++의 `double`형의 유효숫자(15~16개)를 감안했을 때 정확하다고 할 수 있다.

```
==========
Integrate f(x) = e^x from 0 to 1
Exact value: 1.71828182846

Number of points: 1
Approx. value: 1.6487212707
Error: -0.0695605577589

Number of points: 2
Approx. value: 1.71789637801
Error: -0.000385450451541

Number of points: 3
Approx. value: 1.71828100437
Error: -8.24086523021e-07

Number of points: 4
Approx. value: 1.71828182753
Error: -9.32967259004e-10

Number of points: 5
Approx. value: 1.71828182846
Error: -6.53477272294e-13

==========
Integrate f(x) = 1 + 3x^5 + 5x^9 from 0 to 1
Exact value: 2

Number of points: 1
Approx. value: 1.103515625
Error: -0.896484375

Number of points: 2
Approx. value: 1.75347222222
Error: -0.246527777778

Number of points: 3
Approx. value: 1.9778125
Error: -0.0221875

Number of points: 4
Approx. value: 1.99948979592
Error: -0.000510204081633

Number of points: 5
Approx. value: 2
Error: -4.4408920985e-16
```

## Ex3-17

`ex3-17.cpp`를 컴파일 후 실행하면 무작위의 7차 다항식을 적분한다.
역시 `double` 자료형의 유효숫자(15~16개)를 감안했을 때 항상 정확한 값을 근사해냄을 알 수 있다.
다음은 출력 결과들 중 하나이다.

```
Integrate random polynomial (degree 7), random range using GLL rule
Integrate function: (7)+(18)x+(17)x^2+(19)x^3+(19)x^4+(9)x^5+(9)x^6+(12)x^7
Integrate range: from 0 to 5
Exact value: 725633.511905
Approx. value: 725633.511905
Relative error: -3.20865340195e-16
```
