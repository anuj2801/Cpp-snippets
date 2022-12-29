#include<bits/stdc++.h>
using namespace std;
struct cmpp {
	bool operator() (const int &a, const int &b) const {
		return a>b;
	}
};

int main()
{
    auto cmp=[](const int &a,const int &b)  // use (const ,&) or dont use anything at all
    {
        return a>b;
    };
    set<int,decltype(cmp)> s1(cmp);    // type1
    set<int,cmpp> s2;                  // type2


    int n,m;
    cin>>n>>m;
    int x;
    for(int i=0;i<n;i++)
     cin>>x,s1.insert(x);
    for(int i=0;i<m;i++)
     cin>>x,s2.insert(x);
    while(!s1.empty())
    {
        cout<<*s1.begin()<<" ";
        s1.erase(s1.begin());
    }
    cout<<endl;
    while(!s2.empty())
    {
        cout<<*s2.begin()<<" ";
        s2.erase(s2.begin());
    }
    cout<<endl;
    return 0;
}