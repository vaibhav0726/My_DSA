#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

// Binary tree to doubly linkedlist
// time:- O(n) and space:- O(h) where h is the height of the tree
BinaryTreeNode<int>* prev = NULL;
BinaryTreeNode<int>* BinaryTreeToDLL(BinaryTreeNode<int>* root){
    if(root == NULL)
        return root;
    BinaryTreeNode<int>* head = BinaryTreeToDLL(root->left);
    if(prev == NULL){
        head = root;
    }
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BinaryTreeToDLL(root -> right);
    return head;
}