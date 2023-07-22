#include<iostream>
#include<queue> 
#include<stack>
#include<map>
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
    cout<<node->data<<" " ; 
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
//Level order traversal of Binary Tree in Spiral form : 
void printSpiralOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    stack<Node*> s;
    bool leftToRight = true;

    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            if (leftToRight)
                cout << current->data << " ";
            else
                s.push(current);

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        if (!leftToRight) {
            while (!s.empty()) {
                Node* temp = s.top();
                s.pop();
                cout << temp->data << " ";
            }
        }

        leftToRight = !leftToRight;
    }
}
void ReverseLevelOrder(Node* root)
{
    if (root==nullptr)
    {
        return ; 
    }
    stack<Node*> s  ;
    queue<Node*> q;
    q.push(root) ;
    while (!q.empty())
    {
        Node* current=q.front() ;
        q.pop() ; 
        s.push(current) ; 
        if(current->right)
        {
            q.push(current->right) ; 
        }
        if (current->left)
        {
            q.push(current->left) ; 
        }
        

    }
    while (!s.empty())
    {
        Node* current=s.top() ; 
        s.pop() ; 
        cout<<current->data<<" " ; 
    }
}
// inorder Traversal using stack 
void inorderTraversalStack(Node* root)
{
    if(root==nullptr)
    {
        return ; 
    }
    stack<Node*> s ; 
    Node* current=root ;
    while (!s.empty()|| current!=nullptr)
    {
         while(current)
         {
             s.push(current)  ; 
             current=current->left ;
         } 
    current=s.top() ; 
    s.pop() ; 
    cout<<current->data<<" "; 
    current=current->right ; 
    }
}
//Find the Maximum Depth or Height of given Binary Tree  using Level Order Traversal : 
int depthLevelOrderTraversal(Node* root)
{
    if(root==nullptr)
    {
        return 0 ; 
    }
    queue<Node*> q ; 
    int hight=0 ; 
    while (!q.empty())
    {
        int size=q.size() ; 
        for (int i = 0; i < size; i++)
        {
            Node* temp=q.front() ; 
            q.pop() ; 
            if (temp->left!=nullptr)
            {
                q.push(temp->left) ; 
            }
            if(temp->right!=nullptr)
            {
                q.push(temp->right) ; 
            }
        }
        hight++ ; 
    }
    return hight ; 
}
// inorderTraversal again 
void inorderTraversal(Node* root)
{
    if(root==nullptr)
    {
        return ; 
    }
    if (root->left!=nullptr)
    {
        inorderTraversal(root->left) ; 
    }
    cout<<root->data<<" " ; 
    if(root->right!=nullptr)
    {
        inorderTraversal(root->right) ; 
    }
}

void preOrder(Node* root)
{
    if(root==nullptr)
    {
        return ; 
    }
    cout<<root->data<<" "; 
    if (root->left)
    {
        preOrder(root->left) ; 
    }
    if(root->right)
    {
        preOrder(root->right) ; 
    }
    
}
Node * constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  Node * root = new Node(preorder[preStart]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}
 Node * buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
// We Pass now to BST
Node* insert(Node* node,int key)
{
    if(node==nullptr)
    {
        Node* newNode=new Node(key) ; 
        return newNode ; 
    }
    if(node->data>key)
    {
        insert(node->left,key) ; 
    }
    else if (node->data <key)
    {
        insert(node->right,key) ; 
    }
    return node ; 
} 
Node* search(Node* node,int value)
{
    if(node==nullptr|| node->data==value)
    {
        return node ; 
    }
    if (value<node->data)
    {
        search(node->left,value) ; 
    }
    else
    {
        search(node->right,value) ; 
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //printCurrentLevel(root,3) ;
    //printSpiralOrder(root) ;  
    //ReverseLevelOrder(root) ;
    vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  Node * root1 = buildTree(preorder, inorder);
  printInorder(root1) ;
   // inorderTraversal(root) ;  
    return 0 ; 
}