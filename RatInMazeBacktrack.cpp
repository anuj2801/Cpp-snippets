#include<iostream>
using namespace std;
bool isSafe(int arr[][6],int x,int y,int n)
{
    if(x<n&&y<n&&arr[x][y]==1)
    return true;
    return false;

}
bool maze(int arr[][6],int x,int y,int n,int sol[][6])
{
    if(x==n-1&&y==n-1)
    {sol[x][y]=1;
    return true;
    }
    if(isSafe(arr,x,y,n))
    {sol[x][y]=1;
    //move right
     if(maze(arr,x+1,y,n,sol))
     return true;
     //move down
     else if(maze(arr,x,y+1,n,sol))
     return true;
     else
     {
         sol[x][y]=0;//backtrack
         return false;
     }
    }
    return false;
    
      

}
int main()
{  int a[][6]={{1,1,0,0,0,1},
              {0,1,1,1,1,1},
              {0,1,0,0,1,0},
              {0,0,1,0,1,1},
              {1,1,1,0,0,1},
              {0,1,0,1,0,1}};
    int sol[6][6];
    for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
    sol[i][j]=0;
    if(maze(a,0,0,6,sol))
    for(int i=0;i<6;i++){
    for(int j=0;j<6;j++)
    cout<<sol[i][j]<<" ";
    cout<<endl;}
    else
    cout<<"No Way";
    

    return 0;
}