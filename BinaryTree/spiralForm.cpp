#include <iostream>
#include<queue>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

// method:-1
void spiralForm(BinaryTreeNode<int>* root){

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	bool reverse = false;
	stack<int> s;

	while(q.size() != 0){
		int count = q.size();
		for(int i=0; i<count; i++){
			BinaryTreeNode<int>* front = q.front();
			q.pop();
			if(reverse)
				s.push(front -> data);
			else
				cout << front -> data << ",";
			if(front -> left != NULL)
				q.push(front -> left);
			if(front -> right != NULL)
				q.push(front -> right);
		}
		if(reverse){
			while(s.empty() == false){
				cout << s.top() << ",";
				s.pop();
			}
		}
		reverse = !reverse;
		cout << endl;
		
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	spiralForm(root);
}