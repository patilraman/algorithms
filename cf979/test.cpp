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
        vector<int> arr(n);//,0);
        vector<int> b(n);//,0);
        vector<int> c(n);//,0);
        int max = 0, min =1000;
        for(int j=0;j<n;j++)
        {
           cin>>arr[j];
           if(j!=0)
           {
                max = max>arr[j]?max:arr[j];
                min = min<arr[j]?min:arr[j];
           }
           else max=min=arr[0];
        }
        score = (n-1)*(max-min);
        cout<<score;
    }
}