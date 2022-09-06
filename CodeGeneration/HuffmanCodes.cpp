
/*
* Huffman Code is the optimal code for a given probability distribution wrt optimal code length.
* There could be many optimisations possible with this source code
*/


#include "allUserLibraries.h"
using namespace std;
using pair_double_int = pair<double, int>;


struct TreeNode {

	pair_double_int pdi;				// {double,int}. double stores the probability(of the leaf or combined prob of its children)
										// and int stores the index of the code vector if the node is a leaf(valid prob), else stores -1;
	const TreeNode* left{ nullptr };	
	const TreeNode* right{ nullptr };
};


// This is the criteria on how the priority queue should prioritise
struct compare {
	bool operator()(TreeNode a, TreeNode b)
	{
		return b.pdi.first < a.pdi.first;
	}
};


// This is to traverse the tree after construction to get the codes of the leaf nodes
void DFS(const TreeNode* node, vector<string>& codes, string str)
{
	if (node == nullptr) {
		delete node;
		return;
	}

	if (node->left == nullptr && node->right == nullptr)
	{
		codes[(node->pdi).second] = str;    // Updates the codeword if the node is a life
		delete node;
		return;
	}

	// We can actually remove these checks,
	// as the node would either be a leaf or has two children. 
	// So the conditions will always be true here
	if (node->left != nullptr)				
	{
		DFS(node->left, codes, str + "0");
	}

	if (node->right != nullptr)
	{
		DFS(node->right, codes, str + "1");
	}

	delete node;
	return;

}


void huffmanCode(vector<double>& probs, vector<string>& codes)
{
	
	// Priority queue implements the heap. We need the two smallest probs for 
	// every step in constructing the tree, so this is the best data structure to use
	priority_queue<TreeNode, vector<TreeNode>, compare> pq; 
	int n = probs.size();
	for (int i = 0; i < n; i++)
	{
		pq.push({ {probs[i], i}, nullptr, nullptr});
	}

	
	TreeNode first, second, node;
	while (pq.size() > 1)
	{
		// Pop the least two probabilities
		// And add the combined prob to the queue
		first = pq.top();
		const TreeNode* const first_node = new TreeNode{first};
		pq.pop();

		second = pq.top();
		const TreeNode* const second_node = new TreeNode{ second};
		pq.pop();

		double combined_prob = first_node->pdi.first + second_node->pdi.first;
		pair_double_int combined_pdi = { combined_prob, -1 };

		// This builds the subtree at each step
		node = { combined_pdi, first_node, second_node }; 
		pq.push(node);

	}

	const TreeNode* const root = new TreeNode{pq.top()};
	DFS(root, codes,"");

}