#include "../_GlobalDefine.h"

#include <cuda.h>

__global__ void fermat_factorisation_cuda(unsigned long long* results, unsigned long long n, unsigned long long int parts[]){
    unsigned long long x;
    unsigned long long y;
    unsigned short isFactor = FALSE;

    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    unsigned long long int start = parts[tid];
    unsigned long long int end = parts[tid+1]-1;

    while (isFactor < 1 && start <= end) {
        x = sqrt(n + (pow(start, 2)));
        if(floor(x) == x){ //check int avec l'arrondi
            y = start;
            isFactor = TRUE;
        }
        start++;
    }
    
    if (isFactor) {
        results[0] = (x + y);
        results[1] = (x - y);
    }
}
