#ifndef _KMP_
#define _KMP_

#include <string>
#include <vector>

std::vector<int> preprocess(std::string s);
int kmp(std::string str, std::string target, std::vector<int> backtable);
int algoNaif(std::string str, std::string target);

#endif