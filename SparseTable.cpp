#include<bits/stdc++.h>
using namespace std;

// Sparse Table [ Good for fast query,and no updates (when operation is not invertible)]
vector<vector<long long>> st;
long long op(long long&,long long&);
void create_sparse_table(vector<long long> &v,long long &n)
{
    int K=log2(n);
    st=vector<vector<long long>>(n,vector<long long>(K+1));

    for(int i=0;i<n;i++)
     st[i][0]=v[i];

    for(int j=1;j<=K;j++)
      for(int i=0;i+(1<<j)<=n;i++)
          st[i][j]=op( st[i][j-1] , st[i+(1<<(j-1))][j-1] );
}
long long op(long long &a,long long &b)
{
    // define function here
     return max(a,b);
}
long long query(long long l,long long r)// l r are indices
{
      long long len=r-l+1;
      long long k=log2(len);
      long long range=(long long)(pow(2,k)+0.5);
      if(range==len)
      {
          return st[l][k];
      }
      else
      {
          return op(st[l][k],st[r-range+1][k]);
      }
}
int main()
{
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
     cin>>arr[i];
    
    create_sparse_table(arr,n);
    cout<<query(2,6)<<endl;
    cout<<query(1,9)<<endl;
    cout<<query(4,5)<<endl;
    cout<<query(2,2)<<endl;
    return 0;
}