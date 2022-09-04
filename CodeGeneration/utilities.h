#include "allUserLibraries.h"
using namespace std;

#ifndef UTILITIES_H
#define UTILITIES_H

void doubleLine();

void normalizeVector(vector<double>& vec);
double getRandomDouble();
void getRandomProbabilities(vector<double> probs);
void getInputProbabilities(vector<double>& probs);
void assertProbabilities(vector<double>& probs);
void printProbabilities(vector<double>& probs);

double getEntropy(vector<double>& probs);
double getAverageCodeLength(vector<double>& probs, vector<string>& codes);
void getCodes(vector<double>& sorted_probs,vector<string>& codes, const enum class CodeMethod& code_method); // const references can take rvalues
void printDetails(vector<double>& probs, vector<string>& codes);

#endif
