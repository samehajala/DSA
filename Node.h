#include<iostream> 
using namespace std ; 
class Node
{
protected:
    int data ; 
    Node *link ; 
public:
    virtual int getData() const=0 ; 
    virtual Node* getNode() const=0 ; 
    Node(Node* ,int);
    Node() ; 
    ~Node();
};
Node::Node(Node* ,int){}
Node::~Node()
{
    delete link ; 
}
class NodeLinkedList :public Node
{
private:  
public:
    NodeLinkedList(Node* ptr,int value):Node(ptr,value){}
    NodeLinkedList(int value); 
    int getData() const ;
    Node* getNode() const ; 
    bool operator<(Node*) ; 
    
};

int NodeLinkedList::getData() const
{
    return data ; 
}
Node* NodeLinkedList::getNode() const 
{
    return link; 
}


