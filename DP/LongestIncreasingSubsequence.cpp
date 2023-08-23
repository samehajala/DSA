#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 
void sollution(vector<int> nums)
{
    sort(nums.begin(),nums.end()) ; 
    int n =nums.size() ; 
    vector<int> b ; 
    vector<int> c  ; 
    b.push_back(nums[0]) ; 
    int i=1 ; 
    while ((nums[i]==nums[i-1]) && i<n)
    {
        b.push_back(nums[i]) ;
        i++ ;  
    }
    while (i<n)
    {
        c.push_back(nums[i]) ; 
        i++ ; 
    }
    if (b.size()==0 || c.size()==0)
    {
        cout<<"-1"<<endl  ; 
        return ; 
    }
    else
    {
        cout<<b.size()<<" "<<c.size()<<endl ; 
        for (int i = 0; i < b.size(); i++)
        {
            cout<<b[i]<<" " ; 
        }
        cout<<endl ; 
        for (int i = 0; i < c.size(); i++)
        {
            cout<<c[i]<<" " ; 
        }
        cout<<endl ;
        return  ; 
    }
    
    
}
int main()
{
    int t ; 
    cin>>t ; 
    while (t--)
    {
        int n ; 
        cin>>n ; 
        vector<int> nums ;
        while (n--)
        {
            int c ; 
            cin>>c ; 
            nums.push_back(c) ; 
        }
        // sollution will be treated here :)    
        sollution(nums) ;  
    }
    
    return 0 ; 
}