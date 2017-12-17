## Ex4-14

Gauss-Jordan 소거법 등을 이용하여, Ba=y 의 solution을 계산하면 된다.
`ex4-14.cpp`를 컴파일 후 실행하면 결과를 확인할 수 있다.

```
Least square approximation:
(0.161129568106)+(2.45182724252)x+(-0.333887043189)x^2
```

## Ex4-15

모든 parameter를 1로 두고 계산했다.
`f1 = f2 = 0`의 solution을 구했다.
Steepest Descent Method를 사용할 땐 `f = f1^2 + f2^2`의 최솟값을 구하는 것으로 대체했다.
Steepest Descent Method는 초기값에 매우 민감함을 알 수 있었다.

`ex4-15.cpp`를 컴파일 후 실행하면 그 결과를 확인할 수 있다.

```
PARAMETERS
m: 1
lambda: 1
a: 1
b: 1
mu: 1
d: 1
c: 1

INITIAL VALUES
(1, 1)

Newton Method Error: 0.707106781187
Newton Method Error: 0.237065391823
Newton Method Error: 0.029680342291
Newton Method Error: 0.00108014258234
Newton Method Error: 2.93869816244e-06
Newton Method Error: 3.28988068596e-11
Newton Method Result: (1.20556943043, 0.453397651581)

Steepest Descent Method Err: 2.06155281281
Steepest Descent Method Err: 0.0325463059825
Steepest Descent Method Err: 0.0242519958277
Steepest Descent Method Err: 0.0308335191903
Steepest Descent Method Err: 0.0224148113069
Steepest Descent Method Err: 0.0269928798794
Steepest Descent Method Err: 0.0191694743117
Steepest Descent Method Err: 0.0219855357877
Steepest Descent Method Err: 0.0153006442011
Steepest Descent Method Err: 0.0168553053644
Steepest Descent Method Err: 0.0115413228628
Steepest Descent Method Err: 0.0123245512844
Steepest Descent Method Err: 0.00833602639883
Steepest Descent Method Err: 0.00870081551226
Steepest Descent Method Err: 0.00583305879833
Steepest Descent Method Err: 0.00599080118701
Steepest Descent Method Err: 0.00399141681295
Steepest Descent Method Err: 0.00405398989387
Steepest Descent Method Err: 0.00268956547327
Steepest Descent Method Err: 0.00271122405155
Steepest Descent Method Err: 0.0017935924164
Steepest Descent Method Err: 0.00179894459637
Steepest Descent Method Err: 0.00118781505819
Steepest Descent Method Err: 0.00118738075035
Steepest Descent Method Err: 0.000783020704747
Steepest Descent Method Err: 0.000781007807691
Steepest Descent Method Err: 0.000514609209247
Steepest Descent Method Err: 0.000512541244672
Steepest Descent Method Err: 0.000337531047353
Steepest Descent Method Err: 0.000335854339998
Steepest Descent Method Err: 0.000221095680718
Steepest Descent Method Err: 0.000219859981435
Steepest Descent Method Err: 0.000144701673007
Steepest Descent Method Err: 0.000143840879223
Steepest Descent Method Err: 9.46466671956e-05
Steepest Descent Method Err: 9.4063510067e-05
Steepest Descent Method Err: 6.18836449536e-05
Steepest Descent Method Err: 6.14937505394e-05
Steepest Descent Method Err: 4.04585193355e-05
Steepest Descent Method Err: 4.01856436707e-05
Steepest Descent Method Err: 2.6447736532e-05
Steepest Descent Method Err: 2.62616901132e-05
Steepest Descent Method Err: 1.72874398531e-05
Steepest Descent Method Err: 1.71625585571e-05
Steepest Descent Method Err: 1.12992360685e-05
Steepest Descent Method Err: 1.12162151059e-05
Steepest Descent Method Err: 7.38502449626e-06
Steepest Descent Method Err: 7.33016646752e-06
Steepest Descent Method Err: 4.8266370056e-06
Steepest Descent Method Err: 4.79052858822e-06
Steepest Descent Method Err: 3.15450118785e-06
Steepest Descent Method Err: 3.13079331949e-06
Steepest Descent Method Err: 2.06163800498e-06
Steepest Descent Method Err: 2.04609714943e-06
Steepest Descent Method Err: 1.34738370462e-06
Steepest Descent Method Err: 1.337207129e-06
Steepest Descent Method Err: 8.80578982392e-07
Steepest Descent Method Result: (1.20556887007, 0.453396051286)
```

## Ex6-4

`f(t, u) = 2 + 2u + t + tu`, `u(0)=1`, `0<=t<=1`의 ODE를 계산했다.
위 식의 정확한 해는 `u(t) = 2*exp(t*(t+4)/2) - 1`이다.
R = 2, 3, 4에 대해, (Number of Steps) = 10, 100, 1000, 10000에 대해 계산했다.
R > 2일 때의 초기값들은, 더 작은 R을 이용해서 근사했다. 예를 들어, R=3인 경우 초기값이 2개 필요한데, u(t1)은 R=2의 방법을 이용하여 근사했다.
R이 클수록, 조금 더 빨리 수렴함을 알 수 있다.

`ex6-4.cpp`를 컴파일 후 실행하면 그 결과를 확인할 수 있다.

```
Solve f(t, u) = 2 + 2u + t + tu, 0<=t<=1, u(0) = 1
Exact solution of t=1: 23.3649879214
==========
R=2
==========
N=10
Solution: 21.1443141015
Absolute Error: -2.22067381991
Relative Error: 0.0950427976844
N=100
Solution: 23.3354678571
Absolute Error: -0.0295200643509
Relative Error: 0.00126343161187
N=1000
Solution: 23.3646865532
Absolute Error: -0.000301368240645
Relative Error: 1.28982836053e-05
N=10000
Solution: 23.3649849018
Absolute Error: -3.01959111226e-06
Relative Error: 1.29235723229e-07
N=100000
Solution: 23.3649878912
Absolute Error: -3.02090761295e-08
Relative Error: 1.29292068248e-09


==========
R=3
==========
N=10
Solution: 22.2466772023
Absolute Error: -1.11831071913
Relative Error: 0.0478626705431
N=100
Solution: 23.3580863824
Absolute Error: -0.0069015389949
Relative Error: 0.000295379523333
N=1000
Solution: 23.3649261652
Absolute Error: -6.17561938014e-05
Relative Error: 2.64310831271e-06
N=10000
Solution: 23.3649873114
Absolute Error: -6.09972797605e-07
Relative Error: 2.61062748954e-08
N=100000
Solution: 23.3649879153
Absolute Error: -6.10068084939e-09
Relative Error: 2.61103531057e-10


==========
R=4
==========
N=10
Solution: 22.5115915297
Absolute Error: -0.853396391714
Relative Error: 0.0365245809065
N=100
Solution: 23.358739931
Absolute Error: -0.00624799043264
Relative Error: 0.000267408245776
N=1000
Solution: 23.3649268734
Absolute Error: -6.10480033423e-05
Relative Error: 2.61279841221e-06
N=10000
Solution: 23.3649873121
Absolute Error: -6.09258567152e-07
Relative Error: 2.60757064888e-08
N=100000
Solution: 23.3649879153
Absolute Error: -6.09855632661e-09
Relative Error: 2.61012603436e-10
```
