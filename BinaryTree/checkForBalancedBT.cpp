#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

// int height(BinaryTreeNode<int>* root){
// 	if(root==NULL)
// 		return 0;

// 	return 1+ max(height(root->left), height(root->right));
// }


// method:-1 
// time :- O(n^2) 
bool checkBT(BinaryTreeNode<int>* root){
	if(root == NULL)
		return true;
	int Lheight = height(root->left);
	int Rheight = height(root->right);

	return ( abs(Lheight - Rheight <=1) && checkBT(root->left) && checkBT(root->right));
}

// method:- 2 Efficient approach
// time:- O(n)
// here we are using height and checking the balanced tree in on function
int isBalanced(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;

	int Lheight = isBalanced(root->left);
	if(Lheight == -1)
		return -1;

	int Rheight = isBalanced(root->right);
	if(Rheight == -1)
		return -1;

	if(abs(Lheight- Rheight) >1)
		return -1;
	else 
		return max(Lheight , Rheight) + 1;
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	if(isBalanced(root) <= 1)
		cout << "Balanced";
	else 
		cout << "Not Balanced";

	cout << endl;

	if(checkBT(root) == true)
		cout << "Balanced";
	else 
		cout << "Not Balanced";
}