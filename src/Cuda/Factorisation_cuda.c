#include "../_GlobalDefine.h"

#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

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

void extract_PEM_values(unsigned long long int* n, unsigned int* e, char* filePath){
    RSA *rsa = RSA_new();

    FILE *pemFileStream = fopen(filePath, "rb");

    PEM_read_RSA_PUBKEY(pemFileStream, &rsa, NULL, NULL);
    if (rsa == NULL) {
        printf("Erreur: impossible de lire la clé publique RSA\n");
        fclose(pemFileStream);
        return;
    }
    fclose(pemFileStream);

    const BIGNUM *BN_n;
    const BIGNUM *BN_e;
    RSA_get0_key(rsa, &BN_n, &BN_e, NULL);
    
    char* n_str = BN_bn2dec(BN_n);
    char* e_str = BN_bn2dec(BN_e);

    *n = strtoull(n_str, NULL, 10);
    *e = strtoull(e_str, NULL, 10);

    printf("Modulus : %s\n", BN_bn2hex(BN_n));
    printf("Exponent : %s\n", BN_bn2hex(BN_e));

    RSA_free(rsa);
    OPENSSL_free((void*)BN_n);
    OPENSSL_free((void*)BN_e);
}