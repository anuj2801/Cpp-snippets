#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Running median stream
 priority_queue<int,vector<int>> pqMax;
 priority_queue<int,vector<int>,greater<int>> pqMin; 
 void insertElement(int val)
 {  if(pqMax.size()==pqMin.size())
    {
        if((pqMin.size()==0)||(pqMin.size()!=0&&pqMin.top()>val))//if both empty or val cannot put at pqMin,then true 
        pqMax.push(val);
        else
        pqMin.push(val);
    }
    else if(pqMax.size()>pqMin.size())
    {
        if(val>=pqMax.top())
        pqMin.push(val);
        else
        {
            pqMin.push(pqMax.top());
            pqMax.pop();
            pqMax.push(val);
        }
    }
    else{
        if(val<=pqMin.top())
        pqMax.push(val);
        else
        {
            pqMax.push(pqMin.top());
            pqMin.pop();
            pqMin.push(val);
        }
    }
 } 
double findMedian()
{ if(pqMax.size()==0)
  return 0;
  if(pqMax.size()==pqMin.size())
  return ((pqMax.top()+pqMin.top())/2.0);
  else if(pqMax.size()>pqMin.size())
      return pqMax.top();
      else
      return pqMin.top();
}

//merge k sorted arrays
void createKsortedArraysAndMergeThem(int k)
{  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//MinHeap
   
   vector<vector<int>> v(k);//2D vector
   for(int i=0;i<k;i++)
   {   int size;
       cout<<"Enter size of "<<i<<"th sorted array"<<endl;
       cin>>size;
       v[i]=vector<int>(size);
       for(int j=0;j<size;j++)
       cin>>v[i][j];
       cout<<endl;
   }
   vector<int> pos(k,0);//pointer pointing begining of k arrays,so 0 index
  
   for(int i=0;i<k;i++)
   pq.push(make_pair(v[i][0],i));

   vector<int> ans; //result sorted array after merging k sorted arrays
   while(!pq.empty())
   {
       ans.push_back(pq.top().first);
       int arrayNo=pq.top().second;
       pq.pop();
       pos[arrayNo]++;

       if(v[arrayNo].size()>pos[arrayNo])
       pq.push({v[arrayNo][pos[arrayNo]],arrayNo});

   }
   cout<<"Sorted array:";
   for(int i=0;i<ans.size();i++)
   cout<<ans[i]<<" ";
}

int smallestSubsequenceWithSumK(vector<int> v,int k)
{ int count=0;
   priority_queue<int> pq;  //MaxHeap
   for(int i:v)
   pq.push(i);
   int sum=0;
   while(!pq.empty())
   {   sum+=pq.top();
       pq.pop();
       count++;
       if(sum>=k)
       break;
   }
   if(sum<k)
   return -1;
  return count;
}
int main()
{     
//   priority_queue<int> pq;  //MaxHeap //default container is vector
//     priority_queue<int,vector<int>> pq;  //MaxHeap
//     pq.push(3);
//     pq.push(7);
//     pq.push(1);
//     cout<<pq.top()<<endl;
//     pq.pop();
//     cout<<pq.top()<<endl;
      
    // priority_queue<int,vector<int>,greater<int>> pq;  //MinHeap ,we must have to write the container
    // pq.push(3);
    // pq.push(7);
    // pq.push(1);
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
   
   // running stream median
    //    insertElement(3);
    //    cout<<findMedian()<<endl;
    //    insertElement(1);
    //    cout<<findMedian()<<endl;
    //    insertElement(7);
    //    cout<<findMedian()<<endl;
    //    insertElement(6);
    //    cout<<findMedian()<<endl;
    //    insertElement(5);
    //    cout<<findMedian()<<endl;
    //    insertElement(1);
    //    cout<<findMedian()<<endl;

    //createKsortedArraysAndMergeThem(5);
    
    //vector<int> v=
   // cout<<smallestSubsequenceWithSumK({5,2,7,1,9,3,2},17)<<endl;

    return 0;
}