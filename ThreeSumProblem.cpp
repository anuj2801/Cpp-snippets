#include<bits/stdc++.h>
using namespace std;
//BruteForce O(n^3)
//This method O(n logn) for sorting   O(n^2) for finding
//so time complexity O(n^2)
bool ThreeSumUsingTwoPointer(vector<int> a,int sum)
{ sort(a.begin(),a.end());
   int n=a.size();
  for(int i=0;i<n;i++)
  { int low=i+1,high=n-1;
    while(low<high)
    { int currentSum=a[i]+a[low]+a[high];
      if(currentSum==sum)
      return true;
      else if(currentSum>sum)
      high--;
      else
      low++;
    }

  }
  return false;
}
int main()
{  vector<int> v;
   v.push_back(5);
    v.push_back(2);
     v.push_back(3);
      v.push_back(1);
       v.push_back(2);
     if(ThreeSumUsingTwoPointer(v,12))
     cout<<"found";
     else
     cout<<"not found";
      

    return 0;
}
