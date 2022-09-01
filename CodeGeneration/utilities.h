#include "Libraries.h"

#ifndef UTILITIES_H
#define UTILITIES_H

void doubleLine();

double getEntropy(vector<double> probs);
double getAverageCodeLength(vector<double> probs, vector<string> codes);
vector<string> getCodes(vector<double> sorted_probs, string code_method);
void printDetails(vector<double> probs, vector<string> codes);

#endif
