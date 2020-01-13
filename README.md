# picasino

An absurdly simple [Monte Carlo] simulation in C++.

<img alt="Le Chiffre" src="picasino.jpeg" title="You must have thought I was bluffing.">

[Monte Carlo]: https://en.wikipedia.org/wiki/Monte_Carlo_method

## abstract

Draw a unit circle. Draw a square which just barely contains the circle.

Choose a random point uniformly distributed on the square.
The probability it is inside the circle is π/4.

Choose 100,000,000 random points the same way.
If *n* points are inside the circle, then π/4 ≈ n/100,000,000.

## basics

Run `make` to compile the program.

## commands

Estimate pi. (Needs user input.)
```
bin/picasino
```

## dependencies

1. `g++` from the [GNU Compiler Collection](https://gcc.gnu.org/)

## examples

```
> bin/picasino

How many million darts should we throw? 100
Throwing darts...
78540008 hits out of 100000000 tosses.
Estimated value of pi is 3.14160032
Error is 7.666410207e-06
```

## faq

### Is this a good way to calculate π?

Not really.
