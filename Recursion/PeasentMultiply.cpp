#include<iostream> 
#include <cmath>
using namespace std ;
int peasantMultiply(int a , int b)
{
    if (a==0 || b==0)
    {
        return 0 ; 
    }
    else 
    {
        int a1=a/2 ; 
        int b2=b*2 ; 
        int prod= peasantMultiply(a1,b2) ; 
        if(a%2==0)
        {
           return prod ; 
        }
        else 
        {
            return prod+1 ; 
        }
    }
} 
int main()
{
    
    return 0 ; 
}