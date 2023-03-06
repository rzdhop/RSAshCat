#include <stdio.h>
#include <stdlib.h>
#include "Factorisation.h"
#include "../_GlobalDefine.h"

int main() {
    unsigned long long int n = 187; 
    unsigned long long *results = (unsigned long long*)malloc(2*sizeof(unsigned long long));

    fermat_factorisation(results, n);

    printf("\n%llu = %llu * %llu\n", n, results[0], results[1]);

    free(results);

    return 0;
}
