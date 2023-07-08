#include<iostream> 
using namespace std ; 
struct Node
{
    int data ; 
    Node* link ; 
}; 
void push(Node **head , int newDAta)
{
    Node* newNode=new Node() ; 
    newNode->data=newDAta ; 
    newNode->link=*head ; 
    *head=newNode;  
    return ; 
}
void Append(Node **head,int newData)
{
    Node* newNode=new Node() ; 
    newNode->data=newData ; 
    newNode->link=nullptr ;
    if(*head==nullptr)
    {
        *head=newNode ; 
        cout<<newNode->data<<endl ; 
        return ; 
    } 
    Node *last=*head ; 
    while (last->link!=nullptr)
    {
        
        last=last->link ; 
    }
    cout<<newNode->data<<endl ;
    last->link=newNode ; 
    return ; 
}

int main()
{
    Node* A = nullptr ; 
    for (int i = 0; i < 10; i++)
    {
    Append(&A,i) ;  
    }
    push(&A,20) ; 
    cout<<A->data<<endl ; 
    return 0 ; 
}