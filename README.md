# RSAshCat

Le projet RSAshCat est un programme codé en C qui prend en argument un chemin de fichier RSA et effectue une attaque de factorisation. Toutes les étapes de l'attaque sont effectuées à l'aide de CUDA pour utiliser la puissance de traitement du GPU. Si un facteur est trouvé, le programme reconstruit la clé privée à partir des nouvelles valeurs de p et q trouvées.

Le projet RSAshCat a été développé par Rida VERDU, WAGUE Al-Housseiny et WIECZOREK Guillaume, pour l'école d'ingénieurs ESIEA.
Utilisation

Le programme peut être utilisé en utilisant les commandes suivantes :

```bash
./RSAshCat <chemin_fichier_RSA>
```

## Algorithme utilisé

L'algorithme de factorisation utilisé dans le projet RSAshCat est le crible quadratique généralisé (General Number Field Sieve - GNFS), qui est une méthode avancée pour factoriser des nombres entiers très grands.

Le crible quadratique généralisé est basé sur l'utilisation de l'algèbre de corps de nombres. L'idée principale est de trouver un petit facteur p d'un grand nombre entier N en trouvant une paire de nombres a et b tels que :

$$a^2\ ≡\ b^2\ (mod\ p)$$

En utilisant l'identité *(a + b)(a - b) = a^2 - b^2*, on peut exprimer N comme :

$$N\ =\ (a\ +\ b)(a\ -\ b)\ mod\ p$$

En résolvant cette équation pour p, nous pouvons trouver un facteur de N.

Pour trouver les nombres <i>a</i> et <i>b</i>, le crible quadratique généralisé utilise une méthode similaire à la méthode rho de Pollard, mais avec des courbes elliptiques. En utilisant ces courbes elliptiques, le programme cherche des points qui se répètent, ce qui indique qu'il y a une collision entre les points. Ces collisions peuvent être utilisées pour trouver des facteurs de N.

Le crible quadratique généralisé est une méthode très puissante pour factoriser des nombres entiers très grands, mais elle nécessite beaucoup de puissance de traitement. En utilisant CUDA pour effectuer les calculs sur le GPU, RSAshCat peut effectuer cette attaque de manière beaucoup plus rapide que les méthodes conventionnelles.

## Répartition des tâches

| Personne	| Tâches | Réalisées |
| :--- | :---:| ---: |
| Rida VERDU	| Algoritme & Reconstruction PK | |
| WAGUE Al-Housseiny	| Interfaces d'interaction utilisateur |  |
| WIECZOREK Guillaume	|  A definir |  |

