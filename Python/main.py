#!/usr/bin/python3
from pycallgraph import PyCallGraph
from pycallgraph.output import GraphvizOutput
import sys,os,glob

def correspondances(seq):
    tabcorres=[0 for x in range(len(seq)+1)]
    tabcorres[0]=-1
    i=0
    j=-1
    while i < len(seq):
        while j >= 0 and seq[i] != seq[j]:
            j=tabcorres[j]
        i+=1
        j+=1
        tabcorres[i]=j
    return tabcorres

def kmp (seq, text):
    if not seq:                # si on passe le mot vide on renvoie 0
        return 0
    elif len(seq) > len(text): # si on passe un mot trop long
        return -1              # par rapport au texte, erreur
    tabcorres=correspondances(seq)
    i=0
    j=0
    while i < len(text):       # tant qu'on a pas parcouru tout le texte
        while j >= 0 and text[i] != seq[j]:
            j=tabcorres[j]
        i+=1
        j+=1
        if j == len(seq):     # si on a trouvé le mot on affiche sa position
            print("Le mot \""+seq+"\" se trouve en position: "+str(i-j))
            j=tabcorres[j-1]

    return -1                 # on a pas trouvé le mot


if __name__=="__main__":
    if len(sys.argv) != 3:
        print("USAGE: ./main.py <séquence_à_trouver> <texte | chemin/vers/un/ou/des/fichier>")
        exit(1)

    files = []
    for file in glob.glob(sys.argv[2]):
        files.append(file)
    with PyCallGraph(output=GraphvizOutput()):
        if not files:
            kmp(sys.argv[1], sys.argv[2])
        else:
            for file in files:
                f=open(file,"r")
                print("Dans le fichier \""+ file+"\"")
                kmp(sys.argv[1], f.read())
                f.close()
