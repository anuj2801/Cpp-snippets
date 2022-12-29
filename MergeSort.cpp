#include<iostream>
using namespace std;
//Time complexity nlog(n)
void Merge(int* arr,int start,int mid,int end)
{
    int sizeOfFirstHalf=mid-start+1;//=2nd half or =2nd half+1
    int sizeOfsecondHalf=end-mid;
    int first[sizeOfFirstHalf]; //temporary array
    int second[sizeOfsecondHalf];
    /*filling array which is already sorted 
    as when arr=2element,first=1element already sorted 
       when arr=4,first=2 ,which is sorted when arr=2
       when arr=8,first=4,which is sorted when arr=4
       same with second*/
    for(int i=0;i<sizeOfFirstHalf;i++) 
    first[i]=arr[start+i];            
    for(int i=0;i<sizeOfsecondHalf;i++)
    second[i]=arr[mid+i+1];

    int i=0,j=0,k=start;
    while(k<=end)
        if((first[i]<second[j]&&i<sizeOfFirstHalf&&j<sizeOfsecondHalf)||j==sizeOfsecondHalf)
            arr[k++]=first[i++];
        else if((first[i]>=second[j]&&i<sizeOfFirstHalf&&j<sizeOfsecondHalf)||i==sizeOfFirstHalf)
        arr[k++]=second[j++];
}
void mergeSort(int* arr,int start,int end)
{    if(start<end)
     { int mid=(start+end)/2;
       mergeSort(arr,start,mid);
       mergeSort(arr,mid+1,end);
       Merge(arr,start,mid,end);
       }                       
       //merge two sorted parts of an array
        //for eg. {3,5,9,1,6,8} 
        //3<5<9 & 1<6<8
         //after merge {1,3,5,6,8,9}
}
      
int main()
{ int a[9]={2,5,4,1,9,3,6,8,7};
  int l=*(&a+1)-a;
    mergeSort(a,0,l);
    for(int i=0;i<l;i++)
    cout<<a[i]<<" ";
return 0;
}