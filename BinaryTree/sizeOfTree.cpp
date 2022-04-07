#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

// basically the size of the tree
// time:-O(n) space:- O(h) or 0(h)
int numNodes(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;

	return 1 + numNodes(root->left) + numNodes(root->right);
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	printLevelLineByLine(root);
}
