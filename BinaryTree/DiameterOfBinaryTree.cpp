#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

// naive solution 
// time:- O(n^2)
int diameter(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;
	int d1 = 1+ height(root -> left) + height(root -> right);
	int d2 = diameter(root -> left);
	int d3 = diameter(root -> right);

	return max(d1,max(d2,d3));
}

// method:-2 
// precompute the height of every node and store it in the map


// method:- 3
// using the height function with taking the record of res
// time:- O(n) and space:- O(h) where h is the height O(h) recursive calls
int res = 0;
int diameter3(BinaryTreeNode<int>* root){
	if(root == NULL) return 0;
	int lh = height(root -> left);
	int rh = height(root -> right);
	res = max(res, 1+lh+rh);
	return 1+max(lh, rh);
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	cout << diameter(root);
}