#include "../_GlobalDefine.h"
#include <stdlib.h>


void fermat_factorisation(unsigned long long* results, unsigned long long n){
    unsigned long long x;
    unsigned long long y;
    unsigned short isFactor = FALSE;

    fwhile(!isFactor){
        x = sqrt(n + (pow(i, 2)));
        if(floor(x) == x){ //check int avec l'arrondi
            y = i;
            isFactor = TRUE;
        }
    }
    if (isFactor) {
        results[0] = (x + y);
        results[1] = (x - y);
    }
}

