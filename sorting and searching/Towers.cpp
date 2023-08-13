#include<iostream> 
#include<vector>
#include<set> 
using namespace std ; 
int sollution(vector<int> v)
{
    multiset<int> towers  ; 
    for (int i = 0; i < v.size(); i++)
    {
        if (towers.size()==0)
        {
            towers.insert(v[i]) ; 
        }
        else 
        {
            auto it=towers.upper_bound(v[i]) ; 
            if(it!=towers.end())
            {
                towers.insert(v[i]) ; 
                towers.erase(it) ; 
            }
            else{
                towers.insert(v[i]) ; 
            }
        }
                
    }
    return towers.size() ; 
}
int main()
{
    int n  ; 
    cin>>n ; 
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int c  ; 
        cin>>c ; 
        v.push_back(c) ; 
    } 
    cout<<sollution(v) ; 
    return 0 ; 
}