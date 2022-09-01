#include "Libraries.h"
#include "funcDeclare.h"
#include "utilities.h"
#include "defines.h"

using namespace std;

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
		ASSERT_RANGE_PROB(probs[i], 0, 1, "Entered Probability not in expected range (0,1].");
		sum_probs += probs[i];
		cout << "You entered " << probs[i] << '\n';
	}

	// Assert that the sum of probs is 1.
	ASSERT_TOTAL_PROB(sum_probs, 1e-10, "Sum of Probabilities is not 1");
	doubleLine();

	//Sorting is an important step for both FANO's code and SHANNON's code
	sort(probs.begin(), probs.end(), greater<double>());
	vector<string> codes;

	codes = getCodes(probs, "FANO");
	cout << " FANO'S METHOD : " << '\n';
	printDetails(probs, codes);

	codes = getCodes(probs, "SHANNON");
	cout << " SHANNON'S METHOD : " << '\n';
	printDetails(probs, codes);
	
	return 0;
}