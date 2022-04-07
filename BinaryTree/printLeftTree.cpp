#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

int maxLevel = 0;

void printLeft(BinaryTreeNode<int>* root, int level){
	if(root == NULL)
		return;
	if(maxLevel<level)
	{
		cout << root->data << endl;
		maxLevel = level;
	}

	printLeft(root->left, level+1);
	printLeft(root->right, level+1);
}

void printLeftView(BinaryTreeNode<int>* root){
	printLeft(root,1);
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	// printTreeLevelWise(root);
	printLeftView(root);
}