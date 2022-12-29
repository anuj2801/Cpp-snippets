#include <bits/stdc++.h>
//#include<vector> 
using namespace std;
int main()
{
    vector<int> v;
 //   cout<<v.size()<<endl;
// v.insert(v.begin(),5);
    v.push_back(9);
     v.push_back(4);
      v.push_back(7);
      v.push_back(6);
     //  sort(v.begin(),v.end());
  //   cout<<v.capacity()<<endl;
    //   cout<<v.size()<<endl;
       //for(auto i=v.begin();i<v.end();i++)
       int m=*max_element(v.begin(),v.end());
       cout<<m<<endl;
     //cout<<*(v.begin())<<endl;

    return 0;
}
