#include<iostream>
using namespace std;
//Best Time complexity nlog(n)
//worstTime complexity n^2
//so use Merge Sort
void swap(int *arr,int fi,int li)
{  if(fi!=li)
  { arr[fi]=arr[fi]+arr[li];
   arr[li]=arr[fi]-arr[li];
   arr[fi]=arr[fi]-arr[li];
  }
}
int partition(int *arr,int first,int last)
{   int pivotValue=arr[last];//taking last value as pivot value
    int pivot=first;
    for(int j=first;j<last;j++)//traversing array except last element
    if(arr[j]<pivotValue)
     swap(arr,pivot++,j);
    swap(arr,pivot,last);//place piotValue at right position
    return pivot;
}
void QuickSort(int *arr,int first,int last)
{   if(first<last)
    {  int pivot=partition(arr,first,last);
        QuickSort(arr,first,pivot-1);
        QuickSort(arr,pivot+1,last);
    }
}
int main()
{ int a[]={2,2,2,5,1,3,6,8,10};
  int l=*(&a+1)-a;
  QuickSort(a,0,l-1);
  for(int i=0;i<l;i++)
   cout<<a[i]<<" ";
   return 0;
}