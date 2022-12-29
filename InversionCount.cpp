#include<iostream>
using namespace std;
//Time complexity nlog(n)
//inversion count using merge sort
// Input: arr[] = {8, 4, 2, 1}
// Output: 6
// Explanation: Given array has six inversions:
// (8,4), (4,2), (8,2), (8,1), (4,1), (2,1).    
int Merge(int* arr,int start,int mid,int end)
{
    int sizeOfFirstHalf=mid-start+1;//=2nd half or =2nd half+1
    int sizeOfsecondHalf=end-mid;
    int first[sizeOfFirstHalf]; //temporary array
    int second[sizeOfsecondHalf];
    for(int i=0;i<sizeOfFirstHalf;i++) 
    first[i]=arr[start+i];            
    for(int i=0;i<sizeOfsecondHalf;i++)
    second[i]=arr[mid+i+1];
    int inversion_count=0;
    int i=0,j=0,k=start;
    while(k<=end)
        if((first[i]<=second[j]&&i<sizeOfFirstHalf&&j<sizeOfsecondHalf)||j==sizeOfsecondHalf)
            arr[k++]=first[i++];
        else if(first[i]>second[j]&&i<sizeOfFirstHalf&&j<sizeOfsecondHalf)
        { inversion_count+=sizeOfFirstHalf-i;
            arr[k++]=second[j++];
        }
        else if(i==sizeOfFirstHalf)
         arr[k++]=second[j++];
         return inversion_count;
}
int mergeSort(int* arr,int start,int end)
{   int count=0; 
    if(start<end)
     { int mid=(start+end)/2;
       count=mergeSort(arr,start,mid)+mergeSort(arr,mid+1,end)+Merge(arr,start,mid,end);
     } 
     return count;                      
}
      
int main()
{ int a[]={3,5,6,9,1,2,7,8};
  int l=*(&a+1)-a;
    int x=mergeSort(a,0,l);
    cout<<"Inversion Count="<<x;
return 0;
}