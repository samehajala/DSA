#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 
int main()
{
    int n,x ; 
    cin>>n ; 
    cin>>x ; 
    vector<int> v ; 
    while (n--)
    {
        int c ; 
        cin>>c ; 
        v.push_back(c) ; 
    }
    sort(v.begin(),v.end()) ; 
    int i=0 ; 
    int j=v.size()-1 ; 
    int countGuandola=0 ; 
    while (i<=j)
    {
        if (v[j]+v[i]>x)
        {
            countGuandola++ ; 
            j-- ; 
        }
        else 
        {
            countGuandola++ ; 
            i++ ; 
            j-- ; 
        }
        
    }
    cout<<countGuandola ; 
    
}