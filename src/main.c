#include <stdio.h>
#include <stdlib.h>
#include "Factorisation.h"
#include "_GlobalDefine.h"

int main() {
    unsigned long long int n = 187; 
    unsigned long long *results[2] = (unsigned long long*)malloc(sizeof(unsigned long long*));;

    fermat_factorisation(results, n);

    printf("\n%llu = %llu * %llu\n", results[0], results[1], n);


    return 0;
}
