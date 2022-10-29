#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

node *search(node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    if (target < root->data)
    {
        return search(root->left, target);
    }
    return search(root->right, target);
}

node* inorderSucc(node* root){
    node* curr = root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* deleteNode(node* root, int target){
    if(root==NULL){
        return NULL;
    }
    if(target<root->data){
        root->left= deleteNode(root->left, target);
    }
    else if(target>root->data){
        root->right= deleteNode(root->right, target);
    }
    else{
        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            node* temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right= deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/*
            5
          /   \
        1      7
         \
          3
         / \
        2   4
*/

int main()
{
    node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);

    inorder(root);
    cout << endl;

    if (search(root, 6) != NULL)
    {
        cout << "exist" << endl;
    }
    else
    {
        cout << "not exist" << endl;
    }

    root= deleteNode(root,5);
    inorder(root);
    cout << endl;

    return 0;
}