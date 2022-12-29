#include<bits/stdc++.h>
using namespace std;
int catalan(int n)
{
    if(n<=1)
    return 1;
    int res=0;
    for(int i=0;i<=n-1;i++)
    res+=catalan(i)*catalan(n-i-1);
    return res;
}
//Using Dynamic Programming Optimized solution using space 
int catalanUsingDp(int n)
{   if(n<=1)
     return 1;
    int catalanNumbers[n+1]={0};
    catalanNumbers[0]=catalanNumbers[1]=1;
    for(int i=2;i<=n;i++)
         for(int j=0;j<=i-1;j++)
           catalanNumbers[i]+=catalanNumbers[j]*catalanNumbers[i-j-1];
    return catalanNumbers[n];  
    
}

class Node{
    public:
     int data;
     Node *left;
     Node *right;
     Node(int val)
     {
         data=val;
         left=NULL;
         right=NULL;
     }
};
vector<Node*> constructPossibleBST(int Min,int Max)// start is the min value present in the tree ,end is the max value present in the tree
{ vector<Node*>trees;
  if(Min>Max)
   {trees.push_back(NULL);
     return trees;
   }
   for(int i=Min;i<=Max;i++)
   {
       vector<Node*> leftSubtrees=constructPossibleBST(Min,i-1);
       vector<Node*> rightSubtrees=constructPossibleBST(i+1,Max);
       for(int j=0;j<leftSubtrees.size();j++)
       { Node* Left=leftSubtrees[j];
         for(int k=0;k<rightSubtrees.size();k++)
          {  Node* Right=rightSubtrees[k];
             Node* root=new Node(i);
             root->left=Left;
             root->right=Right;
             trees.push_back(root);
          }
       }

   }

}
void preorder(Node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
} 

int main()
{
//     for(int i=0;i<=10;i++)
//     cout<<catalan(i)<<" ";
//     cout<<endl;
//     for(int i=0;i<=10;i++)
//     cout<<catalanUsingDp(i)<<" ";
vector<Node*> p=constructPossibleBST(1,3);
for(int i=0;i<p.size();i++)
{
    preorder(p[i]);
    cout<<endl;
}
  return 0;
}