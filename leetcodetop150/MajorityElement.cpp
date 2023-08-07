#include<iostream>  
#include<vector> 
#include<algorithm>
using namespace std ; 
 int majorityElement(vector<int>& nums) {
        int majority=nums[0] ; 
        int count=1 ;
        for(int i=0;i<nums.size();i++)
        {
            if(majority==nums[i])
            {
                count++ ; 
            }
            else 
            {
                count-- ; 
                if(count==0)
                {
                    count=1 ; 
                    majority=nums[i] ; 
                }
            }
        }  
        return majority ; 
    }
int main()
{
    vector<int> v={2,2,1,1,1,2,2} ; 
    int max=majorityElement(v) ; 
    cout<<max; 
    return 0 ; 
}