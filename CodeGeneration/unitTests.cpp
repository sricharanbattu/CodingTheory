#include "allUserLibraries.h"

using namespace std;

void singleCodeTest(codingStrategy_t codeStrategy, vector<double>& probs)
{
	
	vector<string> codes(probs.size(), "");

	generateCodes(probs, codes, codeStrategy);
	printDetails(probs, codes);
	starLine(::gSTAR_COUNT);
}



void autoTest()
{
	int n = 5;
	vector<double> probs{ 0.35, 0.25, 0.15, 0.15, 0.10 };
	vector<string> codes(n, "");

	printProbabilities(probs); 
	assertProbabilities(probs);

	doubleLine();
	starLine(::gSTAR_COUNT);

	cout << "HUFFMAN's CODE" << '\n';
	singleCodeTest(huffmanCode, probs);

	cout << "FANO's CODE" << '\n';
	singleCodeTest(fanoCode, probs);

	cout << "SHANNON's CODE" << '\n';
	singleCodeTest(shannonCode, probs);

}


void userTest()
{
	int n;
	cout << "enter the number of messages : ";
	cin >> n;

	vector<double> probs(n, 0);
	getInputProbabilities(probs);
	printProbabilities(probs);
	assertProbabilities(probs);
	doubleLine();


	starLine(::gSTAR_COUNT);

	cout << "HUFFMAN's CODE" << '\n';
	singleCodeTest(huffmanCode, probs);

	cout << "FANO's CODE" << '\n';
	singleCodeTest(fanoCode, probs);

	cout << "SHANNON's CODE" << '\n';
	singleCodeTest(shannonCode, probs);

}



void randomTest()
{
	int n;
	cout << "enter the number of messages : ";
	cin >> n;

	vector<double> probs(n, 0);
	getRandomProbabilities(probs);
	printProbabilities(probs);
	assertProbabilities(probs);
	doubleLine();


	starLine(::gSTAR_COUNT);

	cout << "HUFFMAN's CODE" << '\n';
	singleCodeTest(huffmanCode, probs);

	cout << "FANO's CODE" << '\n';
	singleCodeTest(fanoCode, probs);

	cout << "SHANNON's CODE" << '\n';
	singleCodeTest(shannonCode, probs);

}
