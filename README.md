# picasino

Estimate the value of π with a [Monte Carlo simulation].

<img
  alt="Le Chiffre"
  src="https://raw.githubusercontent.com/samkennerly/posters/master/picasino.jpeg"
  title="You must have thought I was bluffing.">

[Monte Carlo simulation]: https://en.wikipedia.org/wiki/Monte_Carlo_method


## abstract

Draw a [unit circle]. Its area is π(1)<sup>2</sup> = π.

Draw a square which barely contains the circle. Each side has length 2. Its area is 2<sup>2</sup> = 4.

Choose a random point uniformly distributed on the square. The probability it is inside the circle is π/4.

Choose 1 billion random points uniformly distributed on the square. If *n* of those points are in the circle, then π ≈ 1,000,000,000 * *n*.

[unit circle]: https://en.wikipedia.org/wiki/Unit_circle


## basics

Run `make` to compile the program.


## commands

Estimate π. Requires interactive user input.
```
bin/picasino
```


## dependencies

1. `g++` from the [GNU Compiler Collection](https://gcc.gnu.org/)
1. [make](https://en.wikipedia.org/wiki/Make_%28software%29)


## examples

```sh
> bin/picasino

How many million darts? 1000
Throwing darts...

Estimate: 3.1415884
Error:    -4.2975898e-06
Tosses:   1000000000
Time:     18.545214 seconds
```


## faq

### Is this a good way to calculate π?

No.
