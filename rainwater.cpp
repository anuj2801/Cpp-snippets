#include<bits/stdc++.h>
using namespace std;
void printt(vector<int> a)
{
    for(auto i=a.end()-1;i>=a.begin();i--)
    cout<<*i<<" ";
}
int waterUsingStack(vector<int> a)
{
  stack<int> st;
  int n=a.size(),ans=0;

    for(int i=0;i<n;i++)
    { 
      while(!st.empty() and a[st.top()] <a[i])
      { int cur=st.top();
        st.pop();
        if(st.empty())
        break;
        int diff=i-st.top()-1;
        ans+=(min(a[st.top()],a[i])-a[cur])*diff;
      } st.push(i);
    }
    return ans;
}
int waterBruteForce(vector<int> a)
{   int sum=0;
    int n=a.size();
    vector<int> RightMax(n);
    //vector<int> LeftMax(n);
    int uptilLeftMax=0;
   for(int i=n-1;i>0;i--)
    RightMax[i-1]=max(RightMax[i],a[i]);
   for(int i=0;i<n;i++)
    { int x=min(RightMax[i],uptilLeftMax)-a[i];
      if(x>0)
      sum+=x;
      uptilLeftMax=max(uptilLeftMax,a[i]);
    }
      return sum;
}

int main()
{  vector<int> v;
   v.push_back(5);
    v.push_back(2);
     v.push_back(3);
      v.push_back(1);
       v.push_back(2);
       //printt(v);
       cout<<waterBruteForce(v)<<endl;
       cout<<waterUsingStack(v)<<endl;

    return 0;
}
