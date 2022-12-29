#include<iostream>
using namespace std;
//a[i]>=a[i+1]<=a[i+2]>=a[i+3]....
//Time complexity O(n)
void swap(int *arr,int i,int j)
{  if(i!=j)
  { arr[i]=arr[i]+arr[j];
   arr[j]=arr[i]-arr[j];
   arr[i]=arr[i]-arr[j];
  }
}
void wavesort(int arr[], int n){
for(int i=1;i<n;i+=2) {
if(arr[i]>arr[i-1])
swap(arr,i,i-1);
if(arr[i]>arr[i+1] && i<=n-2)
swap(arr,i,i+1);
}}
int main()
{ int a[]={1,5,4,7,8,9,4,2,6,10,15};
int l=*(&a+1)-a;
  wavesort(a,l);
  for(int i=0;i<l;i++)
  cout<<a[i]<<" ";
    return 0;
}