#include<iostream> 
using namespace std ; 
void toirOfHanoi(int n ,char src ,char dest,char temp)
{
    if(n>0)
    {
        toirOfHanoi(n-1,src,temp,dest) ; 
        cout<<"mooving the disk number "<<n<<" from "<<src<<" To "<<dest<<endl ; 
        toirOfHanoi(n-1,temp,dest,src) ; 
    }
    return  ;
}
int main()
{
    toirOfHanoi(3,'A','C','B') ; 
    return 0 ; 
}