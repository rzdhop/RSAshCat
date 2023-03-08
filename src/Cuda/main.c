#include "../_GlobalDefine.h"
#include "Factorisation_cuda.h"

#include <stdio.h>
#include <cuda.h>


int main(int argc, char** argv) {

    printf(" ____________________________________________");
	printf("|           RSAshCat v1.0		           |");
	printf("|____________________________________________|");

    unsigned long long int *n = (unsigned long long int*)malloc(sizeof(unsigned long long int)); 
    unsigned int *e = (unsigned int*)malloc(sizeof(unsigned int));
    
    *n = 47693663;
    *e = 65537;
    //extract_PEM_values(n, e, argv[1]);
    unsigned long long int *results = (unsigned long long int*)malloc(2*sizeof(unsigned long long int));
    unsigned long long int *d_results = NULL;
    HANDLE_ERROR(cudaMalloc((void**)&d_results, 2*sizeof(unsigned long long int))); //malloc for result in driver
    
    unsigned long long int parts[THREADS+1];
    parts[0] = 1; // On commence à 1
    parts[THREADS] = *n; // On termine à n
    for(int i = 1; i < THREADS; i++) {
        parts[i] = parts[i-1] + (*n)/THREADS;
    }
    unsigned long long int *d_parts = NULL; 
    HANDLE_ERROR(cudaMalloc((void**)&d_parts, (THREADS+1)*sizeof(unsigned long long int)));

    HANDLE_ERROR(cudaMemcpy(d_parts, parts, (THREADS+1)*sizeof(unsigned long long int), cudaMemcpyHostToDevice));
    
    fermat_factorisation_cuda<<<BLOCKS, THREADS>>>(d_results, *n, d_parts); //proceed and store in d_results
    cudaDeviceSynchronize();
    HANDLE_ERROR(cudaMemcpy(results, d_results, 2*sizeof(unsigned long long int), cudaMemcpyDeviceToHost));

    printf("\n%llu = %llu * %llu\n", *n, results[0], results[1]);

    unsigned long long int d = reconstruct_private_key(*e, results[0], results[1]);
    printf("\nExposant privé :%llu", d);

    free(results);
    cudaFree(d_results);
    cudaFree(d_parts);
    free(e);
    free(n);
    return 0;
}