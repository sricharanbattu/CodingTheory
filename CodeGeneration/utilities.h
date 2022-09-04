#include "allUserLibraries.h"
using namespace std;

#ifndef UTILITIES_H
#define UTILITIES_H

void doubleLine();

void normalizeVector(vector<double>& vec);
double getRandomDouble();
vector<double>& getRandomProbabilities(int n);
vector<double>& getInputProbabilities(int n);
void assertProbabilities(vector<double>& probs);
void printProbabilities(vector<double>& probs);

double getEntropy(vector<double>& probs);
double getAverageCodeLength(vector<double>& probs, vector<string>& codes);
vector<string>& getCodes(vector<double>& sorted_probs, const enum class CodeMethod& code_method); // const references can take rvalues
void printDetails(vector<double>& probs, vector<string>& codes);

#endif
