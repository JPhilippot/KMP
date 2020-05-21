#!/bin/bash
if [ $# != 3 ]
 then
    echo "Mauvaise utilisation du fichier, la syntaxe est : $0 nb_excecution_des_progammes fichier_a_parcourir sequence_a_trouver"
    exit 1

 else
    if [ ! -d "./Results" ]; then
        mkdir ./Results
    fi
    rm -f ./Results/*.data
    echo "Execution des programmes $1 fois sur le fichier $2, nous cherchons la séquence $3 ."
    echo "Execution de la version C++"
    make -f ./C++/MakefileExec
    ./C++/kmp $1 -f $2 $3 "./Results/result-cpp.data"
    make clean -f ./C++/MakefileExec
    echo "Execution de la version Python"
    ./Python/main.py "$3" "$2" "$1" "./Results/result-py.data"
    #execution de la version Java
    echo "Execution Java"
    javac ./Java/KmpAlgorithme.java
    cd ./Java
    java KmpAlgorithme $1 "../$2" $3
    cd ..
    echo "Recupération de la moyenne des résultats obtenus."
    cat ./Results/*.data > ./Results/all.data
    echo "Création du graphe."
    gnuplot -e "filename='$2'" -e "seq='$3'" ./make-plot.gp

fi