#include <string>
#include <vector>
#include "fonctions.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fstream>
using namespace std;

int main(int argc, const char *argv[])
{   
    double totalNaif = 0;
    double totalKMP = 0;
    clock_t deb, fin;
    struct rusage usg;
    string f = "-f";
    unsigned int nbOcc = 0;
    unsigned int nbExec = atoi(argv[1]);
    if (argc < 5 || argc > 6)
    {
        cout << "Mauvaise utilisation de KMP ! L'appel doit s'effectuer comme ceci :\n"
             << argv[0] << " séquenceDeRéférence séquenceAtrouver" << endl;
        cout << "__OU__  " << endl;
        cout << argv[0] << " -f fichier séquenceAtrouver" << endl;
        return -1;
    }
    else
    {
        if (argc == 6)
        {
            if (argv[2] == f)
            {
                long lSize;
                char *buffer;
                size_t result;
                FILE *file = fopen(argv[3], "r");
                if (file == NULL)
                {
                    fputs("File error", stderr);
                    exit(1);
                }

                // obtain file size:
                fseek(file, 0, SEEK_END);
                lSize = ftell(file);
                rewind(file);

                // allocate memory to contain the whole file:
                buffer = (char *)malloc(sizeof(char) * lSize);
                if (buffer == NULL)
                {
                    fputs("Memory error", stderr);
                    exit(2);
                }

                // copy the file into the buffer:
                result = fread(buffer, 1, lSize, file);
                if (result != lSize)
                {
                    fputs("Reading error", stderr);
                    exit(3);
                }

                ofstream output(argv[5]);
                cout << "[Appel naïf] "<<endl;

                for (size_t i = 0; i < nbExec; i++)
                {
                    deb = clock();
                    nbOcc = algoNaif(buffer, argv[4]);
                    fin = clock();
                    cout << nbOcc << " occurences trouvées" << endl;
                    cout << (double)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
                    totalNaif += (double)(fin - deb) / CLOCKS_PER_SEC;
            }
             output << "C++[naif] " << totalNaif/nbExec << endl;

                std::vector<int> backtable(strlen(argv[4]) + 1);
                backtable = preprocess(argv[4]);
                cout << "[Appel KMP] "<<endl;

                for (size_t i = 0; i < nbExec; i++)
                {
                    deb = clock();
                    nbOcc = kmp(buffer, argv[4], backtable);
                    fin = clock();
                    cout << nbOcc << " occurences trouvées" << endl;
                    cout << (double)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
                    totalKMP += (double)(fin - deb) / CLOCKS_PER_SEC;
            }
             output << "C++[KMP] " << totalKMP/nbExec << endl;;

                fclose(file);
                free(buffer);
                output.close();
            }
            else
            {
                cout << "Paramètre " << nbExec << " non reconnu !\n L'appel doit s'effectuer comme ceci :\n"
                     << argv[0] << " séquenceDeRéférence séquenceAtrouver" << endl;
                cout << "__OU__" << endl;
                cout << argv[0] << " -f fichier séquenceAtrouver" << endl;
            }
        }

        else
        {
            ofstream output(argv[5]);
            cout << "Veuillez noter qu'il est également possible de lire des fichier en utilisant : " << argv[0] << " -f fichier séquenceAtrouver" << endl;
            cout << "[Appel naïf] "<<endl;
           
            for (size_t i = 0; i < nbExec; i++)
            {
                deb = clock();
                nbOcc = algoNaif(argv[2], argv[3]);
                fin = clock();
                cout << nbOcc << " occurences trouvées" << endl;
                cout << (double)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
                totalNaif += (double)(fin - deb) / CLOCKS_PER_SEC;
            }
             output << "C++[naif] " << totalNaif/nbExec << endl;

            std::vector<int> backtable(strlen(argv[3]) + 1);
            backtable = preprocess(argv[3]);
            cout << "[Appel KMP] "<<endl;
           
            for (size_t i = 0; i < nbExec; i++)
            {
                deb = clock();
                nbOcc = kmp(argv[2], argv[3], backtable);
                fin = clock();
                cout << nbOcc << " occurences trouvées" << endl;
                cout << (double)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
               totalKMP += (double)(fin - deb) / CLOCKS_PER_SEC;
            }
             output << "C++[KMP] " << totalKMP/nbExec << endl;;

            output.close();
            return 0;
        }
    }
}