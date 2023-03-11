#include "diffie_hellmann.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

int main()
{
    srand(time(NULL)); // seed rand()

    int primes[1000];
    gen_primes(primes);
//  print_primes();

    int p = primes[rand() % 1000];
    while(!is_prime(p / 2 - 1))
    {
        p = primes[rand() % 1000];
    }
    printf("p: %d\n", p);

    int g = find_primitive_root_modulo(p);
    printf("g: %d\n", g);

    int a = rand();
    int b = rand();
    printf("a: %d\n", a);
    printf("b: %d\n", b);

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
