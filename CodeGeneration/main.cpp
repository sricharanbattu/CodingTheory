
#include "allUserLibraries.h"
using namespace std;
using enum CodeMethod;

int main()
{
	
	int n;
	cout << "enter the number of messages : ";
	cin >> n;

	cout << std::setprecision(5);

	//vector<double>& probs{ getRandomProbabilities(n) };
	vector<double>& probs{ getInputProbabilities(n) };
	printProbabilities(probs);
	assertProbabilities(probs);
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
