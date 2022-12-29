#include<bits/stdc++.h>
using namespace std;
int DFS(int vertex,bool visited[],vector<int>* AdjList,int store[])
{ 
  visited[vertex]=1;

  for(int i=0;i<AdjList[vertex].size();i++)
    if(!visited[AdjList[vertex][i]])
      store[vertex]+=DFS(AdjList[vertex][i],visited,AdjList,store);
  return ++store[vertex];
}
int find_centroid(int vertex,bool visited[],vector<int>* AdjList,int store[],int val)
{
  cout<<"z"<<endl;
  cout<<vertex<<endl;
    visited[vertex]=1;
    for(int i=0;i<AdjList[vertex].size();i++)
     if(!visited[AdjList[vertex][i]])
      if(store[AdjList[vertex][i]]>val)
       return find_centroid(AdjList[vertex][i],visited,AdjList,store,val);
     return vertex;
      
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adjlist[n];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    bool vis[n];
    int store[n]={0};// store number of nodes subtree has with root at i,(including i)
    memset(vis,false,sizeof(vis));
    DFS(0,vis,adjlist,store);
    memset(vis,false,sizeof(vis));
    int centroid=find_centroid(0,vis,adjlist,store,store[0]/2);
    cout<<centroid<<endl;
    return 0;
}