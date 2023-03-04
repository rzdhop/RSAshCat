/* ------------------- import of libraries ------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ------------------- main.c : Principal program ------------------- */

int main(int argc, char *argv[]) {

	FILE* rsa_file = fopen(argv[1],  "r");

	printf(" ____________________________________________");
	printf("|           RSAshCat v1.0		           |");
	printf("|____________________________________________|");

	if (rsa_file == NULL) {
		printf("\n\t>>> /!\ The RSA file you provide doesn't exist /!\");
		printf("\n\t    Programm finished ...");
		exit()

	} else {
		printf("\n\t>>> Your RSA file: %s", argv[1]);
		printf("\n\tBegin of the attack ...");

	}

	return 0;
}