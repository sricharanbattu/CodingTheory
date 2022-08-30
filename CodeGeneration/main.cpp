#include "Libraries.h"
#include "funcDeclare.h"

using namespace std;

int main()
{
	int n;
	cout << "enter the number of messages : ";
	cin >> n;

	vector<double> probs(n, 0);
	cout << "Enter the probabilities of the messages : ";

	// Take care that the sum of probs is 1. We are not adding any sort of  check here
	// Assert that the sum of probs is 1. For future development
	for (int i = 0; i < n; i++)
	{
		cin >> probs[i];
	}
	doubleLine();

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