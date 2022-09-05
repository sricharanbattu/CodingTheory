
#include "allUserLibraries.h"
using namespace std;
using enum CodeMethod;

int main()
{
	
	int n;
	cout << "enter the number of messages : ";
	cin >> n;


	
	vector<double> probs(n, 0);
	//getInputProbabilities(probs);
	getRandomProbabilities(probs);
	printProbabilities(probs);
	assertProbabilities(probs);
	doubleLine();

	//Sorting is an important step for both FANO's code and SHANNON's code
	sort(probs.begin(), probs.end(), greater<double>());
	vector<string> codes_fano(n,"");

	getCodes(probs, codes_fano, eFANO);
	cout << " FANO'S METHOD : " << '\n';
	printDetails(probs, codes_fano);

	vector<string> codes_shannon(n, "");
	getCodes(probs, codes_shannon, eSHANNON);
	cout << " SHANNON'S METHOD : " << '\n';
	printDetails(probs, codes_shannon);

	//vector<string> codes_huffman(n, "");
	//getCodes(probs, codes_shannon, eHUFFMAN);
	//cout << "HUFFMAN's METHOD : " << '\n';
	//printDetails(probs, codes_huffman);
	
	return 0;
}
