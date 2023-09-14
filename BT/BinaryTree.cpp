#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
class Node 
{
    public:
    int value ; 
    Node* left ; 
    Node* right ; 
    Node(int d)
    {
        value=d ; 
        left=right=nullptr ; 
    }

} ; 
void InsertLevelOrder(Node* root,int value)
{
    Node* nn=new Node(value) ; 
    if (root==nullptr)
    {
        root=nn ; 
        return ; 
    }
    queue<Node*> q ; 
    q.push(root) ; 
    while (!q.empty())
    {
        Node* n=q.front() ; 
        q.pop() ; 
        if(n->left==nullptr)
        {
            n->left=nn ; 
            return ;     
        }
        else if(n->right==nullptr)
        {
            n->right=nn ; 
            return ; 
        }
        q.push(n->left) ; 
        q.push(n->right) ; 
    }
}

int main()
{
    for (int  i = 0; i < 22; i++)
    {
        cout<<"slm"<<endl ; 
    }
    
    return 0 ; 
}