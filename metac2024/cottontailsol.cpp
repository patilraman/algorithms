#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

long A=12345678987654321;
long h1=123456789;
long h2=87654321;
long list[45];
#define MAXDIGIT 17

void preparelist()
{
    int digits = (17-2);
    int j=0;
    list[j++] = A;
    while(digits >= 3)
    {
        long tmp1 = h1;
        long tmp2 = h2;
        int k=digits/2;
        int kk=9-k-1;
        long tst = (pow(10,k+1));
        long tst2h = (pow(10,k));
        for(int i=(9-k);i>0;i--)
        {
            long ph1 = tmp1/pow(10,kk+1-i);
            ph1 = ph1%tst;
            long ph2 = tmp2/(pow(10,i-1));
            ph2 = ph2%tst2h;
            list[j++] = ph1*tst2h+ph2;
        }
        digits -=2;
    }

    for(int i=9;i>0;i--) 
        list[j++] = i;

    for(int i=0,j=44;i<j;i++,j--) 
    {
        long tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
    }
}

int findrange(long A,long B, long M)
{
    int pw=9;
    int i=0,j=44,mid=22;
    long low=0, high=0;
    cout<<"A="<<A<<"B="<<B<<'\n';
    while(i<j)
    {
        if(A> list[mid])
        {
            low = mid+1;
            i = mid+1;
        }
        else
        {
            low = mid-1;
            if(A==list[mid])
            {
                low = mid;
                break;
            }
            j = mid-1;
        }
        mid = (i+j)/2;
    }
    i=0;
    j=44;
    mid=22;
    while(i<j)
    {
        if(B> list[mid])
        {
            high = mid+1;
            i = mid+1;
        }
        else
        {
            high = mid-1;
            if(B==list[mid])
            {
                high = mid;
                break;
            }
            j = mid-1;
        }
        mid = (i+j)/2;
    }

    int cnt=0;
    for(int i=low;i<=high;i++)
    {
        if((list[i]>=A)&&(list[i]<=B))
            if(list[i]%M==0) cnt++;
    }

    return cnt;
}

int main()
{
    ifstream inFile;
    ofstream outFile;

    long x,y,z;
    inFile.open("cottontail_climb_part_1_input.txt");
    outFile.open("output.txt");

    preparelist();

    if((!inFile)&&(!outFile)){
        cout<<"file open failed"<<'\n';
        exit(1);
    }
    int index=0;
    int tc;
    inFile>> tc;
    cout<<"Total case#"<<tc<<'\n';

    while(tc--){
        inFile>>x>>y>>z;
        cout<<"Case #"<<index<<":"<<findrange(x,y,z)<<'\n';
        outFile<<"Case #"<<++index<<": "<<findrange(x,y,z)<<'\n';
    }
}