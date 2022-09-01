#include "Libraries.h"
#include "funcDeclare.h"
#include "defines.h"

using namespace std;


void doubleLine()
{
	cout << "\n\n";
}



double getEntropy(vector<double> probs) 
{
	int n = probs.size();
	double entropy{ 0 };
	for (int i = 0; i < n; i++)
	{
		if (probs[i] <= 0)
			continue;
		entropy -= probs[i] * log2(probs[i]);
	}

	return entropy;
}



double getAverageCodeLength(vector<double> probs, vector<string> codes)
{
	int n = probs.size();
	//Assert that codes and probs have same size. Left for future development

	double avg_len{ 0 };
	for (int i = 0; i < n; i++)
	{
		avg_len += probs[i] * codes[i].length();
	}

	return avg_len;
}

vector<string> getCodes(vector<double> sorted_probs, string code_method)
{
	if (code_method == "FANO")
		return fanoCode(sorted_probs, 0, sorted_probs.size() - 1, "");
	else if (code_method == "SHANNON")
		return shannonCode(sorted_probs);


}


void printDetails(vector<double> probs, vector<string> codes)
{

	int n = probs.size();
	//Assert here whether probs and codes both have same size. Leaving for further development
	for (int i = 0; i < n; i++)
	{
		cout << "Code word for the message with probability " << probs[i] << " is : " << codes[i] << '\n';
	}
	doubleLine();

	cout << "Entropy of the message                    =   " << getEntropy(probs) << '\n';
	cout << "Average Code Length of the message        =   " << getAverageCodeLength(probs, codes) << '\n';
	doubleLine();

}