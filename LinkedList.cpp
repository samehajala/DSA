#include<iostream> 
#include<stack>
using namespace std ; 
struct Node
{
    int data ; 
    Node* link ; 
}; 
void push(Node**head , int newDAta)
{
   Node* newNode=new Node() ; 
    newNode->data=newDAta ; 
    newNode->link=nullptr ; 
    if (*head==nullptr)
    {
        *head=newNode ; 
        return ; 
    }
    newNode->link=*head ; 
    *head=newNode ; 
    return ; 
}
void printCircLinkedList(Node* head)
{
    Node* temp=head ;
    if(temp==nullptr)
    {
        return ; 
    } 
    while (temp->link!=head)
    {
        cout<<temp->data<<endl ;
         temp=temp->link ; 
    }
    cout<<temp->data ; 
    
}
void pushC(Node** head_ref, int data)
{   
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->link = *head_ref;   
    if (*head_ref != NULL) {     
        Node* temp = *head_ref;
        while (temp->link != *head_ref)
            temp = temp->link;
        temp->link = ptr1;
    }
    else
 
        // For the first node
        ptr1->link = ptr1;
 
    *head_ref = ptr1;
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
    if(*head==nullptr || pos==0)
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
int getCount(Node* head)
{ 
    if (head==nullptr)
    {
        return 0  ; 
    }
    int count=0 ; 
    while (head!=nullptr)
    {
        count++ ;
        head=head->link ; 
    }
    return count ;    
}
// reversing aa linked list using a stack mmm nice XD 
void reverseLinkedList(Node** head)
{
    if((*head)==nullptr )
    {
        return ; 
    }
    if((*head)->link==nullptr)
    {
        return ; 
    }
    stack<Node*> nodes ; 
    Node* temp=*head ; 
    while (temp->link!=nullptr)
    {
        nodes.push(temp) ; 
        temp=temp->link ; 
    }
    *head=temp ; 
    while(!nodes.empty())
    {
        temp->link=nodes.top() ; 
        nodes.pop() ; 
        temp=temp->link ; 
    }
    temp->link=nullptr ; 
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
    Node* C=nullptr ; 
    pushC(&C,5) ; 
    pushC(&C,8) ;
    pushC(&C,6) ;
    printCircLinkedList(C) ;   
    /*
    int count=getCount(A) ; 
    //cout<<count<<endl ; 
    printLinkedList(A) ; 
    cout<<endl ; 
    reverseLinkedList(&A) ; 
    printLinkedList(A) ; 
    //deleteNode(&A,5) ; 
    //count=getCount(A) ; 
    //cout<<count<<endl ;*/ 
    return 0 ; 
}