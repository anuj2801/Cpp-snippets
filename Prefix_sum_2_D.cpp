#include<iostream>
#include<vector>
using namespace std;
void find_sum(vector<vector<int>> v,vector<vector<int>> &Prefix_Sum,int n,int m)
{
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
     {
        Prefix_Sum[i][j]=v[i][j];
        if(i-1>=0)
          Prefix_Sum[i][j]+=Prefix_Sum[i-1][j];
        if(j-1>=0)
          Prefix_Sum[i][j]+=Prefix_Sum[i][j-1];
        if(i-1>=0&&j-1>=0)
          Prefix_Sum[i][j]-=Prefix_Sum[i-1][j-1];
     }
}
void input( vector<vector<int>> &v,int n,int m)
{
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
      cin>>v[i][j];
}
void display(vector<vector<int>> x,int n,int m)
{
    for(int i=0;i<n;i++)
     {for(int j=0;j<m;j++)
      cout<<x[i][j]<<" ";
      cout<<endl;
     }
}
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<int>> Prefix_Sum(n,vector<int>(m));
    input(v,n,m);
    find_sum(v,Prefix_Sum,n,m);
    display(Prefix_Sum,n,m);
    return 0;
}