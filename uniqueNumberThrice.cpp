#include <iostream>
using namespace std;
int bitToNumber(int _64bits[])
{
    int ans=0;
    for(int i=0;i<64;i++)
        ans+=_64bits[i]*(1<<i);
    return ans;
}
int uniqueNumber(int a[],int len)
{
    int _64[64]={0};// otherwise junk willbe there
    for(int i=0;i<len;i++)
    {  
        int j=0;
        while(a[i]!=0)
        {  
          if(((a[i]>>1)<<1)!=a[i])
           _64[j]++;
           j++;
           a[i]>>=1;
        
        }

    }
    for(int i=0;i<64;i++)
    _64[i]%=3;
    return bitToNumber(_64);
}
int main()
{
    int a[10]={8,2,7,9,7,2,8,2,8,7};
    cout<<uniqueNumber(a,10);
    return 0;
}
