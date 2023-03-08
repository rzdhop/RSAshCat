/* ------------------- import of libraries ------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

/* ------------------- InfoRSARecovery.c : Recovery function of exponent and modulus ------------------- */

int main(int argc, char *argv[])
{

    printf("Vous allez utiliser ce programme vers : %s", argv[1]);

    RSA *rsa = RSA_new();
    if (!rsa) {
        fprintf(stderr, "RSA_new() failed.\n");
        exit(1);
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    PEM_read_RSA_PUBKEY(f, &rsa, NULL, NULL);
    fclose(f);

    const BIGNUM *modulus;
    const BIGNUM *exponent;
    RSA_get0_key(rsa, &modulus, &exponent, NULL);

    char *modulus_str = BN_bn2hex(modulus);
    char *exponent_str = BN_bn2hex(exponent);

    printf("Modulus : %s\n", modulus_str);
    printf("Exponent : %s\n", exponent_str);

    RSA_free(rsa);
    OPENSSL_free(modulus_str);
    OPENSSL_free(exponent_str);

    return 0;
}
