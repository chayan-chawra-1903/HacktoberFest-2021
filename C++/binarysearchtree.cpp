#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* newnode = new Node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

Node* insertNode(Node* root,int data)
{
    if (root==NULL)
    {
        root = newNode(data);
    }
    else if (data<=root->data)
    {
        root->left = insertNode(root->left,data);
    }
    else
    {
        root->right = insertNode(root->right,data);
    }
    return root;
}

bool numberPresent(Node* root,int data)
{
    if (root==NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    else if(data<root->data)
    {
        return numberPresent(root->left,data);
    }
    else
    {
        return numberPresent(root->right,data);
    }    
}

map<string,int> findMinMax(Node* root)
{
    map<string,int> minmax;
    minmax["min"] = -1;
    minmax["max"] = -1;
    if(root==NULL)
    {
        return minmax;
    }
    Node* temp = root;
    while (temp->left!=NULL)
    {
        temp=temp->left;
    }
    minmax["min"] = temp->data;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    minmax["max"]=root->data;

    return minmax;
}

int heightofTree(Node* root)
{
    if (root==NULL)
    {
        return -1;
    }
    return max(heightofTree(root->left),heightofTree(root->right))+1;  
}

void preOrder(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        cout<<q.front()->data<<" ";
        if (q.front()->left!=NULL) q.push(q.front()->left);
        if (q.front()->right!=NULL) q.push(q.front()->right);
        q.pop();
    }
}

Node* deleteNode(Node* root,int data)
{
    if (root==NULL)
    {
        return NULL;
    }
    if(data < root->data)
    {
        root->left = deleteNode(root->left,data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right,data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            int maxEle = findMinMax(root->right)["min"];
            cout<<root->data<<endl;
            cout<<maxEle<<endl;
            root->data = maxEle;
            root->right = deleteNode(root->right,maxEle);
        }
    }
    return root;    
}

int main()
{
    Node* root=NULL;
    root = insertNode(root,12);
    root = insertNode(root,15);
    root = insertNode(root,10);
    root = insertNode(root,14);
    root = insertNode(root,100);
    root = insertNode(root,167);
    root = insertNode(root,1000);
    root = insertNode(root,1);
    root = insertNode(root,8);




    cout<<numberPresent(root,16)<<endl;

    map<string,int> minmax = findMinMax(root);
    cout<<"Min: "<<minmax["min"]<<endl;
    cout<<"Max: "<<minmax["max"]<<endl;

    cout<<heightofTree(root)<<endl;

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;

    root = deleteNode(root,1000);
    inOrder(root);
    cout<<endl;
    root = deleteNode(root,12);
    inOrder(root);
    cout<<endl;

    root = deleteNode(root,100);
    inOrder(root);
    cout<<endl;
    return 0;
}