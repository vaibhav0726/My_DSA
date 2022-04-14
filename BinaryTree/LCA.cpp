#include<iostream>
#include<vector>
#include "BinaryTreeNode.h"

// LCA:- Lowest common ancestor

// method:-1 
// time:- 0(n) requires three traversal of the tree
// space:- O(n) for storing the nodes in the vector
bool findPath(BinaryTreeNode<int>* root, vector<BinaryTreeNode<int>*> &p, int n){
	if(root == NULL) 
		return false;
	p.push_back(root);
	if(root -> data == n) 
		return true;
	if(findPath(root -> left, p, n) || findPath(root -> right, p, n))
		return true;
	p.pop_back();

	return false;
}

BinaryTreeNode<int>* lca(BinaryTreeNode<int>* root, int n1, int n2){
	vector<BinaryTreeNode<int>*> path1, path2;
	if(findPath(root, path1, n1)==false || findPath(root, path2, n2)==false)
		return NULL;
	for(int i=0;i<path1.size()-1 && i<path2.size()-1; i++){
		if(path1[i+1] != path2[i+1] )
			return path1[i];
	}
	return NULL;
}

// method:- 2 assuming the keys are present in the tree 
// time:- O(n) space:- 0(h)

BinaryTreeNode<int>* lca2(BinaryTreeNode<int>* root, int n1, int n2){
	if(root == NULL)
		return NULL;
	if(root -> data == n1 || root -> data == n2)
		return root;
	BinaryTreeNode<int>* lcaLeft = lca2(root -> left , n1, n2);
	BinaryTreeNode<int>* lcaRight = lca2(root -> right , n1, n2);

	if(lcaLeft != NULL && lcaRight != NULL)
		return root;

	if(lcaLeft != NULL)
		return lcaLeft;
	else
		return lcaRight;
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	BinaryTreeNode<int>* same = lca2(root, 13, 70);
	cout << same -> data << endl; 
}