#include<iostream> 
#include<vector>
using namespace std ; 
void fillingShapes(int n)
{
    vector<int> dp ; 
    dp.push_back(1) ; 
    dp.push_back(0)  ; 
    for(int i=2;i<=n;i++)
    {
        dp.push_back(2*dp[i-2]) ; 
    }
    cout<<dp[n]<<endl ; 

}
int main()
{
    int n ; 
    cin>>n ; 
    fillingShapes(n) ; 
    return 0 ; 
}