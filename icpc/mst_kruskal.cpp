MST
Int MinimumSpanningTreeKruskal (vector<vector<int>> &Edges)
{ 
//Edges ->{cost,u,v}  , use dsu class for make union and find_set functions
  sort(Edges.begin(),Edges.end());
  int cost=0;
  for(auto i:Edges)
  {
    int w=i[0];
    int u=find_set(i[1]);
    int v=find_set(i[2]);
    if(u==v)
    continue;
    else
    {cost+=w;
     make_union(u,v);
    }
  }
  return cost;
}