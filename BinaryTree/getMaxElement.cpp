#include<iostream>
#include<climits>
#include <algorithm>
#include "BinaryTreeNode.h"
using namespace std;

// time:- O(n) space:-O(h)
int getMax(BinaryTreeNode<int>* root){
	if(root==NULL){
		return INT_MIN;
	}

	return max(root->data,max(getMax(root->left), getMax(root->right)));
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	// printTreeLevelWise(root);
	// printKdist(root,1);
	cout << getMax(root);
}