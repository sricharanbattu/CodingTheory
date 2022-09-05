
#include "allUserLibraries.h"
using namespace std;
using pair_double_int = pair<double, int>;


struct TreeNode {
	pair_double_int pdi;
	string code{ "" };
	const TreeNode* left{ nullptr };
	const TreeNode* right{ nullptr };
};



struct compare {
	bool operator()(TreeNode a, TreeNode b)
	{
		return b.pdi.first < a.pdi.first;
	}
};



void DFS(const TreeNode* node, vector<string>& codes, string str)
{
	if (node == nullptr) {
		delete node;
		return;
	}

	if (node->left == nullptr && node->right == nullptr)
	{
		codes[(node->pdi).second] = str;
		delete node;
		return;
	}

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
	
	priority_queue<TreeNode, vector<TreeNode>, compare> pq;
	

	int n = probs.size();
	
	for (int i = 0; i < n; i++)
	{
		pq.push({ {probs[i], i}, "", nullptr, nullptr});
	}

	
	TreeNode first, second;
	while (pq.size() > 1)
	{
		first = pq.top();
		const TreeNode* first_node = new TreeNode{first};
		pq.pop();

		second = pq.top();
		const TreeNode* second_node = new TreeNode{ second};
		pq.pop();

		double combined_prob = first_node->pdi.first + second_node->pdi.first;
		pair_double_int combined_pdi = { combined_prob, -1 };
		TreeNode node = { combined_pdi, "", first_node, second_node };
		pq.push(node);

	}

	const TreeNode* root = new TreeNode{pq.top()};
	DFS(root, codes,"");

}