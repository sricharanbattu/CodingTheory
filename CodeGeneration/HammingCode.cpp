/*
#include "Libraries.h"
using namespace std;

struct node {
	double prob;
	node* left;
	node* right;
};

bool compare(node* a, node* b)
{
	return a->prob < b->prob;
}

node* HammingCode(vector<node*> nodes, int n)
{


	sort(nodes.begin(), nodes.end(), compare);
	int n = nodes.size();
	if (n == 1)
		return nodes[0];

	double prob_comb = nodes[n - 1]->prob + nodes[n - 2]->prob;

	node* new_node = new node;


}

*/