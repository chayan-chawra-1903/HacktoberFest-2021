#include<iostream>
using namespace std;

struct node 
{
    int data;
    node* next;
};

node* Insert(node* head,int x)
{
    node* newNode = new node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    return head;
}

node* Insertatn(node* head,int x,int n)
{
    node* newNode = new node();
    newNode->data=x;
    newNode->next=NULL;
    
    if (n==1)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }
    
    n-=2;
    node* temp=head;
    while (temp->next!=NULL && n--)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}

node* Deleteatn(node* head,int n)
{
    node* temp = head;
    if (n==1)
    {
        head = head->next;
        delete temp;
        return head;
    }
    
    n=n-2;
    while (temp->next!=NULL && n--)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        cout<<"The last number is: "<<temp->data<<endl;
        delete temp;
        return head;
    }
    node* deletedNode = temp->next;
    temp->next=deletedNode->next;
    delete deletedNode;
    return head;   
}

node* Reverse(node* head)
{
    node* current = head;
    node *prev,*next;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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

void Printrecursive(node* head)
{
    if (head==NULL)
    {
        cout<<"\n";
        return;
    }
    
    cout<<head->data<<" ";
    Printrecursive(head->next);
}

void Reverseprintrecursive(node* head)
{
    if (head==NULL)
    {
        return;
    }
    Reverseprintrecursive(head->next);
    cout<<head->data<<" ";
}

node* RecursiveReverse(node* head)
{
    if (head== NULL || head->next==NULL)
    {
        return head;
    }
    node* p = RecursiveReverse(head->next);
    head->next->next=head;
    head->next = NULL;
    return p;
}

int main()
{
    node* head;
    head=NULL;
    int n,x;
    cout<< "Enter the amount of numbers: ";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the number to be inserted: ";
        cin>>x;
        head = Insert(head,x);
        Print(head);
    }
    head = Insertatn(head,6,5);
    Print(head);

    head = Deleteatn(head,6);
    Print(head);

    head = Reverse(head);
    cout<<"After reversing:"<<endl;
    Print(head);
    Printrecursive(head);
    Reverseprintrecursive(head);
    cout<<"\n";

    head = RecursiveReverse(head);
    Print(head);
}