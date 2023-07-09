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
void insertAfter(Node* prev,int newData)
{
    if(prev==nullptr)
    {
        cout<<"Previous can't be null "<<endl ; 
        return ; 
    }
    Node* newNode=new Node() ; 
    newNode->data=newData  ;
    newNode->link=prev->link ;  
    prev->link=newNode ; 
    return ; 
}
void deleteNode(Node **head ,int pos) 
{
    if(*head==nullptr)
    {
        return ; 
    }
    Node* temp=*head ; 
    if (pos==1)
    {
        *head=temp->link ; 
        delete(temp) ; 
    }
    Node* current=nullptr ; 
    int i=1 ; 
    while (i<pos && temp!=nullptr)
    {
        i++ ; 
        current=temp ; 
        temp=temp->link ; 
    }
    current->link=temp->link ; 
    delete(temp ) ; 
    return ; 
    
}
void printLinkedList(Node* head)
{
    if(head==nullptr)
    { 
        cout<<"Empty"<<endl ; 
        return ; 
    }
    while(head!=nullptr)
    {
        cout<<head->data<<endl ; 
        head=head->link ; 
    }
    return ; 
}
int main()
{
    Node* A = nullptr ; 
    push(&A,1) ; 
    push(&A,2) ; 
    push(&A,3) ; 
    push(&A,4) ; 
    push(&A,5) ; 
    push(&A,6) ; 
    push(&A,7) ; 
    push(&A,8) ;
    push(&A,9) ; 
    printLinkedList(A) ; 
    deleteNode(&A,5) ; 
    printLinkedList(A) ; 
    return 0 ; 
}