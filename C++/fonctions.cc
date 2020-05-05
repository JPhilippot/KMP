#include "fonctions.h"
#include <iostream>

std::vector<int> preprocess(std::string s)
{
    std::vector<int> backtable(s.size() + 1);
    backtable[0] = -1;
    size_t i = 0; 
    int j = -1;
    while (i < s.size())
    {
        while (j >= 0 && s[i] != s[j])
            j = backtable[j];
        backtable[++i] = ++j;
    }
    return backtable;
}

int kmp(std::string str, std::string target, std::vector<int> backtable)
{

    size_t i = 0, cpt = 0;
    int j = 0; 
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
{   size_t cpt =0;
    for (size_t i = 0; i < (str.size() - target.size() + 1); i++)
    {
        size_t j = 0;
        while (j < target.size() && str[i + j] == target[j])
        {
            j++;
             if (j == target.size())
            {
                cpt++;
            }
        }
    }
    return cpt;
}
