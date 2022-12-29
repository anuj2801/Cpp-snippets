#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &v,int n,int i) //heapify adjust root node downwards and returns MaxHeap at i,ancestors may or may not MaxHeap
{                                        //receive tree (subtree) whose root node is i,and whose subtrees are MaxHeap 
                                         // check root node is violating MaxHeap properties or Not
    int maxIdx=i;//will store index of max of root left right // if violating ,adjust it with left or right child whichever is max
    int leftChild=2*i+1;                                      // after adjusting, the child with which root swapped its value,may be that subtree violates MaxHeap property now
    int rightChild=2*i+2;                                     // so call heapify again for that child(recurrsion)
    if(leftChild<n&& v[leftChild]>v[maxIdx])                  // thus MaxHeap is again created with root at i index
     maxIdx=leftChild;
    if(rightChild<n&&v[rightChild]>v[maxIdx])     
     maxIdx=rightChild;
    if(maxIdx!=i)
    {
        swap(v[i],v[maxIdx]);
        heapify(v,n,maxIdx);
    }
}
//O(nLogn)
void HeapSort(vector<int> &v)
{
    int n=v.size();
    //creating MaxHeap
    for(int i=n/2-1;i>=0;i--)// or ((n-1)-1)/2 ie parent of last node
    heapify(v,n,i);

    //just like deletion and heapify
    for(int i=n-1;i>0;i--)
    {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}
void printV(vector<int> v)
{
    for(auto element:v)
    cout<<element<<" ";
}
int main()
{  vector<int> v={2,8,1,10,4,9,6};
    HeapSort(v);
    printV(v);
    return 0;
}