#include "Libraries.h"
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
* code        : Array of code strings of the corresponding probability
* begin       : Beginning index of the sliced/un-sliced array
* end         : Last index of the sliced/un-sliced array
* prefix      : Bit character that needs to be added to this array
*
*
* OUTPUT :
* code gets updated
*/


vector<string> fanoCode(vector <double> sorted_prob, int begin, int end, string prefix) 
{

	static vector<string> code(end-begin+1, "");      // declaring a code vector here for the first time

	// Recursive base conditions 
	if (begin > end)
		return code;

	if (begin == end)
	{
		code[begin] += prefix;
		return code;
	}

	// Non-trivial implementation begins here
	int n = end - begin + 1;

	for (int i = begin; i <= end; i++)
	{
		code[i] += prefix;
	}

	// These two are to calculate the cumulative probabilities upto an index from begin and end
	// These values are used to slice the array so that both arrays has total probability as close as possible
	vector<double> cumulative_prob(n, 0);
	vector<double> cumulative_backprob(n, 0);


	// Slicing the code. divider gives the index after which we must slice the array. 
	// (begin < divider < end) 
	cumulative_prob[0] = sorted_prob[begin];
	cumulative_backprob[n - 1] = sorted_prob[end];

	for (int i = 1; i < n; i++)
	{
		cumulative_prob[i] = cumulative_prob[i - 1] + sorted_prob[begin + i];
	}

	for (int j = n - 2; j >= 0; j--) {
		cumulative_backprob[j] = cumulative_backprob[j + 1] + sorted_prob[begin + j];
	}


	double mini{ abs(cumulative_prob[0] - cumulative_backprob[1]) };
	int divider{ begin };
	for (int i = 1; i < n - 1; i++) {
		if (abs(cumulative_prob[i] - cumulative_backprob[i + 1]) < mini)
		{
			mini = abs(cumulative_prob[i] - cumulative_backprob[i + 1]);
			divider = begin + i;
		}
	}


	// Add prefix 0 to the left array and 1 to the right array and repeat the process
	code = fanoCode(sorted_prob, begin, divider, "0");
	code = fanoCode(sorted_prob, divider + 1, end, "1");

	return code;

}