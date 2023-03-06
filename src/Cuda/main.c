#include "../_GlobalDefine.h"
#include "Factorisation_cuda.h"

#include <stdio.h>
#include <cuda.h>


int main() {
    unsigned long long int n = 178567; 
    unsigned long long *results = (unsigned long long*)malloc(2*sizeof(unsigned long long));
    unsigned long long *d_results;
    cudaMalloc((void**)d_results, 2*sizeof(unsigned long long)); //malloc for result in driver
    
    unsigned long long int parts[THREADS+1];
    parts[0] = 1; // On commence à 1
    parts[THREADS] = n; // On termine à n
    for(int i = 1; i < THREADS; i++) {
        parts[i] = parts[i-1] + n/THREADS;
    }
    unsigned long long int *d_parts;
    cudaMalloc((void**)d_parts, (THREADS+1)*sizeof(unsigned long long int));

    cudaMemcpy(d_parts, parts, (THREADS+1)*sizeof(unsigned long long int), cudaMemcpyHostToDevice);
    
    fermat_factorisation_cuda<<<BLOCKS, THREADS>>>(d_results, n, d_parts); //proceed and store in d_results
    cudaDeviceSynchronize();
    cudaMemcpy(results, d_results, 2*sizeof(unsigned long long), cudaMemcpyDeviceToHost);

    printf("\n%llu = %llu * %llu\n", n, results[0], results[1]);

    free(results);
    cudaFree(d_results);
    return 0;
}