
#include "Libraries.h"
using namespace std;

#ifndef FUNC_DECLARE_H
#define FUNC_DECLARE_H

void doubleLine();
double getEntropy(vector<double> probs);
double getAverageCodeLength(vector<double> probs, vector<string> codes);
vector<string> getCodes(vector<double> sorted_probs, string code_method);
void printDetails(vector<double> probs, vector<string> codes);

vector<string> fanoCode(vector <double> sorted_prob, int begin, int end, string prefix);
vector<string> shannonCode(vector<double> sorted_probs);


#endif