#include<bits/stdc++.h>
#define ll long long
using namespace std;
//n*m matrix .... n*m is odd... 1<=Ai<1e9
void input(vector<vector<ll>> &a,ll n,ll m)
{
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
     cin>>a[i][j];
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    input(a,n,m);
    

    //binary search algorithm- (nLog(m)Log(n*m))  //since rows are sorted
    ll low=1,high=1e9;
    ll req=n*m/2;
    ll mid,ans;
    while(low<=high)
    {
        mid=(high+low)/2;
        ll count=0;
        for(int i=0;i<n;i++)
        {
            ll h=m-1,l=0,mi;
            while(l<=h)
            {
                mi=(l+h)/2;
                if(a[i][mi]<=mid)
                 l=mi+1;
                else
                 h=mi-1;
            }
            count+=mi;
        }
        if(count>=req)
         {ans=mid;
          high=mid-1;
         }
         else
          low=mid+1;
    }
    cout<<"Median="<<ans<<endl;
    return 0;
}