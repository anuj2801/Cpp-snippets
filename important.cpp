#include<bits/stdc++.h>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------//

map<pair<long long,long long>,long long> num;
long long  timesDivide(long long n,long long val)// return how many times val divides n, n=(val^ans)*x*y.....;
{
    if(val<=1)
     return -1;
    if(num[{n,val}]!=0)
     return num[{n,val}];
    long long ans=0;
    long long p=1;
    while(n%val==0)
    {
        if(n%(long long)pow(val,p)==0)
        {
           n=n/(long long)pow(val,p);
           ans+=p;
           p+=1;
        }
        else
         p=1;
    }
    return num[{n,val}]=ans;
}

//-------------------------------------------------------------------------------------------------------------------------//

vector<long long> sieve(1e5+1,0);
void fillsieve(long long n)
{
    for (long long x=2;x<=n;x++) 
    {
    if (sieve[x]) 
        continue;
    for(long long u=2*x;u<=n;u+=x)
     { 
        // if(sieve[u]==0)   // to save smallest prime factor of i
        //  sieve[u] = x;

        sieve[u]=x; //to save largest prime factor of i
     }
    }
}

//-------------------------------------------------------------------------------------------------------------------------//

const int MOD=1e9+7;
long long modpow(long long x,long long n)  // find x^n%MOD
{
  if(n==0) 
   return 1;
  long long u=modpow(x,n/2);
  u=(u*u)%MOD;
  if(n%2==1)
    u=(u*x)%MOD;
  return u;
}

//-------------------------------------------------------------------------------------------------------------------------//



int main()
{
    long long n=100;
    fillsieve(n);
    for(int i=0;i<=n;i++)
     cout<<i<<"->"<<sieve[i]
<<endl;    
    
    return 0;
}