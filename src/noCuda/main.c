#include <stdio.h>
#include <stdlib.h>
#include "Factorisation.h"
#include "../_GlobalDefine.h"

int main() {

    printf(" ____________________________________________");
	printf("|           RSAshCat v1.0		           |");
	printf("|____________________________________________|");
    
    unsigned long long int *n = (unsigned long long int*)malloc(sizeof(unsigned long long int)); 
    unsigned int *e = (unsigned int*)malloc(sizeof(unsigned int));
    unsigned long long int *results = (unsigned long long int*)malloc(2*sizeof(unsigned long long int));

    *n = 41725382548836457;
    *e = 65537;
    //extract_PEM_values(n, e, argv[1]);

    fermat_factorisation(results, *n);

    printf("\n%llu = %llu * %llu\n", *n, results[0], results[1]);

    unsigned long long int d = reconstruct_private_key(*e, results[0], results[1]);
    printf("\nExposant privé :%llu", d);

    free(results);
    free(e);
    free(n);

    return 0;
}
