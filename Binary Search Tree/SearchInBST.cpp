#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

bool search(BinaryTreeNode<int>* root, int key){
	if(root == NULL)
		return false;

	if(root -> data  == key)
		return true;

	else if(root -> data > key)
		return search(root -> left, key);
	else
		return search(root -> right, key);
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	cout << search(root, 70);
}