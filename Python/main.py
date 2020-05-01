#!/usr/bin/python3
import sys,os,glob,time

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
    nbOcc=0
    while i < len(text):       # tant qu'on a pas parcouru tout le texte
        while j >= 0 and text[i] != seq[j]:
            j=tabcorres[j]
        i+=1
        j+=1
        if j == len(seq):     # si on a trouvé le mot on affiche sa position
            # print("Le mot \""+seq+"\" se trouve en position: "+str(i-j))
            j=tabcorres[j-1]
            nbOcc+=1

    return -1 if nbOcc==0 else nbOcc

def algonaif (seq, text):
    list_pos=[]
    n=len(text)
    m=len(seq)

    for i in range(n-m+1):
        j=0
        while (j<m and text[i+j]==seq[j]):
            j+=1
        if j==m:
            list_pos.append(i)

    return len(list_pos)

if __name__=="__main__":
    if len(sys.argv) != 3:
        print("USAGE: ./main.py <séquence_à_trouver> <texte | chemin/vers/un/ou/des/fichier>")
        exit(1)

    files = []
    for file in glob.glob(sys.argv[2]):
        files.append(file)
        if not files:
            ##################################################
            print("__Version Naïve__:")
            deb = time.clock()
            print("Il y a "+str(algonaif(sys.argv[1], sys.argv[2]))+" occurences de "+sys.argv[1])
            timenaif=str(time.clock()-deb)
            print("Durée: "+timenaif)
            ##################################################
            print("__Version KMP__:")
            deb = time.clock()
            print("Il y a "+str(kmp(sys.argv[1], sys.argv[2]))+" occurences de "+sys.argv[1])
            timekmp=str(time.clock()-deb)
            print("Durée: "+timekmp)

            #On sauvegarde dans le fichier
            content="Python[naif] "+timenaif+"\nPython[KMP] "+timekmp
            f=open("results.data","w")
            f.write(content)
            f.close()
        else:
            for file in files:
                f=open(file,"r")
                content = f.read()
                print("Dans le fichier \""+ file+"\"")

            ##################################################
            print("__Version Naïve__:")
            deb = time.clock()
            print("Il y a "+str(algonaif(sys.argv[1], content))+" occurences de "+sys.argv[1])
            timenaif=str(time.clock()-deb)
            print("Durée: "+timenaif)
            ##################################################
            print("__Version KMP__:")
            deb = time.clock()
            print("Il y a "+str(kmp(sys.argv[1], content))+" occurences de "+sys.argv[1])
            timekmp=str(time.clock()-deb)
            print("Durée: "+timekmp)
            f.close()
            #On sauvegarde dans le fichier
            content="Python[naif] "+timenaif+"\nPython[KMP] "+timekmp
            f=open("results.data","w")
            f.write(content)
            f.close()
