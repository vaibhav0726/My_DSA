#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

void inorderMorris(BinaryTreeNode<int>* root){
	BinaryTreeNode<int>* curr = root;
	while(curr != NULL){
		// left is null then print the node and go to right
		if(curr -> left == NULL){
			cout << curr -> data << " ";
			curr = curr -> right;
		}
		else{
			// find the predecessor 
			BinaryTreeNode<int>* predecessor = curr -> left;
			// To find predecessor keep going right till right node is null or right is not current
			while(predecessor -> left != curr && predecessor -> right != NULL){
				predecessor = predecessor -> right;
			}

			// if right node is null then go left after establishing link from predecessor current
			if(predecessor -> right == NULL){
				predecessor -> right = curr;
				curr = curr -> left;
			}
			else{ // left is already visit. go right after visiting current
				predecessor -> right = NULL;
				cout << curr -> data << " ";
				curr = curr -> right;
			}
		}
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	inorderMorris(root);
}