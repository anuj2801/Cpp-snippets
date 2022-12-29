#include<iostream>
#include<string>
using namespace std;
string keypadValues[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//when keypad is typed eg.s="23653"
void keypad(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    int typed=s[0]-'0';
    string alphabetSet=keypadValues[typed];
    for(int i=0;i<alphabetSet.length();i++)
    keypad(s.substr(1),ans+alphabetSet[i]);

}
//when two buttons are used
// void twoClick(string s1,char ans1,string s2,char ans2)
// {   if(ans1!=' '&&ans2!=' ')
//       {
//           cout<<ans1<<ans2<<endl;
//                  return;
//       }
//      if(ans1==' '&&s1.length()!=0)
//    {   char ch1=s1[0];
//     s1=s1.substr(1);
//     twoClick(s1,ch1,s2,ans2);
//     twoClick(s1,' ',s2,ans2);
//    }    
//   else if(s2.length()!=0){
//     char ch2=s2[0];
//     s2=s2.substr(1);
//     twoClick(s1,ans1,s2,ch2);
//     twoClick(s1,ans1,s2,' ');
//    }       
    
// }
int main()
{ 
    keypad("235","");
    
    return 0;
}