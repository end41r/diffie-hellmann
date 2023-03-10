#include <math.h>

int is_prime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++) if (n % i == 0) return 0;

    return 1;
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int power_mod(int base, int exp, int mod)
{
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int gen_primes(int primes[1000])
{
    int i = 0;
    int j = 0;
    while (i < 1000) {
        if (is_prime(j)) {
            primes[i] = j;
            i++;
        }
        j++;
    }
}

int primitive_root(int n)
{
    int i, j, p, phi, is_primitive;
    int factors[100], num_factors = 0;

    if(!is_prime(n)) return -1;
    phi = n - 1;

    for(i = 2; i <= phi; i++) {
        if(phi % i == 0 && is_prime(i)) {
            factors[num_factors++] = i;
        }
    }

    for (i = 2; i <= n - 1; i++) {
        is_primitive = 1;
        for (j = 0; j < num_factors; j++) {
            p = factors[j];
            if (power_mod(i, phi / p, n) == 1) {
                is_primitive = 0;
                break;
            }
        }
        if (is_primitive) return i;
    }
    return -1;
}

int find_primitive_root_modulo(int n)
{
    int g;
    g = primitive_root(n);

    if (g == -1) return -1;
    else return g;

}
