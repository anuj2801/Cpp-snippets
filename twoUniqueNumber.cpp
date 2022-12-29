#include <iostream>
using namespace std;
int getPosOfBit(int val)
{int count=0;
  while(val%2==0)
  {   val>>=1;
   count++;
  }
  return count;
}
bool isBitPresent(int val,int pos)
{ return (val&(1<<pos));
}
void UniqueNumber(int a[],int len) //when two unique nos are present
{                              
   int xorsum=0;
   for(int i=0;i<len;i++)
    xorsum^=a[i];   
    int newxorsum=0;
     int pos=getPosOfBit(xorsum);
  for(int i=0;i<len;i++)
   if(isBitPresent(a[i],pos))
      newxorsum^=a[i];

cout<<newxorsum<<endl;
cout<<(xorsum^newxorsum);
}

int main()
{
    int a[10]={1,2,4,5,9,2,5,3,1,4};
    UniqueNumber(a,10);
    return 0;
}
