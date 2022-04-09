#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

// time:-O(n) space:- O(h) where h is the height of the tree
void printKdist(BinaryTreeNode<int>* root,int k){
	if(root==NULL)
		return;
	if(k==0)
		cout << root->data << endl;
	else{
		printKdist(root->left, k-1);
		printKdist(root->right, k-1);
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	// printTreeLevelWise(root);
	printKdist(root,1);
}