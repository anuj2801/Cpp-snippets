#include<bits/stdc++.h>
using namespace std;
vector<long long> no_of_divisors(1e6+7,0);
void count_divisors()
{
    // seiveoferastosthenes
    for(int i=1;i<=1e6+2;i++)
     for (int j=i;j<=1e6+2;j+=i)
       no_of_divisors[j]++;
}
int main()
{
   //print divisors of 1 to n,1<= n<=10^6
   count_divisors();
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cout<<no_of_divisors[i]<<endl;
   }
}