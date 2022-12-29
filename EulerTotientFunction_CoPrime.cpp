#include<bits/stdc++.h>
using namespace std;


// Euler Totient Function (NUMBER of comprime of i present between 1 to i-1)(coprime x,y if->gcd(x,y)=1)
const int MAX=1e6+2;
int tot[MAX];
void totient()
{
   for(int i=0; i<MAX; i++)
     tot[i] = i;              
 
   for(int i=2; i<MAX; i++)
   {
       if(tot[i] == i) // getting a prime number
       {
           tot[i] -= 1; //for prime number n, no. of coprimes between 1 to n is (n-1)
           for(int j=2*i; j<MAX; j+=i)
             tot[j] -= tot[j]/i;  // reducing all multiples of the prime number i
                                  // at the end ,numbers which are not prime will be reduced by factor (1-1/p),where p denotes prime factor of that number
                                  // t*=(1-1/p)   equivalent to  t=t-t/p or t-=t/p

       }
   }
}


int main()
{
    totient();
    for(int i=1;i<=19;i++)
     cout<<tot[i]<<" ";
     cout<<endl;
}
