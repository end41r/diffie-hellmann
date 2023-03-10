#include "diffy-hellmann.h"
#include "stdlib.h"
#include "stdio.h"

int main()
{
    int primes[1000];
    gen_primes(primes);

    int p = primes[rand() % 1000];
    while(!is_prime(p / 2 - 1))
    {
        p = primes[rand() % 1000];
    }
    int g = find_primitive_root_modulo(p);

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int A = power_mod(g, a, p);
    int B = power_mod(g, b, p);

    int secretA = power_mod(B, a, p);
    int secretB = power_mod(A, b, p);

    if (secretA == secretB) 
    {
        printf("Secrets are equal: %d", secretA);
        return 1;
    }
    printf("Secrets are not equal: %d | %d", secretA, secretB);
    return 0;
}
