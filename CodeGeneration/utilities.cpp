#include "allUserLibraries.h"
using namespace std;


void doubleLine()
{
	cout << "\n\n";
}


//Set the sum of all the values in a vector to 1
void normalizeVector(vector<double>& vec)
{
	int n = vec.size();
	double sum{ 0 };
	for (int i = 0; i < n; i++)
	{
		sum += vec[i];
	}

	for (int i = 0; i < n; i++)
	{
		vec[i] = vec[i] / sum;
	}
}

// Returns a random integer within the given range as a double
double getRandomDouble()
{
	
	std::mt19937 mt{ std::random_device{}() }; // this gets created and seeded every time the function is called
	std::uniform_int_distribution range{ 100, 250 };
	return range(mt);
}


// Set random probabilities
vector<double>& getRandomProbabilities(int n)
{
	static vector<double> probs(n);
	for (int i = 0; i < n; i++)
	{
		probs[i] = getRandomDouble();

	}
	normalizeVector(probs);
	return probs;
}

// We can input the probabilities ourselves
vector<double>& getInputProbabilities(int n)
{
	static vector<double> probs(n);
	cout << "Enter the probabilities : " ;
	for (int i = 0; i < n; i++)
	{
		cin >> probs[i];
	}
	return probs; 
}

// check if the set/ entered probabilities confirm to the rules of probability
void assertProbabilities(vector<double>& probs)
{
	int n = probs.size();
	double sum{ 0 };
	for (int i = 0; i < n; i++)
	{
		ASSERT_PROB_RANGE(probs[i], 0, 1, "Entered Probability not in expected range (0,1].");
		sum += probs[i];
	}
	cout << "sum of probabilities entered is :" << sum<< '\n';
	ASSERT_TOTAL_PROB(sum, 1e-10, "Sum of Probabilities is not 1 ");
}


// Print the entered probabilities
void printProbabilities(vector<double>& probs)
{
	int n = probs.size();
	cout << "Entered Probabilities are : \n";
	for(int i = 0; i < n; i++)
	{
		cout << probs[i] << '\n';
	}
}


// Returns the entropy of the set/entered probability distribution
double getEntropy(vector<double>& probs) 
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


// Returns the avg code length given the probabilities and their corresponding codes
double getAverageCodeLength(vector<double>& probs, vector<string>& codes)
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

// Returns a vector of code strings given the probabilities and the method of coding
void getCodes(vector<double>& sorted_probs, vector<string>& codes, const enum class CodeMethod& code_method)
{
	if (code_method == CodeMethod::eFANO)
		return fanoCode(sorted_probs, codes, 0, sorted_probs.size() - 1, "");
	else if (code_method == CodeMethod::eSHANNON)
		return shannonCode(sorted_probs, codes);


}

// Print entropy, codes and avg code length for a given distribution and codes. 
void printDetails(vector<double>& probs, vector<string>& codes)
{

	int n = probs.size();
	cout << std::setprecision(5);
	for (int i = 0; i < n; i++)
	{
		cout << "Code word for the message with probability " << probs[i] << " is : \t" << codes[i] << '\n';
	}
	doubleLine();

	cout << "Entropy of the message                    =   " << getEntropy(probs) << '\n';
	cout << "Average Code Length of the message        =   " << getAverageCodeLength(probs, codes) << '\n';
	doubleLine();

}