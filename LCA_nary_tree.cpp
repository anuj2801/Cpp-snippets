#include<bits/stdc++.h>
using namespace std;

//FOR DIRECTED GRAPH(TREE)
//for undirected, change the dfs function(use visited)
int LOG;
vector<vector<int>> up;
vector<int> depth;
// O(nLog(n))
void TreeAncestor(int n, vector<int>& parent)
{
    LOG=0;
    while((1 << LOG) <= n) 
        LOG++;
    up = vector<vector<int>>(n, vector<int>(LOG));
    // up[v][j] is 2^j -th ancestor of node v
    for(int v = 0; v < n; v++)
        up[v][0] = parent[v];

    for(int j = 1; j < LOG; j++) 
        for(int v = 0; v < n; v++)
        up[v][j] = up[ up[v][j-1] ][j-1];
    
}
// O(Log(n))
int getKthAncestor(int node, int k) 
{
    if(depth[node] < k) 
        return -1;
    
    for(int j = LOG - 1; j >= 0; j--) 
    if(k >= (1 << j)) 
        {
            node = up[node][j];
            k -= 1 << j;
        }
    
    return node;
}

// O(n)
void dfs(int vertex,vector<int> *adjlist,int curr_depth)
{
    depth[vertex]=curr_depth;
    for(auto i: adjlist[vertex])
     dfs(i,adjlist,curr_depth+1);

}
// Overall : O(Log(n))
int lca(int a,int b)
{
  if(a==b)
   return a;
  if(depth[b]>depth[a])
   swap(a,b);
  if(depth[a]>depth[b])
  {
      int diff=depth[a]-depth[b];
      // making depth equal
      //O(Log(n))
      a=getKthAncestor(a,diff);
  }
  // it may happen that previously a is in the subtree with root b, now since they are at same level, a=b
  if(a==b)
   return a;
// moving up(both a and b by same level,since at present they are at same level) the tree uptil the child of lca
 //O(Log(n))
  for(int j=LOG-1;j>=0;j--)
   if(up[a][j]!=up[b][j])
   {
       a=up[a][j];
       b=up[b][j];
   }
   return up[a][0];// returning the parent, which is lca
}
int main()
{
    cout<<"Enter no. of nodes :";
    int n;
    cin>>n; //number of nodes;
    //directed graph(tree)
    vector<int> adjlist[n];
    depth=vector<int>(n);
    vector<int> parent(n,-1);
    //memset(&parent,-1,sizeof(parent));
    for(int i=0;i<n-1;i++)
     {
         int x,y;
         cin>>x>>y;
         x--,y--;
         // x-->y
         adjlist[x].push_back(y);
         parent[y]=x;
     }
     int root=-1;
     for(int i=0;i<n;i++)
      if(parent[i]==-1)
      {
          root=i;
          break;
      }
      parent[root]=root;
    
      dfs(root,adjlist,0);
      TreeAncestor(n,parent);
      cout<<"Enter number of queries :";
      int q;
      cin>>q;
      while(q--)
      {
          int a,b;
          cin>>a>>b;
          a--,b--;
          cout<<lca(a,b)+1<<endl;
      }

    return 0;
}