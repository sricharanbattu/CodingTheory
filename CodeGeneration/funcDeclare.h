
#include "Libraries.h"
using namespace std;

#ifndef FUNC_DECLARE_H
#define FUNC_DECLARE_H

double getEntropy(vector<double> probs);
double getAverageCodeLength(vector<double> probs, vector<string> codes);
vector<string> fanoCode(vector <double> sorted_prob, vector<string> code, int begin, int end, string prefix);

#endif