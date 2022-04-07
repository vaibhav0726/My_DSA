#include <iostream>
#include <queue>
using namespace std;


// The children sum property is defined as, For every node of the tree, 
// the value of a node is equal to the sum of values of its children(left child and right child)

bool childSumPro(BinaryTreeNode<int>* root){
	if(root == NULL ||(root->left == NULL && root->right == NULL))
		return true;

	int sum = 0;
	if(root->left != NULL)
		sum += root->left->data;
	if(root->right !=NULL)
		sum += root->right->data;
	return (root->data == sum && childSumPro(root->left) && childSumPro(root->right));
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	cout << childSumPro(root);
}