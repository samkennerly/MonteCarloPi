# picasino

A [Monte Carlo simulation].

<img alt="Le Chiffre" src="picasino.jpeg" title="You must have thought I was bluffing.">

[Monte Carlo simulation]: https://en.wikipedia.org/wiki/Monte_Carlo_method

## abstract

Draw a [unit circle]. Its area is π(1)<sup>2</sup> = π.

Draw a square which barely contains the circle. Its area is (1 + 1)<sup>2</sup> = 4.

Choose a random point uniformly distributed on the square.
The probability it is inside the circle is π/4.

Choose 100,000,000 random points the same way.
If *n* points are in the circle, then π ≈ 400,000,000 * *n*.

[unit circle]: https://en.wikipedia.org/wiki/Unit_circle

## basics

Run `make` to compile the program.

## commands

Estimate π. (Needs user input.)
```
bin/picasino
```

## dependencies

1. `g++` from the [GNU Compiler Collection](https://gcc.gnu.org/)
1. [make](https://en.wikipedia.org/wiki/Make_%27software%28)

## examples

```sh
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
