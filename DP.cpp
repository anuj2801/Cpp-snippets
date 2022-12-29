#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//O(n^2)
int longestSubsequence()
{   
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter n elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> maxSubsequencetforThatIndex(n,1);
    for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
     if(arr[j]<arr[i])
      maxSubsequencetforThatIndex[i]=max(maxSubsequencetforThatIndex[i],1+maxSubsequencetforThatIndex[j]);   

    // for(int i=0;i<n;i++)
    // cout<<maxSubsequencetforThatIndex[i]<<" ";
    int lsi=1;
    for(int i=0;i<n;i++)
     if(lsi<maxSubsequencetforThatIndex[i])
     lsi=maxSubsequencetforThatIndex[i];
     cout<<"longest increasing subsequence is "<<lsi<<endl;
    
}
//LCS
int n,m;
string s1,s2;
vector<vector<int>> f;
int lcs(int i,int j)
{  
    if(i==-1||j==-1)
      return 0;
    else if(f[i][j]!=-1)
     return f[i][j];
      else if(s1[i]==s2[j])
           f[i][j]=1+lcs(i-1,j-1);
           else 
           f[i][j]=max(lcs(i-1,j),lcs(i,j-1));
  return f[i][j];
}
void longestCommonSubsequence()
{
    cout<<"Enter two strings"<<endl;
    cin>>s1>>s2;///input words
        n=s1.size();
        m=s2.size();
      f=vector<vector<int>>(n,vector<int>(m,-1));//to store lcs
      cout<<"Longest common subsq="<<lcs(n-1,m-1);
}

//repeating 1 should not be there
//can also be done by fibonacci(l+1)
int countNoOfDistinctBinaryStrings(int l,int &NoOfOnesForCurrentLength)
{ if(l==1)
  {
    NoOfOnesForCurrentLength=1;
    return 2;
  }
  int noOfOnes=0;
  int length=countNoOfDistinctBinaryStrings(l-1,noOfOnes);
  int noOfZeros=length-noOfOnes;
  int newLength=2*noOfZeros+noOfOnes;
  NoOfOnesForCurrentLength=noOfZeros;
  return newLength;
}
int main()
{   
    //longestSubsequence();
    //longestCommonSubsequence();

    int l,a;
    cout<<"Enter Length"<<endl;
    cin>>l;
    cout<<countNoOfDistinctBinaryStrings(l,a);
    return 0;
}