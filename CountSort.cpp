#include<iostream>
using namespace std;
//Time complexity O(n+k)  n -no of elements  k - range of min and max element
//space complexity(k)
//although it uses space, if range k is small, this algo is preffered
void CountSort(int *arr,int len)
{
    int max_element=arr[0];
    int min_element=arr[0];
    for(int i=1;i<len;i++)
    { max_element=max(max_element,arr[i]);
      min_element=min(min_element,arr[i]);
    }
    int range=max_element-min_element+1;
    int count[range]={0};
    for(int i=0;i<len;i++)
    count[arr[i]-min_element]++;
    int pointer_in_count=0;
    for(int i=0;i<len;i++)
    if(count[pointer_in_count]!=0)
     {arr[i]=pointer_in_count+min_element;
     count[pointer_in_count]--;}
     else{
        while(count[++pointer_in_count]==0);
        arr[i]=pointer_in_count+min_element;
        count[pointer_in_count]--;
     }
}
int main()
{ int a[9]={1,5,4,1,9,9,6,8,7};
int l=*(&a+1)-a;
  CountSort(a,l);
  for(int i=0;i<l;i++)
  cout<<a[i]<<" ";
    return 0;
}