#include<bits/stdc++.h>
using namespace std;
//Span of a stock's price today is defined as the maximum number of
//consecutive days (starting from today and going backwards)for which
//the price of the stocks was less than or equal to today's price.
void printt(vector<int> a)
{ 
    for(auto i:a)
    cout<<i<<" ";
}
void stockspan(vector<int> price)
{ vector<int> ans;
  stack<pair<int,int>> s;
  for(int i=0;i<price.size();i++)
  {   int days=1; //that day itself
      if(!s.empty() and s.top().first<=price[i])
      {
          days+=s.top().second;
          s.pop();
      }
      s.push({price[i],days});
      ans.push_back(days);
  }   
  printt(ans);
}
int main()
{  vector<int> v;
   v.push_back(5);
    v.push_back(2);
     v.push_back(3);
      v.push_back(1);
       v.push_back(2);
     stockspan(v);
      

    return 0;
}
