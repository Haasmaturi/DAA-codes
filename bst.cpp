#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int value){
        data=value;
        left=right=NULL;
    }
};

Node*insert(Node*root,int value){
    if(root==NULL)
        return new Node(value);

    if(value<root->data)
        root->left=insert(root->left,value);
    else if(value>root->data)
        root->right=insert(root->right,value);

    return root;
}

Node*findMin(Node*root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}

Node*deleteNode(Node*root,int value){
    if(root==NULL)
        return root;

    if(value<root->data)
        root->left=deleteNode(root->left,value);
    else if(value>root->data)
        root->right=deleteNode(root->right,value);
    else{
        if(root->left==NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }

        Node*temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }

    return root;
}

void inorder(Node*root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    Node*root=NULL;
    int n,x,k;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }

    cout<<"Inorder: ";
    inorder(root);

    cin>>k;
    root=deleteNode(root,k);

    cout<<"\nAfter deletion: ";
    inorder(root);

    return 0;
}