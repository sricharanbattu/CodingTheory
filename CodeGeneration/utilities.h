#include "Libraries.h"
#include "defines.h"
#include "userDefinedTypes.h"

using namespace std;

#ifndef UTILITIES_H
#define UTILITIES_H

void doubleLine();
void starLine(int n);

void normalizeVector(vector<double>& vec);
void clearCodes(vector<string>& codes);
double getRandomDouble();
void getRandomProbabilities(vector<double>& probs);
void getInputProbabilities(vector<double>& probs);
void assertProbabilities(vector<double>& probs);
void printProbAndCode(vector<double>& probs, vector<string>& codes);
void printProbabilities(vector<double>& probs);

double getEntropy(vector<double>& probs);
double getAverageCodeLength(vector<double>& probs, vector<string>& codes);
void generateCodes(vector<double>& probs, vector<string>& codes, codingStrategy_t codeStrategy);
void printDetails(vector<double>& probs, vector<string>& codes);

#endif
