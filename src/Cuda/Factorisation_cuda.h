#pragma once

static void HandleError( cudaError_t err,
                         const char *file,
                         int line ) {
    if (err != cudaSuccess) {
        printf( "%s in %s at line %d\n", cudaGetErrorString( err ),
                file, line );
        exit( EXIT_FAILURE );
    }
}
#define HANDLE_ERROR( err ) (HandleError( err, __FILE__, __LINE__ ))

void fermat_factorisation_cuda(unsigned long long int* results, unsigned long long int n, unsigned long long int *parts);
void reconstruct_private_key(unsigned int e, unsigned long long int p, unsigned long long int q, char** pathName));
void extract_PEM_values(unsigned long long int* n, unsigned int* e, char[] filePath);
