#include<bits/stdc++.h>
using namespace std;
// Z[i] is the length of the longest substring starting from S[i] which is also a prefix of S
vector<long long> z_function(string s) {
    int n=s.size();
    vector<long long> z(n);
    z[0]=0;
    for (long long i=1,l=0,r=0;i<n;i++) {
        if(i<=r)
         z[i]=min(r-i+1,z[i - l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])
          z[i]++;
        if(i+z[i]-1>r)
         l=i,r=i+z[i]-1;
    }
    return z;
}
int main()
{
    string s;
    cin>>s;
    vector<long long> z=z_function(s);
    for(int i=0;i<s.size();i++)
     cout<<z[i]<<" ";

}