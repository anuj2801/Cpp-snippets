
Fenwich Tree
//1 BASED INDEXING
int n;
vector<int> bit;
void update(int idx,int val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx)
{   
    int ans=0;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=idx&(-idx);
    }
    return ans;
}
