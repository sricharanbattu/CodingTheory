
#include "allUserLibraries.h"
using namespace std;
using enum CodeMethod;

int main()
{
	
	int n;
	cout << "enter the number of messages : ";
	cin >> n;

	vector<double> probs(n, 0);
	cout << "Enter the probabilities of the messages in decimal notation(Fractions don't work): \n";

	// Take care that the sum of probs is 1. 
	double sum_probs{ 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> probs[i];
		ASSERT_PROB_RANGE(probs[i], 0, 1, "Entered Probability not in expected range (0,1].");
		sum_probs += probs[i];
		cout << "You entered " << probs[i] << '\n';
	}

	cout << "sum of probabilities entered is :" << sum_probs << '\n';
	// Assert that the sum of probs is 1.
	ASSERT_TOTAL_PROB(sum_probs, 1e-10, "Sum of Probabilities is not 1 " );
	doubleLine();

	//Sorting is an important step for both FANO's code and SHANNON's code
	sort(probs.begin(), probs.end(), greater<double>());
	//vector<string> codes;

	vector<string>& codes_fano = getCodes(probs, eFANO);
	cout << " FANO'S METHOD : " << '\n';
	printDetails(probs, codes_fano);

	vector<string>& codes_shannon = getCodes(probs, eSHANNON);
	cout << " SHANNON'S METHOD : " << '\n';
	printDetails(probs, codes_shannon);
	
	return 0;
}
