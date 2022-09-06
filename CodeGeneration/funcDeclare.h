
#include "allUserLibraries.h"
using namespace std;

#ifndef FUNC_DECLARE_H
#define FUNC_DECLARE_H



void fanoCode(vector<double>& probs, vector<string>& codes);
void shannonCode(vector<double>& sorted_probs, vector<string>& codes);
void huffmanCode(vector<double>& probs, vector<string>& codes);


#endif