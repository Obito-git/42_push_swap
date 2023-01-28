# push_swap
[Subject](https://cdn.intra.42.fr/pdf/pdf/69290/en.subject.pdf)

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## Result

Success: 88/100

## Installation

Makefile:

```bash
  make
```

if you use zsh you need to go to the bash:
```bash
bash
```

Testing command:
```
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | wc -l 
```

This command will generate 100 random numbers and will count the number of operations.

> For 100 numbers:
> less 700 - super, 
> less 900 - good, 
> less 1100 - medium, 
> less 1300 - bad, 
> less 1500 - very bad.

My result is ~750

> For 500 numbers:
> less 5500 - super, 
> less 7000: good, 
> less 8500: medium, 
> less 10000: bad, 
> less 11500: very bad.

My result is ~6900
