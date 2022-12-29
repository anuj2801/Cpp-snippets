#include<iostream>
using namespace std;


//#define n 100
// class queue{
// int *arr; int Front,Back;
// public: 
// queue(){  arr=new int[n];
//           Front=Back=-1;
//         }
//         void push(int x){    //enqueue
//                 if(Back==n-1){
//                     cout<<"Queue Overflow"<<endl;
//                     return;
//                 }
//                 Back++;
//                 arr [Back]=x;
//                 if(Front==-1)
//                 Front++;
//         }
//         void pop(){      //deququeue
//             if(Front==-1||Front>Back){
//                 cout<<"No element in Queue"<<endl;
//                 return;
//             }
//             Front++;
//             }
//         int front(){    //peek
//             if(Front==-1||Front>Back){
//              cout<<"No element in stack"<<endl;
//              return -1;;
//             }
//             return arr[Front];
//         }
//         bool empty(){
//           return (Front==-1||Front>Back);
//         }
//};

//Beeter approach using nodes
// class Node{
//    public:
//     int data;
//     Node* next;
//     Node(int n)
//             { data=n;
//               next=NULL;
//             }
// };
// class queue{
//  Node *Front,*Back;
// public: 
// queue(){  
//           Front=Back=NULL;
//         }
//         void push(int x){    //enqueue
//              Node* n=new Node(x);
//                if(Front==NULL)
//                {
//                    Front=n;
//                    Back=n;
//                    return;
//                }
//                Back->next=n;
//                Back=Back->next;
//         }
//         void pop(){      //dequeue
//            if(Front==NULL){
//                 cout<<"Queue Underflow"<<endl;
//                 return;
//             }
//             Node* todelete=Front;
//             Front=Front->next;
//             delete todelete;
//             }
//         int front(){    //peek
//             if(Front==NULL){
//              cout<<"No element in stack"<<endl;
//              return -1;;
//             }
//             return Front->data;
//         }
//         bool empty(){
//           return (Front==NULL);
//         }
// };

//queue using two stack
#include<stack>
// class queue{
//   stack<int> s1,s2;
//    public: void push(int x){    //enqueue
//              s1.push(x);
//         }
//         void pop(){      //deququeue // pop operation is costly here O(n)
//          if(s1.empty()&&s2.empty())
//          {
//            cout<<"Queue underflow"<<endl;
//            return;
//          }
//           if(s2.empty())
//           while(!s1.empty())
//           {
//             s2.push(s1.top());
//             s1.pop();
//           }
//           s2.pop();
//             }
//         int front(){    //peek
//         if(s1.empty()&&s2.empty())
//          {
//            cout<<"Queue underflow"<<endl;
//            return -1;
//          }
//             if(s2.empty())
//           while(!s1.empty())
//           {
//             s2.push(s1.top());
//             s1.pop();
//           }
//             return s2.top();
//         }
//         bool empty(){
//           return (s1.empty()&&s2.empty());
//         }
// };

//queue using 1 stack and 1 function call stack
class queue{
  stack<int> s;
   public: void push(int x){    //enqueue
             s.push(x);
        }
        void pop(){      //deququeue // pop operation is costly here O(n)
         if(s.empty())
         {
           cout<<"Queue underflow"<<endl;
           return;
         }
          int top=s.top();
          s.pop();
          if(s.empty())
          return;
          pop();  // can use this->pop();
          s.push(top);
          
        }
        int front(){    //peek
        if(s.empty())
         {
           cout<<"Queue underflow"<<endl;
           return -1;
         }
          int top=s.top();
          s.pop();
          if(s.empty())
          { s.push(top);
            return top;
          }
          int Front=front(); //this->front()
          s.push(top);
          return Front;
        }
        bool empty(){
          return s.empty();
        }
};


int main()
{
      queue s=queue();
     s.push(6);
     s.push(5);
     s.push(7);
     cout<<s.front()<<endl;
     s.pop();
     cout<<s.front()<<endl;
     cout<<s.empty()<<endl;
      s.pop();
       s.pop();
        cout<<s.front()<<endl;
     cout<<s.empty()<<endl;
     


    return 0;
}