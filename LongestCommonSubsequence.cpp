#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
ll n,m;
vector<vector<ll>> dp;
ll LCS(ll i,ll j)
{
    if(i==n||j==m)
     return 0;
    if(dp[i][j]!=-1)
     return dp[i][j];
    ll ans;
    if(a[i]==b[j])
        ans=1+LCS(i+1,j+1);
    else
     {
         ll ans2,ans3;
         ans2=LCS(i,j+1);
         ans3=LCS(i+1,j);
         ans=max(ans2,ans3);
     }
     return dp[i][j]=ans;
}
int main()
{
    cin>>a>>b;
    n=a.size();
    m=b.size();
    dp=vector<vector<ll>>(n,vector<ll>(m,-1));
    ll ans=LCS(0,0);
    cout<<ans<<endl;
    
}