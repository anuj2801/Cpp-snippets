
DSU
class dsu{
  public:
  vector<long long> parent;
    dsu(long long n)
    {
      parent=vector<long long>(n,-1);
    }
    long long find_set(long long v)
    { if(parent[v]<0)
      return v;
      return parent[v]=find_set(parent[v]);
    }
    void make_union(long long u,long long v)
    {  if(abs(parent[u])<abs(parent[v]))
        swap(u,v);  //as below we are considering u as more weighted or greater size graph
        parent[u]=parent[u]+parent[v];
        parent[v]=u;
    }
    void merge(ll x,ll y)
    {
        long long u=find_set(x);
        long long v=find_set(y);
        if(u!=v)
         make_union(u,v);
    }
     bool check_cycle(ll x,ll y)
    {
        long long u=find_set(x);
        long long v=find_set(y);
        if(u!=v)
         return false;    //cycle (will not form)/(not present)
        return true;      //cycle (will form)/(present)
    }
    bool CycleDetectionUndirectedDSU(vector<pair<long long,long long>> &edges)
    {
      for(auto i:edges)
      { 
        long long u=find_set(i.first);
        long long v=find_set(i.second);
        if(u==v)
        return true;
        else
        make_union(u,v);
      }
      return false;
    }
};