#include<iostream>
#include<cstring>
using namespace std;
int KMP(string t)
{ 
    //filling array for KMP algo
    // int lt=t.length();
    // int arr[lt+1]={0};
    // int j=0;
    // for(int i=1;i<lt;i++)
    // { if(t[i]==t[j])
    //   {
    //       j++;
    //       arr[i]=j;
    //   }
    //   else
    //   j=0;
    // }
     int lt=t.length();
    int arr[lt+1];
    memset(arr,-1,sizeof(arr));
    int j=0;
    for(int i=1;i<lt;i++)
     if(t[i]==t[j])
      {
          
          arr[i]=j;
          j++;
      }
      else
      j=0;
   for(int i=0;i<lt;i++)
   cout<<arr[i]<<" ";

}
int main()
{   string t;
cout<<"Enter"<<endl;
    cin>>t;
KMP(t);
    return 0;
}