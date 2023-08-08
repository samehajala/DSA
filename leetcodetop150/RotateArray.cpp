#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std ;
void rotate(vector<int>& nums, int k)
{
    for (int i = 0; i < k; i++)
    {
        nums.insert(nums.begin(),nums[nums.size()-1]);
        nums.pop_back() ;  
    }
} 
int main()
{
    vector<int> v={1,2,3,4,5,6,7} ; 
    rotate(v,3) ; 
    for (int i = 0; i <v.size(); i++)
    {
        cout<<v[i]<<endl ; 
    }
    
    return 0 ; 
}