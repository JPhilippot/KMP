#include <string>
#include <vector>
#include "fonctions.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fstream>
using namespace std;

int main(int argc, const char *argv[])
{
    clock_t deb, fin;
    struct rusage usg;
    string f = "-f";
    if (argc < 3 || argc > 4)
    {
        cout << "Mauvaise utilisation de KMP ! L'appel doit s'effectuer comme ceci :\n"
             << argv[0] << " séquenceDeRéférence séquenceAtrouver" << endl;
        cout << "__OU__  " << endl;
        cout << argv[0] << " -f fichier séquenceAtrouver" << endl;
        return -1;
    }
    else
    {
        if (argc == 4)
        {
            if (argv[1] == f)
            {

                long lSize;
                char *buffer;
                size_t result;
                FILE *file = fopen(argv[2], "r");
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
                ofstream output("results.data");
                deb = clock();
                cout << "[Appel naïf] ";
                cout << algoNaif(buffer, argv[3]) << " occurences trouvées" << endl;
                fin = clock();
                cout << (float)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
                output << "C++[naif] " << (float)(fin - deb) / CLOCKS_PER_SEC<<endl;
                deb = clock();
                cout << "[Appel KMP] ";
                cout << kmp(buffer, argv[3]) << " occurences trouvées" << endl;
                fin = clock();
                cout << (float)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
                output << "C++[KMP] " << (float)(fin - deb) / CLOCKS_PER_SEC;
                fclose(file);
                free(buffer);
                output.close();
            }
            else
            {
                cout << "Paramètre " << argv[1] << " non reconnu !\n L'appel doit s'effectuer comme ceci :\n"
                     << argv[0] << " séquenceDeRéférence séquenceAtrouver" << endl;
                cout << "__OU__" << endl;
                cout << argv[0] << " -f fichier séquenceAtrouver" << endl;
            }
        }

        else
        {   ofstream output("results.data");
            cout << "Veuillez noter qu'il est également possible de lire des fichier en utilisant : " << argv[0] << " -f fichier séquenceAtrouver" << endl;
            cout << "[Appel naïf] ";
            deb = clock();
            cout << "[Appel naïf] ";
            cout << algoNaif(argv[1], argv[2]) << " occurences trouvées" << endl;
            fin = clock();
            cout << (float)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
            output << "C++[naif] " << (float)(fin - deb) / CLOCKS_PER_SEC<<endl;
            deb = clock();
            cout << "[Appel KMP] ";
            cout << kmp(argv[1], argv[2]) << " occurences trouvées" << endl;
            fin = clock();
            cout << (float)(fin - deb) / CLOCKS_PER_SEC << "\t" << usg.ru_utime.tv_sec + usg.ru_utime.tv_usec / 1000000. << "\t" << usg.ru_stime.tv_sec + usg.ru_stime.tv_usec / 1000000. << "\t" << usg.ru_maxrss << endl;
            output << "C++[KMP] " << (float)(fin - deb) / CLOCKS_PER_SEC;
            output.close();
            return 0;
        }
    }
}