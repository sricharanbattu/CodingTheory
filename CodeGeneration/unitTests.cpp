#include "allUserLibraries.h"

using namespace std;

void codingAutoTest(codingStrategy_t codeStrategy, vector<double>& probs)
{
	
	vector<string> codes(probs.size(), "");
	sort(probs.begin(), probs.end(), greater<double>());
	generateCodes(probs, codes, codeStrategy);
	printDetails(probs, codes);
	starLine(::gSTAR_COUNT);
}


void codingUserTest(codingStrategy_t codeStrategy, vector<double>& probs)
{
	int n = probs.size();
	vector<string> codes(n, "");
	//getCodes(probs, codes_fano, CodeMethod::eFANO);
	generateCodes(probs, codes, codeStrategy);
	printDetails(probs, codes);
	starLine(::gSTAR_COUNT);
}


void autoTest()
{
	int n = 5;
	vector<double> probs{ 0.35, 0.25, 0.15, 0.15, 0.10 };
	vector<string> codes(5, "");
	printProbabilities(probs); 
	assertProbabilities(probs);
	doubleLine();
	starLine(::gSTAR_COUNT);


	cout << "FANO's CODE" << '\n';
	codingAutoTest(fanoCode, probs);

	cout << "SHANNON's CODE" << '\n';
	codingAutoTest(shannonCode, probs);

	cout << "HUFFMAN's CODE" << '\n';
	codingAutoTest(huffmanCode, probs);
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

	sort(probs.begin(), probs.end(), greater<double>());

	starLine(::gSTAR_COUNT);

	cout << "FANO's CODE" << '\n';
	codingUserTest(fanoCode, probs);

	cout << "SHANNON's CODE" << '\n';
	codingUserTest(shannonCode, probs);

	cout << "HUFFMAN's CODE" << '\n';
	codingUserTest(huffmanCode, probs);
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

	sort(probs.begin(), probs.end(), greater<double>());

	starLine(::gSTAR_COUNT);

	cout << "FANO's CODE" << '\n';
	codingUserTest(fanoCode, probs);

	cout << "SHANNON's CODE" << '\n';
	codingUserTest(shannonCode, probs);

	cout << "HUFFMAN's CODE" << '\n';
	codingUserTest(huffmanCode, probs);
}
