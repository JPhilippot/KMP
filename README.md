# Etude de l'algorithme KMP par Denis Beauget, Aurélien Besnier, Josua Philippot.

Ce projet est une étude statistique du fonctionnement de l'algorithme KMP réalisée dans le cadre de l'évaluation de notre UE HLIN608 : Algorithimie du texte. 

Le but de ce projet est de mettre en évidence l'utilité de KMP pour traiter des séquences dans un texte volumineux et redondant par rapport à un algorithme naïf.

Les tests sont réalisés dans trois langages, C++, Java, Python.

Pour lancer les test des différents langages, utilisez :

```bash
./exec.sh <nb_execution_des_progammes> <fichier_a_parcourir> <sequence_a_trouver>
```
(Le Makefile utilisé avec cette commande à été allégé des warnings pour un meilleur confort visuel).
