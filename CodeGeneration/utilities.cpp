#include "Libraries.h"
#include "funcDeclare.h"

using namespace std;


void doubleLine()
{
	cout << "\n\n";
}



double getEntropy(vector<double> probs) 
{
	int n = probs.size();
	double entropy{ 0 };
	for (int i = 0; i < n; i++)
	{
		entropy -= probs[i] * log2(probs[i]);
	}

	return entropy;
}



double getAverageCodeLength(vector<double> probs, vector<string> codes)
{
	int n = probs.size();
	//Assert that codes and probs have same size. Left for future development

	double avg_len{ 0 };
	for (int i = 0; i < n; i++)
	{
		avg_len += probs[i] * codes[i].length();
	}

	return avg_len;
}