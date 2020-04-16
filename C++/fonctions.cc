#include "fonctions.h"
#include <iostream>

std::vector<int> preprocess(std::string s)
{
    std::vector<int> backtable(s.size() + 1);
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

int kmp(std::string str, std::string target)
{
    // std::cout << "Comparons " << str << " avec " << target << std::endl;
    if (target.empty())
    {
        // std::cout << "Il y a aucune occurence(s) de " << target << " dans " << str << "." << std::endl;
        return 0;
    }

    else if (target.size() > str.size())
    {
        // std::cout << "La séquence à comparer est vide, fin de l'algorithme." << std::endl;
        return -1;
    }
    std::vector<int> backtable(target.size() + 1);
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
    // std::cout << "Il y a " << cpt << " occurence(s) de " << target << " dans " << str << "." << std::endl;
    return cpt;
}

int algoNaif(std::string str, std::string target)
{
    // std::cout << "Comparons " << str << " avec " << target << std::endl;
    int cpt = 0;
    if (target.empty())
    {
        // std::cout << "Il y a aucune occurence(s) de " << target << " dans " << str << "." << std::endl;
        return 0;
    }

    else if (target.size() > str.size())
    {
        // std::cout << "La séquence à comparer est vide, fin de l'algorithme." << std::endl;
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
    // std::cout << "Il y a " << cpt << " occurence(s) de " << target << " dans " << str << "." << std::endl;
    return cpt;
}