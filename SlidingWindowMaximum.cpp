#include<iostream>
#include<vector>
using namespace std;
#include<set>
// vector<int> SlidingWindowMaxUsingMultiset(vector<int> v,int k)
// {
//     multiset<int,greater<int>> m;
//     vector<int> ans;
//     int len=v.size();
//     for(int i=0;i<len;i++)
//     {
//         m.insert(v[i]);
//         if(m.size()==k)
//         { ans.push_back(*m.begin());
//           m.erase(m.find(v[i-k+1]));
//         }
//     }
//     if(ans.empty()&&!m.empty())
//     ans.push_back(*m.begin());
//     return ans;
//}

#include<deque>
vector<int> SlidingWindowMaxUsingDequeue(vector<int> v,int k) //storing indices in deque,max Range of deque is k,index of max element is stored at front 
{    vector<int> ans;                                         //and elements right side to the max element (which are smaller),their indices are also stored for future needs
    deque<int> d;                                             // and elements left side...are not stored because they are never be required again
 
     int len=v.size();
     for(int i=0;i<len;i++)
    {   if(d.front()==i-k)
            d.pop_front();
        while(!d.empty()&& v[d.back()]<v[i])
           d.pop_back();
        d.push_back(i);
        if(i>=k-1)
         ans.push_back(v[d.front()]);
    }
    if(ans.empty()&&!d.empty())
    ans.push_back(d.front());
    return ans;
}

void print(vector<int> v)                                     
{
    for(auto i=v.begin();i<v.end();i++)
    cout<<*i<<" ";
}
int main()
{   
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
      v.push_back(-1);
       v.push_back(-3);
        v.push_back(5);
         v.push_back(3);
          v.push_back(6);
           v.push_back(7);
           v=SlidingWindowMaxUsingDequeue(v,3);
    print(v);
    return 0;
}