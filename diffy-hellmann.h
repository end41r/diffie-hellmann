#ifndef DIFFY_HELLMANN__H
#define DIFFY_HELLMANN__H

#include <math.h>

// init prime numbers list (could later change to a fixed list of primes)
int gen_primes(int primes[1000]);

// helpers for primitive root
int is_prime(int n);
int gcd(int a, int b);
int power_mod(int base, int exp, int mod);

int primitive_root(int n);
int find_primitive_root_modulo(int n);

#endif // DIFFY_HELLMANN__H
