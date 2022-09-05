
#include "allUserLibraries.h"
using namespace std;
using pair_double_int = pair<double, int>;

struct TreeNode {
	pair_double_int pdi;
	string code{""};
	TreeNode* left{nullptr};
	TreeNode* right{nullptr};
};

struct compare {

	bool operator()(TreeNode a, TreeNode b)
	{
	return (a.pdi).first > (b.pdi).first;
	}

};

void DFS(TreeNode* node, vector<string>& codes)
{
	if (node == nullptr)
		return;
	if (node->left != nullptr)
	{
		(node->left)->code += node->code + "0";
		DFS(node->left, codes);
	}

	if (node->right != nullptr)
	{
		(node->right)->code += node->code + "1";
		DFS(node->right, codes);
	}

	if (node->left == nullptr && node->right == nullptr)
	{
		codes[(node->pdi).second] = node->code;
	}

}

void huffmanCode(vector<double>& probs, vector<string>& codes)
{
	
	priority_queue<TreeNode, vector<TreeNode>, compare> pq;

	int n = probs.size();
	for (int i = 0; i < n; i++)
	{
		pq.push({ {probs[i], i}, "", nullptr, nullptr});
	}

	TreeNode* right_node, left_node;
	while (pq.size() > 1)
	{
		TreeNode first_node = pq.top();
		pq.pop();
		TreeNode second_node = pq.top();
		pq.pop();

		first_node.code = "0";
		second_node.code = "1";
		double combined_prob = first_node.pdi.first + second_node.pdi.first;
		pair_double_int combined_pdi = { combined_prob, -1 };
		pq.push({ combined_pdi, "", &first_node, &second_node });

	}
	TreeNode root = pq.top();
	DFS(&root, codes);

}