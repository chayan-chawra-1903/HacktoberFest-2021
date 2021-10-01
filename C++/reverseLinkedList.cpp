#include<iostream>
#include<stack>
using namespace std;

struct node 
{
    int data;
    node* next;
};

node* reverseLinkedlist(node* head)
{
    stack<node*> s;
    node* temp=head;
    while (temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    temp=s.top();
    head=temp;
    s.pop();
    cout<<s.top()->data<<endl;
    while (!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
    
}

node* Insert(node* head,int x)
{
    node* newNode = new node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    return head;
}

void Print(node* head)
{
    cout<<"Currently the list is:";
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}

int main()
{
    node* head = NULL;
    head=Insert(head,1);
    head=Insert(head,2);
    head=Insert(head,3);
    head=Insert(head,4);
    head=Insert(head,5);
    Print(head);
    head=reverseLinkedlist(head);
    Print(head);
}