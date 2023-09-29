#include<iostream> 
#include<vector>
#include<unordered_map>
using namespace std ; 
class Node
{
public:
   int data ; 
   vector<Node*> childs  ; 
   Node(int d )
   {
    data=d ; 
   }
};
int dfs(int node ,unordered_map<int,Node*> &mp , vector<int> &answer)
{
    if (mp[node]->childs.size()==0)
    {
        return 1 ; 
    }
    for(auto ch : mp[node]->childs)
    {
        answer[node]+=dfs(ch->data,mp,answer) ; 
    }
    return answer[node]+1 ;
}
int main()
{
    int n ;
    cin>>n ; 
    int x; 
    unordered_map<int ,Node*> mp ;
    for(int i=1;i<=n;i++)
    {
        mp[i]=new Node(i) ; 
    }
    for(int i=2;i<=n;i++)
    {
        cin>>x ; 
        mp[x]->childs.push_back(mp[i]) ;
        

    }
    vector<int> answer(n+1,0) ; 
    dfs(1,mp,answer) ;
    for(int i=1;i<=n;i++)
    {
        cout<<answer[i]<<" " ; 
    } 
}