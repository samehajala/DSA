#include<iostream>
#include<queue> 
using namespace std ; 
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value )
    {
        data=value ; 
        left=nullptr ; 
        right=nullptr ; 
    }
};
// Tree Traversal Techniques
void printInorder(Node* node){
    if (node==nullptr)
    {
        return ; 
    }
    printInorder(node->left) ; 
    cout<<node->data ; 
    printInorder(node->right)  ; 

}  
void printPreOrder(Node* node)
{
    if (node==nullptr)
    {
        return ; 
    }
    cout<<node->data ; 
    printPreOrder(node->left) ; 
    printPreOrder(node->right) ;  
}
void printPostOrder(Node* node)
{
    if(node==nullptr)
    {
        return ; 
    }
    printPostOrder(node->left) ; 
    printPostOrder(node->right) ; 
    cout<<node->data ; 
}
// Print Level Order Technique
int height(Node* node)
{
    if(node==nullptr)
    {
        return 0 ; 
    }
    int lheight=height(node->left)  ; 
    int rheight=height(node->right) ; 
    if (lheight>rheight)
    {
        return(lheight+1) ; 
    }
    else
    {
        return rheight+1 ; 
    }
    
}
void printCurrentLevel(Node* root, int level)
{
    if (root==nullptr)
    {
        return ; 
    }
    if (level==1)
    {
        cout<<root->data<<endl ; 
    }
    printCurrentLevel(root->left,level-1) ;
    printCurrentLevel(root->right,level-1) ;  
}
void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
//Level Order Insertion in a Binary Tree 
Node* insertNode(Node* root,int data )
{
    if(root==nullptr)
    {
       root=new Node(data) ; 
       return root ; 
    }
    queue<Node*> nodes ; 
    nodes.push(root) ; 
    Node* newNode=new Node(data) ; 
    while (!nodes.empty())
    {
        Node * node=nodes.front() ; 
        nodes.pop() ; 
        if (node->left==nullptr)
        {
            node->left=newNode ; 
            return root ; 
        }
        else if (node->right==nullptr)
        {
            node->right=newNode ; 
            return root ; 
        }
        else
        {
            nodes.push(node->left) ; 
            nodes.push(node->right) ; 
        } 
    }
    
}
int main()
{
    
    return 0 ; 
}