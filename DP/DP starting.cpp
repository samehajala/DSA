#include<iostream>
using namespace std ;
#include<vector>
// number of ways we can form a number N using the sum of the 3 given numbers {1,3,5} 
int state(int n)
{
    vector<int> dp(n+1,-1) ; 
    if (n<0)
    {
        return 0 ; 
    }
    if(n==0)
    {
        return 1 ; 
    }
    if (dp[n]!=-1)
    {
        return dp[n] ; 
    }
    dp[n]=dp[n-1]+dp[n-3]+dp[n-5] ; 
    return dp[n] ; 
} 
long long catalanNumber(int n)
{
    vector<int> dp(n+1,-1) ;  
    if(n<0)
    {
        return 0 ; 
    }
    if (n==0)
    {
        dp[n]=1 ; 
    }
    if (dp[n]!=-1)
    {
        return dp[n] ; 
    } 
    else
    {
        for (int i = 0; i <=n; i++)
    {
        dp[i]= catalanNumber(i)*catalanNumber(n-i-1) ;   
    }
    return dp[n] ; 
    }
    
}

int main()
{
    return 0 ; 
}