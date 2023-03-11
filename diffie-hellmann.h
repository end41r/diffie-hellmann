#ifndef DIFFIE_HELLMANN__H
#define DIFFIE_HELLMANN__H

#include <math.h>

// init prime numbers list (could later change to a txt with a fixed set of primes)
int gen_primes(int primes[1000]);
int print_primes();

// helpers for primitive root
int is_prime(int n);
int gcd(int a, int b);
int power_mod(int base, int exp, int mod);

int primitive_root(int n);
int find_primitive_root_modulo(int n);

#endif // DIFFIE_HELLMANN__H
