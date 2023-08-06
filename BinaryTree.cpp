#include<iostream>
#include<vector>
using namespace std ;
class Node 
{
    public:
    int value ; 
    vector<Node*> child ; 
    Node(int d)
    {
        value=d ; 
    }

} ; 
int main()
{

    return 0 ; 
}