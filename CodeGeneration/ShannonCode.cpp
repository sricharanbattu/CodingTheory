#include "allUserLibraries.h"
using namespace std;


/*
* SHANNON's CODE IMPLEMENTATION : 
* 

*/


vector<string>& shannonCode(vector<double>& sorted_probs)
{
	int n = sorted_probs.size();
	static vector<string> codes(n, "");

	// The implementation comes directly from the Shannon's method. 

	double pre_cumulative_prob{ 0 };		// For a given prob, it is sum of of all the previous probs

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			pre_cumulative_prob = pre_cumulative_prob + sorted_probs[i-1];

		double temp_pre_cumulative_prob{ pre_cumulative_prob };
		int code_length = ceil(-1 * log2(sorted_probs[i]));
		for (int j = 0; j < code_length; j++)
		{
			temp_pre_cumulative_prob *= 2;
			if (temp_pre_cumulative_prob >= 1)
			{
				codes[i] += "1";
				temp_pre_cumulative_prob -= 1;
			}
			else
				codes[i] += "0";
		}
	}

	return codes;

}