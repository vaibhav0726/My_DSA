#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

// method:- 1
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

// method:- 2
// time:- O(n) space:-0(n) (theta n) or O(n)
void printLevelLineByLine(BinaryTreeNode<int>* root){
	if(root == NULL)
		return ;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(q.size()!=0){
		int count = q.size();
		for(int i=0; i<count; i++){
			BinaryTreeNode<int>* front = q.front();
			q.pop();
			cout << front->data << " ";
			if(front->left != NULL)
				q.push(front->left);
			if(front->right != NULL)
				q.push(front->right);
		}
		cout << endl;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	printLevelLineByLine(root);
}