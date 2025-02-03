# RSAshCat

Le projet RSAshCat est un programme codé en C qui prend en argument un chemin de fichier RSA et effectue une attaque de factorisation. Toutes les étapes de l'attaque sont effectuées à l'aide de CUDA pour utiliser la puissance de traitement du GPU. Si un facteur est trouvé, le programme reconstruit la clé privée à partir des nouvelles valeurs de p et q trouvées.

Le projet RSAshCat a été développé par Rida VERDU, WAGUE Al-Housseiny et WIECZOREK Guillaume, pour l'école d'ingénieurs ESIEA.
Utilisation

Le programme peut être utilisé en utilisant les commandes suivantes :

```bash
./RSAshCat <chemin_fichier_RSA>
```

## Algorithme utilisé

L'algorithme de factorisation utilisé dans le projet RSAshCat est la factorisation de Fermat pour factoriser des nombres entiers.
Il repose sur la formule :

$$n\ =\ x^2\ -\ y^2 \equiv\ x\ =\ \sqrt{n\ +\ y^2}$$

et sur :

$$n\ =\ p\ .\ q \equiv\ n\ =\ (x\ +\ y)\ .\ (x\ -\ y)$$

En itérant sur la valeur de y, il est possible de tester si x est entier, 
si il est alors x et y sont facteur de n (respectivement p et q).

## Fonctionnement

- Chargement du fichier PEM contenant la clée publique
- Division des tâches pour les thread du kernel
- Factorisation du modulus
- Si trouvé, retour des valeurs du Device au Host
- Affichage de "n = p*q"
- Reconstruction de d avec la formule :

$$ d\ =\ e^{-1}\ mod\ ((p-1)*(q-1))$$
- Affichage de l'exposant privé !

