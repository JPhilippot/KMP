## Implémentation de KMP en Python

Ceci est une implémentation de l'algorithme de recherche KMP en Python.

## Exemples d'utilisations

```bash
./main.py "test" "ceci est un test" 10 "results.data"
```
cherchera la position de `test` dans `ceci est un test` `10` fois et enregistre les résultats dans `results.data`.

```bash
./main.py "fichier" "test.txt" 10 "results.data"
```
cherchera la position de `fichier` dans le fichier `test.txt` `10` et enregistre les résultats dans `results.data`.

```bash
./main.py "fichier" "*.txt" 10 "results.data"
```
affichera la position de `fichier` dans les fichiers avec extension `.txt` dans le répertoire courant `10` fois et enregistre les résultats dans `results.data`.