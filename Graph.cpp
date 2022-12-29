#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
#define Infinity 10e8
//Building graphs
            //              1
            //             /  \
            //            /    \ 
            //           2      3
            //        / / \ \   \
            //      /  /   \  \  \
            //    /   /     \    7
            //   4    5      6
void AdjacencyMatrix()
{   int n,m;
    cout<<"Enter Number of Nodes and Number of edges"<<endl;
    cin>>n>>m;
    vector<vector<int>> AdjMat(n+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        cout<<"Enter two nodes which are "<<endl; 
        int x,y;
        cin>>x>>y;
        AdjMat[x][y]=1;
        AdjMat[y][x]=1;  //as undirected ,so both direction are true
        // will for Symmetric Matrix
    }
    cout<<"Output of the above Adjacency Matrix"<<endl;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
       cout<<AdjMat[i][j]<<" ";
       cout<<endl;
    }
}
void AdjacencyList()
{
    int n,m;
    cout<<"Enter Number of Nodes and Number of edges"<<endl;
    cin>>n>>m;
    vector<int> AdjList[n+1];// Array of type vector AdjList[i] is a vector
                             //since now we have nodes 1 to n, but for other cases take size=10^5 or more

    for(int i=1;i<=m;i++)
    {
        cout<<"Enter two nodes which are "<<endl; 
        int x,y;
        cin>>x>>y;
        AdjList[x].push_back(y);
        AdjList[y].push_back(x);  //as undirected ,so both direction are true
        
    }
    cout<<"Output of the above Adjacency List"<<endl;
    for(int i=1;i<=n;i++)
    {   cout<<i<<" ->";
        for(int j:AdjList[i])
        cout<<j<<" ";
        cout<<endl;
    }
    
}
void DFS(int vertex,bool visited[],vector<int>* AdjList)
{ //preorder
  visited[vertex]=1;
  cout<<vertex<<" "; //for above diagram output will be  1 2 4 5 6 7 3

  //inorder
  for(int i=0;i<AdjList[vertex].size();i++)
    if(!visited[AdjList[vertex][i]])
       DFS(AdjList[vertex][i],visited,AdjList);

  //postorder
 // cout<<vertex<<" ";  //for above diagram output will be  4 5 6 3 7 2 1

}
void BFS(bool visited[],vector<int>* AdjList)
{
  queue<int> q;
  q.push(1);
  while(!q.empty())
  {
    int node=q.front();
    cout<<node<<" ";
    visited[node]=1;
    q.pop();
    for(auto i:AdjList[node])
    if(!visited[i])
    { visited[i]=1;
      q.push(i);
    }
  }
}
void TopologicalSort()
{                
//                      1      2    3     4
//                       \    /    /     /
//                        \   5   6     7
//                         \ /   /    /
//                          8   9    10
//                           \ /    /
//                            11   /
//                              \ /
//                               12
                       //nodes= 12 edges =11
                       //ALL EDGES HERE ARE DIRECTED (downward for eg. 1-->8 , 2-->5, 3-->6, so on)
                        //Expected TopologicalSort: 1 2 3 4 5 6 7 8 9 10 11 12
    int n,m;
    cout<<"Enter Number of Nodes and Number of edges"<<endl;
    cin>>n>>m;
    vector<vector<int>> AdjList(n+1);
    map<int,int> indegree;// Map initialize values of all keys with 0
    for(int i=1;i<=m;i++)
    {   cout<<"Enter two nodes such that x-->y "<<endl; 
        int x,y;
        cin>>x>>y;
        AdjList[x].push_back(y);
        indegree[y]++;
    }
    queue<int> vertex;
    //store which nodes have indegree 0,as they come first
    for(int i=1;i<=n;i++)
    { if(indegree[i]==0)
       vertex.push(i); 
    }
    while(!vertex.empty())
    {
      int currVertex=vertex.front();
      vertex.pop();
      cout<<currVertex<<" ";
      for(int i:AdjList[currVertex])
      {
        indegree[i]--;
        if(indegree[i]==0)
        vertex.push(i);
      }
    }
}

//cycle detection in Undirected graph(for  graph )
bool isCycleFound(int i,bool visited[],vector<int>* AdjList,int parent)
{
  visited[i]=true;
  for(int child:AdjList[i]) 
     if(child!=parent)
   {  if(visited[child])
      return true;
      else if(isCycleFound(child,visited,AdjList,i))
             return true;
   }

   return false;
}
bool CycleDetectionUndirected(int n,bool visited[],vector<int>* AdjList)
{ 
  for(int i=1;i<=n;i++) //we are using loop as there may be multiple components of the graph (which are not )
  {  
      if(!visited[i] and isCycleFound(i,visited,AdjList,-1)) //isCycleFound is called only once for one  component
      return true;                                           //as after calling once,all the nodes of the  componenet gets visited
  }                                                          // parent is -1 here as for one  componenet,the 1st node has no parents(we can choose any node as root)
  return false;
}

//cycle detection in Directed graph(may be  graph or may be dis graph)
bool isCycleFound(int i,bool visited[],vector<vector<int>> AdjList,vector<int> recurStack)
{ if(!visited[i])
    {
      visited[i]=true;
      recurStack[i]=1;
      for(int child:AdjList[i]) 
        if(visited[child]&&recurStack[child])
          return true;
          else if(isCycleFound(child,visited,AdjList,recurStack))
                return true;
      recurStack[i]=0;
    }
   return false;
}//recurStack is used since another vertex with indegree 0 may joint with the existing graph and not forming a cycle 
bool CycleDetectionDirected(int n,bool visited[],vector<vector<int>> AdjList,vector<int> recurStack)
{
  for(int i=1;i<=n;i++) //we are using loop as there may be multiple components of the graph (which are not )
  {  
      if(!visited[i] and isCycleFound(i,visited,AdjList,recurStack)) //isCycleFound is called only once for one  component
      return true;                                           //as after calling once,all the nodes of the  componenet gets visited
  }                                                          // parent is -1 here as for one  component,the 1st node has no parents(we can choose any node as root)
  return false;

}

//Find how many  components are present and their size (undirected)
int get_comp_size(int i,bool visited[],vector<int>* AdjList)
{
  visited[i]=true;
  int ans=1;
  for(int child:AdjList[i])
  if(!visited[child])
   ans+=get_comp_size(child,visited,AdjList);
  return ans;
}
void Components(int n,bool visited[],vector<int>* AdjList)
{
  vector<int> componentSize;
  for(int i=1;i<=n;i++)
  if(!visited[i])
   componentSize.push_back(get_comp_size(i,visited,AdjList));

   cout<<"Number of Components="<<componentSize.size()<<endl;
   cout<<"Components Size are: ";
   for(int i:componentSize)
   cout<<i<<" ";

   //Q. Number of ways two person can be selected whom are not  to each other(number of person n )
   cout<<endl;
   int no_of_ways=0;
   for(int i:componentSize)
   no_of_ways+=i*(n-i);
   cout<<"No of ways= "<<(no_of_ways/2)<<endl; // divide by 2!=2 because for eg. person A and person B get selected first when i=1,then  again  person B and person A gets selected when i=2 


}

//Bipartite Graph
bool do_coloring(int vertex,int type_of_color,vector<int> &color,vector<int>* AdjList)
{     // cout<<vertex<<" color type="<<type_of_color<<"  -> ";
       color[vertex]=type_of_color;
       for(int child:AdjList[vertex])
         if(color[child]!=-1)
          {if(color[child]==type_of_color)
            return false;
          }
         else if(!do_coloring(child,1-type_of_color,color,AdjList))
                return false;
  return true;  
}
bool BipartiteCheck(int n,vector<int> &color,vector<int>* AdjList)
{
  for(int i=1;i<=n;i++)
  if(color[i]==-1)
    if(!do_coloring(i,0,color,AdjList)) //-1 indicate no color, 0 indicates red ,1 indicates blue
     return false;
  return true;   
}

//Cycle detection DSU
vector<int> parent;
int find_set(int v)
{ if(parent[v]<0)
  return v;
  return parent[v]=find_set(parent[v]);
}
void make_union(int u,int v)
{  if(abs(parent[u])<abs(parent[v]))
     swap(u,v);  //as below we are considering u as more weighted or greater size graph
     parent[u]=parent[u]+parent[v];
     parent[v]=u;
}
bool CycleDetectionUndirectedDSU(vector<pair<int,int>> &edges)
{
  for(auto i:edges)
  { 
    int u=find_set(i.first);
    int v=find_set(i.second);
    if(u==v)
    return true;
    else
    make_union(u,v);
  }
  return false;
}
//MST
int MinimumSpanningTreePrims(int i,int n,bool visited[],vector<pair<int,int>>* AdjList,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &MinHeap)
{
  //Rule:take minimum and store its "distance to the other vertices(ie weight)" marking it visited, then take othen possible min distance from min heap
  //fails for dis graph..so there are exactly n-1 edges for spanning tree of  graph 
  visited[i]=true;
  for(auto child:AdjList[i])
  MinHeap.push(child);
  int cost=0;
  n=n-1;//since for spanning tree,total no of edges is no. of vertex -1
  while(n--)
  { 
    pair<int,int> minCost=MinHeap.top();
    MinHeap.pop();
    cost+=minCost.first;
    int SelectedChild=minCost.second;
    visited[SelectedChild]=true;
    for(auto child:AdjList[SelectedChild])
     if(!visited[child.second])
     MinHeap.push(child);
  }
  return cost;

}
int MinimumSpanningTreeKruskal(vector<vector<int>> &Edges)
{ //Rule : traverse edges in ascending order and if you found it that edge makes cycle,dont make union
  //works for disconneted graph but spanning tree will be formed for each dis components
  sort(Edges.begin(),Edges.end()); // sorting is done on the basis of 1st element
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
void DisjointSetUnion()
{   int n,m;
    cout<<"Enter Number of Nodes and Number of edges"<<endl;
    cin>>n>>m;
    parent=vector<int>(n+1,-1);//-1 means itself is a parent
    // vector<pair<int,int>> edges;
    // for(int i=0;i<m;i++)
    // { cout<<" Enter x--y"<<endl;
    //   int x,y;
    //   cin>>x>>y;
    //   edges.push_back({x,y});//undirected edges
    // }
    //  if(CycleDetectionUndirectedDSU(edges))
    //  cout<<"Cycle present"<<endl;
    //  else
    //  cout<<"Cycle not present"<<endl;

    vector<vector<int>> Edges;
    for(int i=0;i<m;i++)
    { cout<<"Enter weight w of edge and two vertices x--y "<<endl;
      int w,x,y;
      cin>>w>>x>>y;
      Edges.push_back({w,x,y});//undirected edges
    }
    int cost=MinimumSpanningTreeKruskal(Edges);
    cout<<"Minimum Cost is "<<cost<<endl;
    
}

//Algo to find SHORTEST path of all the vertex from the source

//This algo fails/limitation   when there is a negative wighted edge(may or may not give correct ans)
void DijkstraAlgo(int source,int size,vector<pair<int,int>>* AdjList) //Adjlist {W,V}
{  vector<int>distance(size+1,Infinity);
   distance[source]=0;
   set<pair<int,int>> currVertex; //{shortestdistance, vertex} - distance is initally at infinity
   currVertex.insert({0,source});
   while(!currVertex.empty())
   {
     pair<int,int> v=*(currVertex.begin());
     currVertex.erase(currVertex.begin());
     int distanceTillNow=v.first;
     int newSrc=v.second;
     for(auto child:AdjList[newSrc])
     {
       if(distance[child.second]> distanceTillNow+child.first)
       { distance[child.second]=distanceTillNow+child.first;
         currVertex.insert({distance[child.second],child.second});
       }
     }
     
   }
  for(int i=1;i<=size;i++)
   if(distance[i]<Infinity)
   cout<<i<<"->"<<distance[i]<<endl;
   else
   cout<<i<<"-> Not Reachable"<<endl;
   
}

//This algo can have negative weight edge and works fine,but if the sum of a cycle becomes negative,then it fails as after n-1 times iterating edges,distances will still change if we iterate one more time,but then also consider upto n-1 times
void BellmanFord()
{
  //Rule:Relax all edges n-1 times and get the final ans(Relaxation:whichever distance is min,put that in array)
  //i. Advantage over Dijkstra :Can have negative edge
  //ii. can be used to detect negative cycle
  
   int n,m;
    cout<<"Enter Number of Nodes and Number of edges"<<endl;
    cin>>n>>m;
    vector<vector<int>> Edges;
    for(int i=1;i<=m;i++)
    {   cout<<"Enter weight and two nodes such that x-->y "<<endl; 
        int w,x,y;
        cin>>w>>x>>y;
        Edges.push_back({w,x,y});
    }
      int source;
      cout<<"Enter source"<<endl;
      cin>>source;
      vector<int> distance(n+1,Infinity);
      distance[source]=0;
      bool negativeCycle=false;
      //if we dont need to detect cycle, use variable change=false, and initialize it false before iterating edges,then put change =true inside if(dist...), after iterating edges check change is true or not,if false,break;
   for(int i=1;i<=n;i++)
   for(auto edge:Edges)
   {
     int w=edge[0];
     int u=edge[1];
     int v=edge[2];
     if(i<=n-1)
     {if(distance[v]>distance[u]+w)
     distance[v]=distance[u]+w;
     }
     else
      if(distance[v]>distance[u]+w)
      negativeCycle=true;
   }

   for(int i=1;i<=n;i++)
   if(distance[i]<Infinity)
   cout<<i<<"->"<<distance[i]<<endl;
   else
   cout<<i<<"-> Not Reachable"<<endl;

   if(negativeCycle)
   cout<<"Negative Cycle Present"<<endl;
   else
   cout<<"Negative Cycle Not Present"<<endl;

}
//  This has high time complexity O(n^3)
void FloydWarshallAlgo()
{   int n,m;
    cout<<"Enter Number of Nodes and Number of edges"<<endl;
    cin>>n>>m;
    vector<vector<int>> distance(n+1,vector<int>(n+1,Infinity));
    for(int i=1;i<=m;i++)
    {   cout<<"Enter weight w and two nodes such that x-->y "<<endl; 
        int w,x,y;
        cin>>w>>x>>y;
        distance[x][y]=w;
    }
    for(int k=1;k<=n;k++)
     for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
       if(i==j)
       distance[i][j]=0;
       else if(distance[i][j]>distance[i][k]+distance[k][j])
           distance[i][j]=distance[i][k]+distance[k][j];

     for(int i=1;i<=n;i++)
      {for(int j=1;j<=n;j++)
       if(distance[i][j]==Infinity)
       cout<<"INF ";
       else
       cout<<distance[i][j]<<" ";
       cout<<endl;
      }
}

void SnakeAndLadder()
{//BFS technique
  
   int ladders,snakes;
  cout<<"Enter no of ladders"<<endl;
  cin>>ladders;
  map<int,int> lad;
  for(int i=0;i<ladders;i++)
  { cout<<"Enter u to v"<<endl;
    int u,v;
    cin>>u>>v;
    lad[u]=v;
  }
  cout<<"Enter no of snakes"<<endl;
  cin>>snakes;
  map<int,int> snak;
  for(int i=0;i<snakes;i++)
  { cout<<"Enter u to v"<<endl;
    int u,v;
    cin>>u>>v;
    snak[u]=v;
  }
  int moves=0;
  queue<int> q;
  q.push(1);
  bool found=false;
  vector<bool> vis(101,0);
  vis[1]=true;

  while(!q.empty() and !found)
  { int currQsize=q.size();
    while(currQsize--)
    { int number=q.front();
      q.pop();
      for(int die=1;die<=6;die++)
      {
        if(number+die==100)
        found=true;
        if(number+die<=100 and lad[number+die] and !vis[lad[number+die]])
        {
          vis[lad[number+die]]=true;
          if(lad[number+die]==100)
          found= true;
          q.push(lad[number+die]);
        }
        else if(number+die<=100  and snak[number+die] and !vis[snak[number+die]])
        { vis[snak[number+die]]=true;
          if(snak[number+die]==100)
            found=true;
          q.push(snak[number+die]);
        }
        else if(number+die<=100 and !vis[number+die] and !snak[number+die] and !lad[number+die])
        {
          vis[number+die]=true;
          q.push(number+die);
        }
      }
    }
    moves++;  
  }
  if(found)
  cout<<"Finished in "<<moves<<" moves"<<endl;
  else
  cout<<"Can't finished"<<endl;
}

int main()
{  // AdjacencyMatrix();
    //  AdjacencyList();

   //Undirected Graph Creation
    // int n,m;
    // cout<<"Enter Number of Nodes and Number of edges"<<endl;
    // cin>>n>>m;
    // vector<int> AdjList[n+1];// Array of type vector AdjList[i] is a vector
    //                          //since now we have nodes 1 to n, but for other cases take size=10^5 or more
    //                         // we can also use vector<vector<int>> AdjList(n+1);

    // for(int i=1;i<=m;i++)
    // {
    //     cout<<"Enter two nodes which are "<<endl; 
    //     int x,y;
    //     cin>>x>>y;
    //     AdjList[x].push_back(y);
    //     AdjList[y].push_back(x);  //as undirected ,so both direction are true
        
    // }
    //  bool visited[n+1]={0};

  //  DFS(1,visited,AdjList);
  //   BFS(visited,AdjList);
  // if(CycleDetectionUndirected(n,visited,AdjList))
  // cout<<"Cycle Found"<<endl;
  // else
  // cout<<"Cycle Not Found"<<endl;

  //Components(n,visited,AdjList);

  // vector<int> color(n+1,-1);
  // if(BipartiteCheck(n,color,AdjList))
  //  cout<<"Yes, Bipartite"<<endl;
  //  else
  //  cout<<"No,not Bipartite"<<endl;

//Directed Graph Creation
  // int n,m;
  //   cout<<"Enter Number of Nodes and Number of edges"<<endl;
  //   cin>>n>>m;
  //   vector<vector<int>> AdjList(n+1);
  //   for(int i=1;i<=m;i++)
  //   {   cout<<"Enter two nodes such that x-->y "<<endl; 
  //       int x,y;
  //       cin>>x>>y;
  //       AdjList[x].push_back(y);
  //   }
  //  bool visited[n+1]={0};

  //  vector<int> recurStack(n);
  //  if(CycleDetectionDirected(n,visited,AdjList,recurStack))
  //   cout<<"Cycle Found"<<endl;
  //   else
  //   cout<<"Cycle Not Found"<<endl;
  //TopologicalSort();


//DisjointSetUnion();

// int n,m;
//     cout<<"Enter Number of Nodes and Number of edges"<<endl;
//     cin>>n>>m;
//     vector<pair<int,int>> AdjList[n+1];// Array of type vector AdjList[i] is a vector of pair. firs is weight of edge,second is  to

//     for(int i=1;i<=m;i++)
//     {
//         cout<<"Enter weight of edge and two nodes which are , w  x--y"<<endl; 
//         int w,x,y;
//         cin>>w>>x>>y;
//         AdjList[x].push_back(make_pair(w,y));
//         AdjList[y].push_back(make_pair(w,x));  //as undirected ,so both direction are true
        
//     }
    //  bool visited[n+1]={0};
    //  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> MinHeap;//weight, to
    // int cost=MinimumSpanningTreePrims(1,n,visited,AdjList,MinHeap);
    // cout<<"Minimum Cost is "<<cost<<endl;
   
  //  int source;
  //  cout<<"Enter source"<<endl;
  //  cin>>source;
  //  DijkstraAlgo(source,n,AdjList);
  
  //BellmanFord();

  //FloydWarshallAlgo();

  SnakeAndLadder();
    return 0;
}