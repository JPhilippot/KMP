## Implémentation de KMP en Python

Ceci est une implémentation de l'algorithme de recherche KMP en Python.

## Exemples d'utilisations

```bash
./main.py "test" "ceci est un test"
```
affichera la position de `test` dans `ceci est un test`.

```bash
./main.py "fichier" "test.txt"
```
affichera la position de `fichier` dans le fichier `test.txt`.

```bash
./main.py "fichier" "*.txt"
```
affichera la position de `fichier` dans les fichiers avec extension `.txt` dans le répertoire courant.