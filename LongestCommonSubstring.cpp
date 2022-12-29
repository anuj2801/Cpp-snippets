#include<bits/stdc++.h>
using namespace std;
#define ll long long
 vector<vector<ll>> dp2,dp3;
ll find_ans(ll i,ll j,string &a,string &b,ll &n,ll &m,ll &ans)
{
    if(i==n||j==m)
     return 0;
    if(dp2[i][j]!=-1)
     return dp2[i][j];
    if(a[i]==b[j])
     dp2[i][j]=1+find_ans(i+1,j+1,a,b,n,m,ans);
     else
      dp2[i][j]=0;
    ans=max(ans,dp2[i][j]);
   return dp2[i][j];
}
void find_sol(ll i,ll j,string &a,string &b,ll &n,ll &m,ll &ans)
{
   if(i==n||j==m)
    return;
   if(dp3[i][j]!=-1)
    return;
   dp3[i][j]=1;
   if(a[i]==b[j])
    find_ans(i,j,a,b,n,m,ans);
    else 
     dp2[i][j]=0;
      find_sol(i,j+1,a,b,n,m,ans);
      find_sol(i+1,j,a,b,n,m,ans);
    
}

int main()
{
    string a,b;
    cin>>a>>b;
    ll n,m;
    cin>>n>>m;
    n=a.size();
    m=b.size();
    // vector<vector<ll>> dp(n,vector<ll>(m,0));
    // ll ans=0;
    // for(int i=0;i<n;i++)
    //  for(int j=0;j<m;j++)
    //   if(a[i]==b[j])
    //   {
    //       ll prev=0;
    //       if(i-1>=0&&j-1>=0)
    //        prev=dp[i-1][j-1];
    //      dp[i][j]=prev+1;
    //      ans=max(ans,dp[i][j]);
    //   }
    // cout<<ans<<endl;


    dp2=vector<vector<ll>>(n,vector<ll>(m,-1));
    dp3=vector<vector<ll>>(n,vector<ll>(m,-1));
    ll ans2=0;
    find_sol(0,0,a,b,n,m,ans2);
    cout<<ans2<<endl;
  
}