#include<bits/stdc++.h>
using namespace std;
int max_size_rectangle(vector<int> v)
{   v.push_back(0);
    int n=v.size(),ans=0,i=0;
    
    stack<int> s;//store the index
    while(i<n)
    {   while(!s.empty()&&v[s.top()]>v[i])
       {
           int h=v[s.top()];
           s.pop();
           if(s.empty())
           ans=max(ans,h*i);
           else
           {
               int len=i-s.top()-1;//removing elements will not effect as their heights will be still used
                                   //since we use the index of prev element to find length
                                   // eg. 3 11 12 13 10 0  index=0,1,2,3,4,5 when we find 6, remove 13,12,11,but in 13,12,11 height 10 must be calculated
                                   //this will be done :after removing ,stack:0,4,5  and after i++ i=5
                                   // len= 5-1-1=3, so area=4*len=12 
               ans=max(ans,h*len);
           }
       }
       s.push(i);
        i++;
    }
   return ans;

}
int main()
{  vector<int> v;
   v.push_back(3);
    v.push_back(11);
     v.push_back(12);
      v.push_back(13);
       v.push_back(10);
       cout<<max_size_rectangle(v);
    return 0;
}
