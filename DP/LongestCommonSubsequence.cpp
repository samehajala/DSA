#include<iostream>
#include<vector>
using namespace std ; 
int SollutionRec(int x,int y,string str1,string str2)
{
    if(x==0 || y==0)
    {
        return 0 ; 
    }
    if (str2[y-1]==str1[x-1])
    {
        return 1+SollutionRec(x-1,y-1,str1,str2) ; 
    }
    else 
    {
        return max(SollutionRec(x-1,y,str1,str2),SollutionRec(x,y-1,str1,str2)) ; 
    }
    
}
int dp[101][101] ; 
int SollutionDp(int n ,int m,string str1,string str2)
{
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=m;j++)
        {
            if (i==0 || j==0)
            {
                dp[i][j]=0 ; 
            }
            if (str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1] ; 
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]) ; 
            }
                                    
        }
        
    }
    return dp[n][m]   ; 
}
int main()
{

    return 0 ; 
}