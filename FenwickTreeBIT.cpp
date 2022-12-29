#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> bit;
void update(int idx,int val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx)
{   
    int ans=0;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=idx&(-idx);
    }
    return ans;
}


int main()
{  
    //1 BASED INDEXING FOR FENWICK TREE or BINARY INDEX TREE


    //Sum of l to r
    // cout<<"Enter number of elements: "<<endl;
    // cin>>n;
    // vector<int> v(n+1);
    // bit=vector<int>(n+1,0);
    // for(int i=1;i<=n;i++)
    // { cin>>v[i];
    //   update(i,v[i]);
    // }
    // int op;
    // cout<<"Enter number of operations : "<<endl;
    // cin>>op;
    // while(op--)
    // {
    //     int type;
    //     cout<<"Enter 1 for update ,2 for query"<<endl;
    //     cin>>type;
    //     if(type==1)
    //     {
    //         cout<<"Enter index and value"<<endl; //index starts from 1
    //         int idx,val;
    //         cin>>idx>>val;
    //         update(idx,-v[idx]);
    //         v[idx]=val;
    //         update(idx,val);
    //     }
    //     else if(type==2)
    //     {
    //         cout<<"Enter l and r for query"<<endl; //index starts from 1
    //         int l,r;
    //         cin>>l>>r;
    //         int res=query(r)-query(l-1); //sum of l to r= sum of 0 to r - sum of 0 to l-1
    //         cout<<res<<endl;
    //     }
    // }


    //Count inversion
    // cout<<"Enter number of elements: "<<endl;
    // cin>>n;
    // vector<int> v(n);
    // bit=vector<int>(n+1,0);
    // for(int i=0;i<n;i++)
    //  cin>>v[i];
    // vector<int> temp(v);
    // sort(temp.begin(),temp.end());
    // for(int i=0;i<n;i++)
    //  v[i]=lower_bound(temp.begin(),temp.end(),v[i])-temp.begin()+1;  //so starts from 1 // making the position of the items ,when in sorted ,as the values
    // int count=0;                                                     // since if n=1e5 this algo works but if v[i]<=1e9 we cannot create bit vector<int> bit of size 1e9 and also -ve numbers
    // for(int i=n-1;i>=0;i--)
    // {
    //     count+=query(v[i]-1);  //  query(v[i])-1 is wrong since value of v[i] may be present 2 3..times 
    //     update(v[i],1);
    // }
    // cout<<"Number of inversions : "<<count<<endl;


    cout<<"STOPPED"<<endl;
    return 0;
}