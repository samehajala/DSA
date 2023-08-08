#include<iostream> 
#include<vector>
using namespace std ; 
long long fibDp(int n)
{
    vector<long long> dp ; 
    if(n<2)
    {
        return n ; 
    }
    dp.push_back(0) ; 
    dp.push_back(1) ;
    for(int i=2;i<n+1;i++)
    {
        dp.push_back(dp[i-1]+dp[i-2]) ; 
    }
    return dp[n] ; 
}
int fibRec(int n)
{
    if(n<2)
    {
        return n ; 
    }
    else
    {
        return fibRec(n-1) +fibRec(n-2) ;
    }
}
int main()
{
    cout<<fibDp(10)<<endl ; 
    return 0 ; 
}