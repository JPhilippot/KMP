#ifndef _KMP_
#define _KMP_
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

vector<int> preprocess(string s)
{
    vector<int> backtable(s.size() + 1);
    backtable[0] = -1;
    int i = 0, j = -1;
    while (i < s.size())
    {
        while (j >= 0 && s[i] != s[j])
            j = backtable[j];
        backtable[++i] = ++j;
    }
    return backtable;
}

// return index of first matching target substring
int kmp(string str, string target)
{
    cout << "Comparons " << str << " avec " << target << endl;
    if (target.empty())
    {
        cout << "Il y a aucune occurence(s) de " << target << " dans " << str << "." << endl;
        return 0;
    }

    else if (target.size() > str.size())
    {
        cout << "La séquence à comparer est vide, fin de l'algorithme." << endl;
        return -1;
    }
    vector<int> backtable(target.size() + 1);
    backtable = preprocess(target);
    int i = 0, j = 0, cpt = 0;
    while (i < str.size())
    {
        while (j >= 0 && str[i] != target[j])
            j = backtable[j];
        i++, j++;
        if (j == target.size())
        {
            cpt++;
        }
    }
    cout << "Il y a " << cpt << " occurence(s) de " << target << " dans " << str << "." << endl;
    return cpt;
}

int algoNaif(string str, string target)
{
    cout << "Comparons " << str << " avec " << target << endl;
    int cpt = 0;
    if (target.empty())
    {
        cout << "Il y a aucune occurence(s) de " << target << " dans " << str << "." << endl;
        return 0;
    }

    else if (target.size() > str.size())
    {
        cout << "La séquence à comparer est vide, fin de l'algorithme." << endl;
        return -1;
    }
    unsigned int tmpCount = 0;
    for (unsigned int i = 0; i < str.size(); i++)
    {
        unsigned int j = 0;
        unsigned int tmpI = i;
        while (str[i] == target[j])
        {
            tmpCount++;
            if (tmpCount == target.size())
            {
                cpt++;
                tmpCount = 0;
            }
            j++;
            i++;
        }
        tmpCount = 0;
        i = tmpI;
    }
    cout << "Il y a " << cpt << " occurence(s) de " << target << " dans " << str << "." << endl;
    return cpt;
}
int main(int argc, const char *argv[])
{
    if (argc < 3 || argc > 4)
    {
        cout << "Mauvaise utilisation de KMP ! L'appel doit s'effectuer comme ceci :" << argv[0] << " séquenceDeRéférence séquenceAtrouver" << endl;
        cout << "OU" << endl;
        cout << argv[0] << "-f fichier séquenceAtrouver" << endl;
        return -1;
    }
    else
    {
        if (argc = 4)
        {
            if (argv[1] == '-f')
            {
                FILE * f = fopen ( argv[2], r);
                

            }
            else
            {
                cout << "Paramètre " << argv[1] << " non reconnu !\n L'appel doit s'effectuer comme ceci :" << argv[0] << " séquenceDeRéférence séquenceAtrouver" << endl;
                cout << "OU" << endl;
                cout << argv[0] << "-f fichier séquenceAtrouver" << endl;
            }
        }

        else
        {
            cout << "Veuillez noter qu'il est également possible de lire des fichier en utilisant : " argv[0] << "-f fichier séquenceAtrouver" << endl;
            cout << "[Appel naïf] ";
            algoNaif(argv[1], argv[2]);
            cout << "[Appel KMP] ";
            kmp(argv[1], argv[2]);
            return 0;
        }
    }
#endif