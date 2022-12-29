#include<bits/stdc++.h>
using namespace std;
// ax+by=gcd(a,b) 
// a,b given,  we have to find INTEGRAL ANSWER for  x  and  y
// x,y may come -ve
void ExtendedEucledian(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return;
    }
    long long x1,y1;
    ExtendedEucledian(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;

}
int main()
{
    long long x,y;
    ExtendedEucledian(7,2,x,y);
    cout<<x<<" "<<y<<endl;
    return 0;
}