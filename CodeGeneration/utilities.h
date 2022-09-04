#include "allUserLibraries.h"
using namespace std;

#ifndef UTILITIES_H
#define UTILITIES_H

void doubleLine();

double getEntropy(vector<double>& probs);
double getAverageCodeLength(vector<double>& probs, vector<string>& codes);
vector<string>& getCodes(vector<double>& sorted_probs, const enum class CodeMethod& code_method); // const references can take rvalues
void printDetails(vector<double>& probs, vector<string>& codes);

#endif
