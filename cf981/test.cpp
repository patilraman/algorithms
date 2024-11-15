#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int tc,n,score=0;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        cin>>n;
        if(n%2)
            cout<<"Sakurako"<<'\n';
        else
           cout<<"Kosuke"<<'\n';
    }
}