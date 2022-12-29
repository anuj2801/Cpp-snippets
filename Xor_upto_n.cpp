#include<iostream>
using namespace std;
#define ll long long
ll computeXOR(ll n)
{
  if(n%4==0)
    return n;
  if(n%4==1)
    return 1;
  if(n%4==2)
    return n+1;
  return 0;
}
int main()
{
    ll n;
    cin>>n;
    cout<<computeXOR(n)<<endl;
    return 0;
}