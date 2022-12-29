#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=1e5+2;
int arr[N],tree[4*N]; //for even nodes we need tree[2*N-1] but for safety we are using 4*N

//Sum of Subarray    - Segment Tree

    // void buildTree(int Node,int start,int end)//start node with 1 for 1st time so that we can access its child
    // {
    //     if(start==end)
    //     {
    //         tree[Node]=arr[start];
    //         return;
    //     }
    //     int mid=(start+end)/2;
    //     buildTree(2*Node,start,mid);
    //     buildTree(2*Node+1,mid+1,end);
    //
    //     tree[Node]=tree[Node*2]+tree[Node*2+1];
    // }
    // int query(int Node,int start,int end,int leftRange,int rightRange)//leftRange and RightRange are the given subarray range for which we have to return the subarray sum
    // {   //No overlap                                                  // start and end are the index of arr  
    //     if(end<leftRange || rightRange<start)
    //     return 0;
    //     //complete overlap
    //     if(leftRange<=start && end<=rightRange)
    //     return tree[Node];
    //
    //     //partial overlap
    //     int mid=(start+end)/2;
    //     int q1=query(Node*2,start,mid,leftRange,rightRange);
    //     int q2=query(Node*2+1,mid+1,end,leftRange,rightRange);
    //     return q1+q2;
    // }

//Maxmum of subarray - Segment Tree

//   void buildTree(int Node,int start,int end)
//   {
//       if(start==end)
//         {
//             tree[Node]=arr[start];
//             return;
//         }
//         int mid=(start+end)/2;
//         buildTree(2*Node,start,mid);
//         buildTree(2*Node+1,mid+1,end);
//    
//         tree[Node]=max(tree[Node*2],tree[Node*2+1]);
//   } 
//   int query(int Node,int start,int end,int leftRange,int rightRange)
//    {   //No overlap                                                  // start and end are the index of arr  
//         if(end<leftRange || rightRange<start)
//         return INT_MIN;
//         //complete overlap
//         if(leftRange<=start && end<=rightRange)
//         return tree[Node];
//
//         //partial overlap
//         int mid=(start+end)/2;
//         int q1=query(Node*2,start,mid,leftRange,rightRange);
//         int q2=query(Node*2+1,mid+1,end,leftRange,rightRange);
//         return max(q1,q2);
//     }
//     void upadate(int Node,int start,int end,int index,int value)
//     {   if(index<start||index>end)
//         {cout<<"invalid index for update"<<endl;
//         return;
//         }
//         else if(start==end) //start=end=index
//         {
//             arr[start]=value;
//             tree[Node]=value;
//             return;
//         }
//       
//         int mid=(start+end)/2;
//         if(index<=mid)
//         upadate(2*Node,start,mid,index,value);
//         else
//         upadate(2*Node+1,mid+1,end,index,value);
//         tree[Node]=max(tree[2*Node],tree[2*Node+1]);
//     }

//Nested segments and Intersecting segments      // 1 2 1 4 3 5 2 3 5 4   0 to n,repeat twice   
                                                      //nested segment: 1[0,2]->0(no of elements reapting inside segment 0,2 means between two consecutive 1's)  
                                                                       //2[1,6]->0   3[4,7]->0   4[3,9]->2   5[5,8]->0 
                                                                      // output: 0 0 0 2 0  
                                                     //Intersecting segments: 1[0,2]->1(no of non repeating elements between idx 0,2 ie between two consecutive 1's)
                                                                      //2[1,6]->4  3[4,7]->2   4[3,9]->1   5[5,8]->2
 struct twice{
     int leftIdx;
     int rightIdx;
     int element;
 };
 int query(int Node,int start,int end,int leftRange,int rightRange)
   {   //No overlap                                                  // start and end are the index of arr  
        if(end<leftRange || rightRange<start)
        return 0;
        //complete overlap
        if(leftRange<=start && end<=rightRange)
        return tree[Node];

        //partial overlap
        int mid=(start+end)/2;
        int q1=query(Node*2,start,mid,leftRange,rightRange);
        int q2=query(Node*2+1,mid+1,end,leftRange,rightRange);
        return q1+q2;
    }
    void upadate(int Node,int start,int end,int index,int value)
    {   if(index<start||index>end)
        {cout<<"invalid index for update"<<endl;
        return;
        }
        else if(start==end) //start=end=index
        {
            tree[Node]=value;
            return;
        }
      
        int mid=(start+end)/2;
        if(index<=mid)
        upadate(2*Node,start,mid,index,value);
        else
        upadate(2*Node+1,mid+1,end,index,value);
        tree[Node]=tree[2*Node]+tree[2*Node+1];
    }                                            

int main()
{
    // int n;
    // cout<<"enter size"<<endl;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // buildTree(1,0,n-1);

    // //Before Update
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=2*n-1;i++)
    // cout<<tree[i]<<" ";

    // cout<<endl<<"query :"<<query(1,0,n-1,4,5)<<endl;
    // upadate(1,0,n-1,4,9);
 
    // //After Update
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=2*n-1;i++)
    // cout<<tree[i]<<" ";
    
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    twice tw; tw.leftIdx=-1;tw.rightIdx=-1;
    vector<twice> t(n,tw);
    for(int i=0;i<2*n;i++)
    {
        int x;
        cin>>x;
        if(t[x-1].leftIdx==-1)
          t[x-1].leftIdx=i;
        else
         t[x-1].rightIdx=i;
        t[x-1].element=x;
    } 
    sort(t.begin(),t.end(),[&](twice &t1,twice &t2){
    return t1.rightIdx<t2.rightIdx;
    });
    int ans[n];

    //nested segment:
    // for(int i=0;i<n;i++)
    // { ans[t[i].element-1]=query(1,0,2*n-1,t[i].leftIdx,t[i].rightIdx);
    //   upadate(1,0,2*n-1,t[i].leftIdx,1);
    // }

    //Intersecting segment
     for(int i=0;i<n;i++)
    { ans[t[i].element-1]=t[i].rightIdx-t[i].leftIdx-1-2*query(1,0,2*n-1,t[i].leftIdx,t[i].rightIdx);
      upadate(1,0,2*n-1,t[i].leftIdx,1);
    }

    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";

    return 0;
}
