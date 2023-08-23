#include<iostream>
#include<vector>
using namespace std ; 
void solve(vector<int> v,int sum)
{
     if (sum % (v.size() - 1) == 0) {
        int target = sum / (v.size() - 1);
        
        // Check if every element can be transformed to the target
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != target) {
                cout << "NO" << endl;
                return;
            }
        }
        
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}
int main()
{
    int t ; 
    cin>>t ; 
    while (t--)
    {
        int n  ; 
        cin>>n ; 
        vector<int> v ; 
        int sum=0 ; 
        for (int i = 0; i <n ; i++)
        {
            int c ; 
            cin>>c ; 
            v.push_back(c) ; 
            sum+=c ; 
        }
        solve(v,sum) ;  
    }
    
    return 0 ; 
}