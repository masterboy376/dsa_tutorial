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

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void calcPointers(node *root, node** first, node** mid, node** last, node** prev)
{
    if (root == NULL)
    {
        return;
    }
    calcPointers(root->left, first, mid, last, prev);
    if(*prev && root->data<(*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void restoreBST(node* root){
    node* first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);
    // case 1
    if(first && last){
        swap(&(first->data), &(last->data));
    }
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}

int main()
{
     node * root = new node(10);
    node * l = new node(15);
    node * ll = new node(3);
    node * lr = new node(9);
    node * r = new node(5);
    node * rr = new node(17);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;
    r->right = rr;

    inorder(root);
    cout<<endl;
    restoreBST(root);
    inorder(root);
    cout<<endl;

    return 0;
}