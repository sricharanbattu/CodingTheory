#include "Libraries.h"
#include "funcDeclare.h"

using namespace std;

void doubleLine()
{
	cout << "\n\n";
}

int main()
{
	int n;
	cout << "enter the number of messages : ";
	cin >> n;

	vector<double> probs(n, 0);
	cout << "Enter the probabilities of the messages : ";
	// Take care that the sum of probs is 1. We are not adding any sort of  check here
	double sum{ 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> probs[i];

		sum += probs[i];
		
	}


	sort(probs.begin(), probs.end(), greater<double>());

	vector<string> code(n, "");
	code = fanoCode(probs, code, 0, n - 1, "");

	doubleLine();

	for (int i = 0; i < n; i++) 
	{
		cout << "Code of message with probability " << probs[i] << " is : " << code[i] << '\n';
	}
	doubleLine();


	//Average Coding length;
	double avg_len{ 0 };
	double entropy{ 0 };
	for (int i = 0; i < n; i++)
	{
		avg_len += (code[i].length() * probs[i]);
		entropy -= probs[i] * log2(probs[i]);
	}

	cout << "Entropy = " << entropy << '\n';
	cout << "Average Coding length = " << avg_len << '\n';


	return 0;
}