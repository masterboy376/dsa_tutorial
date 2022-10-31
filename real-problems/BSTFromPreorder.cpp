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

node* buildBSTFormPreorder (int pre[], int* preIndex, int min, int max, int key, int n){
    if(*preIndex>=n){
        return NULL;
    }

    node* root = NULL;
    if(key>min and key<max){
        root = new node(key);
        *preIndex = *preIndex + 1;
        if(*preIndex<n){
            root->left = buildBSTFormPreorder(pre, preIndex, min, key, pre[*preIndex], n);
        }
        if(*preIndex<n){
            root->right = buildBSTFormPreorder(pre, preIndex, key, max, pre[*preIndex], n);
        }
    }
    return root;
}

node* buildBSTFormPreorder (vector<int> pre,int min, int max){
    static int i = 0;
    if(i>=pre.size()){
        return NULL;
    }

    node* root = NULL;
    if(pre[i]>min and pre[i]<max){
        int val = pre[i];
        root = new node(val);
        i++;
        root->left = buildBSTFormPreorder(pre, min, val);
        root->right = buildBSTFormPreorder(pre, val, max);
    }
    return root;
}

int main()
{
    int pre[] = {7,5,4,6,8,9};
    node* root = NULL;
    int preIndex = 0;
    root=buildBSTFormPreorder(pre,&preIndex,INT32_MIN,INT32_MAX, pre[0], 6);

    preorder(root);
    cout<<endl;
    //------------------------------------------------------------------------
    vector<int> pre2 = {7,5,4,6,8,9};
    root=buildBSTFormPreorder(pre2 ,INT32_MIN ,INT32_MAX);

    preorder(root);
    cout<<endl;

    return 0;
}