#include "../_GlobalDefine.h"

#include <cuda.h>

__global__ void fermat_factorisation_cuda(unsigned long long int* results, unsigned long long int n, unsigned long long int *parts){
    unsigned long long int x;
    unsigned long long int y;
    unsigned short int isFactor = FALSE;

    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    unsigned long long int start = parts[tid];
    unsigned long long int end = parts[tid+1]-1;

    while (isFactor < 1 && start <= end) {
        x = sqrt(n + (pow(start, 2)));
        if(floor(x) == x){ 
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

unsigned long long int reconstruct_private_key(unsigned int e, unsigned long long int p, unsigned long long int q){
    return (unsigned long long int)pow(e, -1) % ((p-1)*(q-1));
}