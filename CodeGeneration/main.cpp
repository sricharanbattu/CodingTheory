
#include "allUserLibraries.h"
using namespace std;

int main()
{
	
	int n;
	cout << "enter the number of messages : ";
	cin >> n;


	
	vector<double> probs(n, 0);
	getInputProbabilities(probs);
	//getRandomProbabilities(probs);
	printProbabilities(probs);
	assertProbabilities(probs);
	doubleLine();

	//Sorting is an important step for both FANO's code and SHANNON's code
	sort(probs.begin(), probs.end(), greater<double>());

	vector<string> codes_fano(n,"");
	//getCodes(probs, codes_fano, CodeMethod::eFANO);
	generateCodes(probs, codes_fano, fanoCode);
	cout << " FANO'S METHOD : " << '\n';
	printDetails(probs, codes_fano);

	vector<string> codes_shannon(n, "");
	//getCodes(probs, codes_shannon, CodeMethod::eSHANNON);
	generateCodes(probs, codes_shannon, shannonCode);
	cout << " SHANNON'S METHOD : " << '\n';
	printDetails(probs, codes_shannon);

	vector<string> codes_huffman(n, "");
	//getCodes(probs, codes_huffman, CodeMethod::eHUFFMAN);
	generateCodes(probs, codes_huffman, huffmanCode);
	cout << "HUFFMAN's METHOD : " << '\n';
	printDetails(probs, codes_huffman);
	
	return 0;
}
