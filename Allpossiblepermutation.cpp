#include<iostream>
#include<string>
using namespace std;
void permutationOf(string fixed,string variable)
{
    if(variable.length()==0)
    {
       cout<<fixed<<endl;
       return;
    }
    for(int i=0;i<variable.length();i++)
    { string temp=variable;
      temp.erase(i,1);
      permutationOf(fixed+variable[i],temp);
    }

}
int main()
{  permutationOf("","ABCD");
    return 0;
}