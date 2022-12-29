LCA
//FOR DIRECTED GRAPH(TREE),for undirected->change the dfs function(use visited)
int LOG;
vector<vector<int>> up;
vector<int> depth;
void TreeAncestor(int n, vector<int>& parent)
{  LOG=0;
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
int getKthAncestor(int node, int k) 
{  if(depth[node] < k) 
        return -1;
    for(int j = LOG - 1; j >= 0; j--) 
    if(k >= (1 << j)) 
        {  node = up[node][j];
            k -= 1 << j;
        }
    return node;
}
void dfs(int vertex,vector<int> *adjlist,int curr_depth)
{
    depth[vertex]=curr_depth;
    for(auto i: adjlist[vertex])
     dfs(i,adjlist,curr_depth+1);
}
int lca(int a,int b)
{
  if(a==b)
   return a;
  if(depth[b]>depth[a])
   swap(a,b);
  if(depth[a]>depth[b])
  {
      int diff=depth[a]-depth[b];
       a=getKthAncestor(a,diff); // making depth equal
  }
  if(a==b)
   return a;

  for(int j=LOG-1;j>=0;j--)
   if(up[a][j]!=up[b][j])
   {
       a=up[a][j];
       b=up[b][j];
   }
   return up[a][0];// returning the parent, which is lca
}