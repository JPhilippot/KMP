## Implémentation de KMP en C++

Ceci est une implémentation de l'algorithme de recherche KMP  et son équivalent naïf en C++.

## Exemples d'utilisations

```bash
./kmp -f fichier_dans_lequel_chercher sequence_a_trouver
```
va chercher la séquence dans un fichier donné et va donner son nombre d'occurences.
```bash
./kmp chaine_de_caractere sequence_a_trouver
```
va chercher la séquence dans la chaine donnée en paramètre et va donner son nombre d'occurences.

Une fois le programme terminé il va créer un fichier appelé 'results.data' qui contient les temps d'exécutions enregistré pour les deux fonction.
Il est alors necéssaire de lancer la commande :
```bash
./make-plot.gp
```
qui va créer le graphe associé.
