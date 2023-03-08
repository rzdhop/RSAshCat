#include "../_GlobalDefine.h"

#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>


void fermat_factorisation(unsigned long long int* results, unsigned long long int n){
    unsigned long long x;
    unsigned long long y;
    unsigned short isFactor = FALSE;
    unsigned int i = 0;

    while(!isFactor){
        x = sqrt(n + (pow(i, 2)));
        if(floor(x) == x){ //check int avec l'arrondi
            y = i;
            isFactor = TRUE;
        }
        i++;
    }

    if (isFactor) {
        results[0] = (x + y);
        results[1] = (x - y);
    }
}

unsigned long long int reconstruct_private_key(unsigned int e, unsigned long long int p, unsigned long long int q){
    return (unsigned long long int)pow(e, -1) % ((p-1)*(q-1));
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