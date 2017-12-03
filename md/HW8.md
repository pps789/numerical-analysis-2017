## Ex4-2

`ex4-2.cpp`를 컴파일 후 실행하면, 주어진 방정식을 newton, regula falsi, secand method를 이용해 푼 결과를 보여준다.
각각의 method들의 수렴할 때 까지의 반복 횟수와, order의 근사치를 보여준다.
order의 근사치는 n번 째 iteraton의 error를 e\_n이라 할 때, ln(e\_n/e\_(n-1)) / ln(e\_(n-1)/e\_(n-2)) 로 근사할 수 있다.

```
Number of iteration: 7
Solution using Newton method: -4.37336040792839e-17
Guessing order: 1.33968711800535
Number of iteration: 50
Solution using Regula Falsi method: -6.02081826639108e-16
Guessing order: 1.07577612323703
Number of iteration: 9
Solution using Secant method: 7.41113667320361e-19
Guessing order: 1.06753175264708
```

실제 order는 각각 2, 1, 1.68이어야 하지만, 적은 횟수로도 수렴하여 위와 같은 오차가 발생했다.

## Ex4-5

`ex4-5.cpp`를 컴파일 후 실행하면, 각각의 iteration마다의 guessed solution과 order를 출력한다.
method는 `Ex4-4`에 나온 식을 사용했다. order가 약 2임을 쉽게 확인할 수 있다.

```
Current guess: 0.593001745200698
Current guess: 0.501698276388483, Guessing order: 1.94280400053366
Current guess: 0.500000576632682, Guessing order: 1.99548092413864
Number of iteration: 4
Solution using Newton method: 0.500000576632682
```

## Ex4-8

`ex4-8.cpp`를 컴파일 후 실행하면, 해당하는 method들을 이용해 방정식을 푼 결과를 확인할 수 있다.

```
Number of iteration: 32
Solution using Fixed Point method: 1.62763968277
Number of iteration: 39
Solution using Bisection method: 1.62763968277
Number of iteration: 25
Solution using Regula Falsi method: 1.62763968277
```

## Ex4-9

`ex4-9.cpp`를 컴파일 후 실행하면, 세 개의 방정식을 각각의 방법으로 푼 결과를 확인할 수 있다.
가능한 경우, 모든 방정식에 대해 order를 전부(여러번 씩) 근사해 보았다.
각각의 방정식에 대해 Improved newton method로 다 풀고, muller method로 다시 한 번 풀었다.

```
Number of iteration: 3
Solution using Improved Newton method: -1.07723532649e-17
Guessing order: inf
Number of iteration: 1
Solution using Improved Newton method: 1.61803398875
Number of iteration: 16
Solution using Improved Newton method: 1.83928675521
Guessing order: inf
Guessing order: 1.06510893586
Guessing order: 1.00927668492
Guessing order: 1.00141539353
Guessing order: 1.00021912815
Guessing order: 1.00003366552
Guessing order: 1.00000523203
Guessing order: 1.00000084386
Guessing order: 1.00000034414
Guessing order: 1.00000143284
Guessing order: 1.00000914086
Guessing order: 1.00005873733
Guessing order: 1.00036381322
Guessing order: 1.00167844472
Number of iteration: 6
Solution using Muller method: -1.04880578893e-15
Guessing order: inf
Guessing order: 1.94349562915
Guessing order: 1.74627013688
Guessing order: 1.66475003332
Number of iteration: 1
Solution using Muller method: 1.61803398875
Number of iteration: 5
Solution using Muller method: 1.83928675521
Guessing order: inf
Guessing order: 1.74242991735
Guessing order: 1.71224272463
```

## Ex4-13

`ex4-13.cpp`를 컴파일 후 실행하면, 주어진 방정식의 근을 전부 출력한다. (real, img) 꼴의 복소수이다.

```
Zeros:
(-0.770838640961,0.258065184735)
(-0.770838640961,-0.258065184735)
(-0.765153705012,0.789333286036)
(-0.765153705012,-0.789333286036)
(-0.0984371742603,0.944937048863)
(-0.0984371742603,-0.944937048863)
(0.672633353277,-0.901536113719)
(0.672633353277,0.901536113719)
(0.961796166956,-0.414139720396)
(0.961796166956,0.414139720396)

```
