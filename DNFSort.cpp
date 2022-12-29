#include<iostream>
using namespace std;
//work when three types of array elements are there
//Time complexity O(n)
void swap(int *arr,int i,int j)
{  if(i!=j)
  { arr[i]=arr[i]+arr[j];
   arr[j]=arr[i]-arr[j];
   arr[i]=arr[i]-arr[j];
  }
}
void dnffort(int arr[], int n) {
int low = 0;
int mid= 0;
int high=n-1;

while(mid<=high) 
if(arr[mid]==0) swap(arr,low++, mid++);
 else if(arr[mid]==1) {mid++;}
  else swap(arr,mid,high--); 
}
int main()
{ int a[]={1,0,2,1,1,0,2,1,0,0,1};
  int l=*(&a+1)-a;
    dnffort(a,l);
    for(int i=0;i<l;i++)
    cout<<a[i]<<" ";
return 0;
}