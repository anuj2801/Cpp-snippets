#include<bits/stdc++.h>
using namespace std;


int N=1e5+3;
int M=1e9+7;
vector<long long> power(N);
void powerfill(int n)// n is the max length of string
{
    int p=27;
    power[0]=1;
 
    for(int i=1;i<=n;i++)
     power[i]=(power[i-1]*p)%M;
}
long long createHash(string x)
{
    long long res=0;
    //a->1 ....z->26
    for(int i=0;i<x.size();i++)
     res+=((x[i]-'a'+1)*power[i])%M;
    return res;
}
vector<long long> stringArrayToHashes(vector<string> s)
{
    vector<long long> v(s.size());
    for(int i=0;i<s.size();i++)
     v[i]=createHash(s[i]);
    return v;
}



int main()
{
    // m-> max length of string
    // n-> number of strings

    // powerfill(1e5);//TM: m
    // vector<string> s={"aa","ab","cc","aa","ac","aa"};
    // vector<long long> x=stringArrayToHashes(s);//TM : nm   
    // sort(x.begin(),x.end());// TM: nlogn

    // int distinct=0;
    // for(int i=0;i<x.size();i++)
    // { if(i==0 or x[i]!=x[i-1])
    //   distinct++;
    // }
    // cout<<"Number of distinct strings = "<<distinct<<endl;




    //formula

    // s="ab"
    //t="abxy
    //therefore, hash of(xy)=(1/p^2)*(hashof(abxy)-hashof(ab));
    //ie, hashof(i..j)=(1/p^i)*(hashof(0...j)-hashof(0..i-1));

    //hash of(0...i)=hashof(0..i-1)+(s[i]*p^i)%m

    //Find occurence of s in t

    powerfill(1e5);
    string s="ab";
    string t="xyabjkagabj";
    long long h_s=createHash(s);
    vector<long long> hashes(t.size()+1);//it will store hashesof subtring from 0 to i
    hashes[0]=0;
    for(int i=1;i<t.size()+1;i++)
     hashes[i]=hashes[i-1]+((t[i-1]-'a'+1)*power[i-1])%M;
    int S=s.size();
    for(int i=0;i+(S-1)<t.size();i++)
        if((power[i]*h_s)%M==(hashes[i+S]-hashes[i]+M)%M)
          cout<<"FOUND at-> "<<i<<endl;
    

    return 0;
}