#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void primeNumbersInRange(int n)//upto n from 0
{  n=n+1;// since array starts from 0
    int primeNumbers[n]={0};//0 indicates prime, 1 indicates not prime

    for(int i=2;i<=sqrt(n);i++)
        if(primeNumbers[i]==0)
        {   int startMarking=i*i;
             while(startMarking<=n)
             { primeNumbers[startMarking]=1;
               startMarking+=i;
             }

        }
    for(int i=2;i<=n;i++)
    if(!primeNumbers[i])
        cout<<i<<endl;

}



const long long MAX_SIZE = 10000001;//1e7 is under 1sec
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
  
// function generate all prime number less then N in O(n)
void manipulated_seive(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false ;
  
    for (long long int i=2; i<N ; i++)
    {  if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
       for (long long int j=0;j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

int main()
{ 
    int N=200;
    primeNumbersInRange(N);

 
    manipulated_seive(N);
    // pint all prime number less then N
    for (int i=0; i<prime.size()&&prime[i] <= N; i++)
        cout << prime[i] << " ";
        cout<<endl;
    for(int i=2;i<=200;i++)
     if(isprime[i])
     cout<<i<<" ";
    return 0;

}