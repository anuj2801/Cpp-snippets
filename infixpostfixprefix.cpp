#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prefixEvaluation(string s)
{   stack<int> st;
    int len=s.length();
    for(int i=len-1;i>=0;i--)
     if(s[i]<='9'&&s[i]>='0')
        st.push(s[i]-'0');
     else
     {
         int operand1=st.top();
         st.pop();
         int operand2=st.top();
         st.pop();
         switch(s[i])
         {
            case '+': st.push(operand1+operand2);
                        break;
            case '-': st.push(operand1-operand2);
                        break;
            case '/': st.push(operand1/operand2);
                        break;
            case '*': st.push(operand1*operand2);
                        break;
            case '^': st.push(pow(operand1,operand2));
                        break;
            default: return -1; 
             
         }
     }
     return st.top();
}
int postfixEvaluation(string s)
{   stack<int> st;
    int len=s.length();
    for(int i=0;i<len;i++)
     if(s[i]<='9'&&s[i]>='0')
        st.push(s[i]-'0');
     else
     {
         int operand2=st.top();
         st.pop();
         int operand1=st.top();
         st.pop();
         switch(s[i])
         {
            case '+': st.push(operand1+operand2);
                        break;
            case '-': st.push(operand1-operand2);
                        break;
            case '/': st.push(operand1/operand2);
                        break;
            case '*': st.push(operand1*operand2);
                        break;
            case '^': st.push(pow(operand1,operand2));
                        break;
            default: return -1; 
             
         }
     }
     return st.top();
}

int precedence(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*'||c=='/')
    return 2;
    else if(c=='+'||c=='-')
    return 1;
    else
    return -1;//incase of '('
}
string infixToPostfix(string s)
{
    stack<char> st;
    string result="";
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
        result+=s[i];
        else if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')')
        { while(!st.empty() && st.top()!='(')
         {   
            result+=st.top();
            st.pop();
         }
         if(!st.empty())
         st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top())>=precedence(s[i]))
            {
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    return result;
}
//infix to prefix using postfix logic
string reverse(string s)
{   string reverse="";
    for(int i=s.length()-1;i>=0;i--)
    { if(s[i]=='(')
       reverse+=')';
       else if(s[i]==')')
       reverse+='(';
       else
       reverse+=s[i];
    }
    return reverse;
}
string infixToPrefix(string s)
{ s=reverse(s);
//converting infix to postfix
stack<char> st;
    string result="";
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
        result+=s[i];
        else if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')')
        { while(!st.empty() && st.top()!='(')
         {   
            result+=st.top();
            st.pop();
         }
         if(!st.empty())
         st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top())>precedence(s[i]))
            {
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    result=reverse(result);
    return result;
}
int main()
{
//   string s1="+*43++26-57";
//   cout<<prefixEvaluation(s1)<<endl;
   // string s2="46+2/5*7+";
   // cout<<postfixEvaluation(s2)<<endl;
   //string s3="a+b-c(d/e^f-g*h)+i";
   // cout<<infixToPostfix(s3)<<endl;
//    string s4="a+b-c*d/(e^f)";
//     cout<<infixToPrefix(s4)<<endl;



    string s5="a^b^c";
    cout<<infixToPostfix(s5)<<endl;
    //Expected output :   abc^^
    return 0;
}