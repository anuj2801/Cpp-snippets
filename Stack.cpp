#include<iostream>
using namespace std;

// #define n 100
// class stack{
// int *arr; int Top;
// public: 
// stack(){  arr=new int[n];
//           Top=-1;
//         }
//         void push(int x){
//                 if(Top==n-1){
//                     cout<<"Stack Overflow"<<endl;
//                     return;
//                 }
//                 Top++;
//                 arr [Top]=x;
//         }
//         void pop(){
//             if(Top==-1){
//                 cout<<"No element to pop"<<endl;
//                 return;
//             }
//             Top--;
//             }
//         int top(){
//             if(Top==-1){
//              cout<<"No element in stack"<<endl;
//              return -1;;
//             }
//             return arr[Top];
//         }
//         bool empty(){
//           return Top==-1;
//         }
// };

#include<queue>
//stack using 2 queue method 1, POP is costly

// class stack{
// queue<int> q1,q2; //q1 is main,q2 is helper
// int Size;
// public: 
// stack(){ Size=0;
//         }
//         void push(int x){
//                 q2.push(x);
//                 Size++;
//                 while(!q1.empty())
//                 {
//                     q2.push(q1.front());
//                     q1.pop();
//                 }
//                 q2.swap(q1);
//         }
//         void pop(){
//             if(q1.empty())
//             {
//                 cout<<"Queue underflow"<<endl;
//                 return;
//             }
//             q1.pop();
//             Size--;
//             }
//         int top(){
//             if(q1.empty())
//             {
//                 cout<<"Queue underflow"<<endl;
//                 return -1;
//             }
//            return q1.front();
//         }
//         int size()
//         {
//             return Size;  //q1.size();
//         }
//         bool empty(){
//           return Size==0; //q1.empty();
//         }
// };

//stack using 2 queue method 2,PUSH is costly

class stack{
queue<int> q1,q2; //q1 is main,q2 is helper
int Size;
public: 
stack(){ Size=0;
        }
        void push(int x){
                q1.push(x);
                Size++;
        }
        void pop(){
            if(q1.empty())
            {
                cout<<"Queue underflow"<<endl;
                return;
            }
            while(q1.size()!=1)
            { q2.push(q1.front());
              q1.pop();
            }
            q1.pop();
            q2.swap(q1);
            Size--;
            }
        int top(){
            if(q1.empty())
            {
                cout<<"Queue underflow"<<endl;
                return -1;
            }
            while(q1.size()!=1)
            { q2.push(q1.front());
              q1.pop();
            }
           int top=q1.front();
            q2.push(top);
            q1.pop();
            q2.swap(q1);
           return top;
        }
        int size()
        {
            return Size;  //q1.size();
        }
        bool empty(){
          return Size==0; //q1.empty();
        }
};

void printStack(stack st)
{   
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

//#include<stack>
// //Reversing stack without using extra stack ,BUT call stack  is used(stack which is used incase of recursion)
// void insertAtButtom(stack<int> &st,int topElement)
// {   if(st.empty())
//     {st.push(topElement);
//     return;
//     }
//     int element=st.top();
//     st.pop();
//     insertAtButtom(st,topElement);
//     st.push(element);
// }
// void reverseStack(stack<int> &st)
// {   if(st.empty())
//      return;
//     int topElement=st.top();
//     st.pop();
//     reverseStack(st);
//     insertAtButtom(st,topElement);
// }
int main()
{
   stack s=stack();
     s.push(6);
     s.push(5);
     s.push(7);
     cout<<s.size()<<endl;
     cout<<s.top()<<endl;
     s.pop();
     cout<<s.top()<<endl;
     cout<<s.empty()<<endl;
      s.pop();
       s.pop();
        cout<<s.top()<<endl;
     cout<<s.empty()<<endl;
    //   stack<int> st;
    //   st.push(1);
    //    st.push(2);
    //     st.push(3);
    //     st.push(4);
    //     st.push(5);
    //     st.push(6);
    //     st.push(7);
    //     printStack(st);
    //     reverseStack(st);
    //     printStack(st);


    return 0;
}