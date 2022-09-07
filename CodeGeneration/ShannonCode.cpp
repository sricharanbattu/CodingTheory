#include "allUserLibraries.h"
using namespace std;


/*
* SHANNON's CODE IMPLEMENTATION : 
* The probabilities are first sorted in non-increasing order
* The code word of a given prob comes from the binary representation
* of sum of it's previous probabilities after decimal point.
* The length of the codeword is ceil(log(1/prob[i]));

*/


void shannonCodeCore(vector<double>& probs, vector<string>& codes)
{

	int n = probs.size();
	
	// The implementation comes directly from the Shannon's method. 
	double pre_cumulative_prob{ 0 };	// To store the sum of prev probabilities	

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			pre_cumulative_prob = pre_cumulative_prob + probs[i-1];

		double temp_pre_cumulative_prob{ pre_cumulative_prob };
		int code_length = ceil(-1 * log2(probs[i]));
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

	return;

}


void shannonCode(vector<double>& probs, vector<string>& codes)
{
	ASSERT_EQUAL_SIZES(probs, codes, " Probs and Codes are not of equal size; ");
	clearCodes(codes);
	sort(probs.begin(), probs.end(), greater<double>());
	shannonCodeCore(probs, codes);
}