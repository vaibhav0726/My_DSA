#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;


// time:- O(n+h) space:-0(w) or O(n) where w is the width of the tree
void printLevelLineByLine(BinaryTreeNode<int>* root){
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		BinaryTreeNode<int>* front = q.front();
		q.pop();

		if(front==NULL){
			cout<<endl;
			q.push(NULL);
			continue;
		}

		cout << front->data;

		if(front->left!=NULL)
			q.push(front->left);
		if(front->right!=NULL)
			q.push(front->right);
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	printLevelLineByLine(root);
}