#include "allUserLibraries.h"
using namespace std;

/*
* FANO's code Implementation :
* First sort the array in non-increasing order, We are already given the sorted array
* Slice the array into two parts such that the sum of the probablities of each part is as close as possible
* The left array gets a 0 and right array gets a 1 added to their codes
* Repeat the process for both arrays
*
*
*
* INPUT PARAMETERS :
* sorted_prob : Array of probabilities in non-decreasing order. Take care that the sum is 1
* codes       : Array of code strings of the corresponding probability
* begin       : Beginning index of the sliced/un-sliced array
* end         : Last index of the sliced/un-sliced array
* prefix      : Bit character that needs to be added to this array
*
*
* OUTPUT :
* code gets updated
*/



void fanoCodeCore(vector<double>& sorted_prob, vector<string>& codes, int begin, int end, string prefix) 
{

	 
	// Recursive base conditions 
	if (begin > end)
		return;

	if (begin == end)
	{
		codes[begin] += prefix;
		return;
	}

	// Non-trivial implementation begins here
	double sum_probs{ 0 }; // This is the sum of probabilities in this array

	for (int i = begin; i <= end; i++)
	{
		codes[i] += prefix;
		sum_probs += sorted_prob[i];
	}


	// Slicing the code. divider gives the index after which we must slice the array. 
	// (begin < divider < end) 


	double mini{ abs(sorted_prob[begin] - (sum_probs - sorted_prob[begin])) };
	int divider{ begin };
	double cumulative_prob{ sorted_prob[begin] };
	for (int i = begin + 1; i < end; i++)
	{
		cumulative_prob += sorted_prob[i];
		if (abs(cumulative_prob - (sum_probs - cumulative_prob)) < mini)
		{
			mini = abs(cumulative_prob - (sum_probs - cumulative_prob));
			divider = i;
		}
	}

	// Add prefix 0 to the left array and 1 to the right array and repeat the process
	fanoCodeCore(sorted_prob, codes, begin, divider, "0");
	fanoCodeCore(sorted_prob,codes, divider + 1, end, "1");

}


void fanoCode(vector<double>& probs, vector<string>& codes)
{
	ASSERT_EQUAL_SIZES(probs, codes, " Probs and Codes are not of equal size; ");
	clearCodes(codes);
	sort(probs.begin(), probs.end(), greater<double>());
	fanoCodeCore(probs, codes, 0, probs.size() - 1, "");
}
