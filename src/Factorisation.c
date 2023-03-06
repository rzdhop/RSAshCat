#include "_GlobalDefine.h"
#include <math.h>

void fermat_factorisation(unsigned long long** results, unsigned long long n){
    unsigned long long x;
    unsigned long long y;
    unsigned short isFactor = FALSE;

    for(unsigned long long i = 0; isFactor < 1; y++){
        x = sqrt(n + (pow(i, 2)));
        if(floor(x) == x){
            y = i;
            isFactor = TRUE;
        }
    }
    *results[0] = (x + y);
    *results[1] = (x - y);

}