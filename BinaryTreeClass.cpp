#include<bits/stdc++.h>
using namespace std;
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
void printVector(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}
void levelTraversal(Node* root)
{  if(root==NULL)
    return;
    
    queue<Node*> q;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty())
    {    q.push(NULL);
        while(q.front()!=NULL)
        {    Node* left=q.front()->left;
            if(left!=NULL)
            {cout<<left->data<<" ";
            q.push(left);}
             Node* right=q.front()->right;
            if(right!=NULL)
            {cout<<right->data<<" ";
            q.push(right);}
            q.pop();
        }
       q.pop();
    }
}

int count(Node* root)
{ if(root==NULL)
  return 0;
  return count(root->left)+count(root->right)+1;
}
int sum(Node* root)
{ if(root==NULL)
  return 0;
  return sum(root->left)+sum(root->right)+root->data;
}
int height(Node* root)//means max height of the tree
{ if(root==NULL)
   return 0;
   return max(height(root->left),height(root->right))+1;
}
//Diameter of a tree is the longest path between any two leaf nodes
//using height function O(n^2)
int diameter(Node* root)
{   if(root==NULL)
     return 0;
    int currentDiameter=height(root->left)+height(root->right)+1;
    return max(currentDiameter,max(diameter(root->right),diameter(root->left)));

}
//using one pointer for height O(n)
int diameterUsingPointer(Node* root,int* height)
{   if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int leftHeight=0,rightHeight=0;
    int leftDiameter=diameterUsingPointer(root->left,&leftHeight);
    int rightDiameter=diameterUsingPointer(root->right,&rightHeight);
    int currentDiameter=leftHeight+rightHeight+1;
    *height=max(leftHeight,rightHeight)+1;
    return max(currentDiameter,max(leftDiameter,rightDiameter));
}

void sumReplace(Node* root)
{  
    if(root==NULL)
    return;
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left!=NULL)
    root->data+=root->left->data;
    if(root->right!=NULL)
    root->data+=root->right->data;
}

//Time complexity O(n),using height pointer, if we use height function for height calculation then TC O(n^2)
//balanced binary tree means mod of difference of right and left subtree<=1
bool balancedBinaryTree(Node* root,int *height)
{
    if(root==NULL)
    {
        *height=0;
        return true;
    }
    int leftHeight=0,rightHeight=0;
    if(!(balancedBinaryTree(root->left,&leftHeight)&&balancedBinaryTree(root->right,&rightHeight))||abs(leftHeight-rightHeight)>1)
         return false;
         *height=max(leftHeight,rightHeight)+1;
    return true;
}

//Right-view od binary tree means print those nodes which are visible when viewed from right(ie,right most node of each level)
//using level traversal method
void rightView(Node* root)
{  if(root==NULL)
    return;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {    q.push(NULL);
          Node* rightMostNode;
         while(q.front()!=NULL)
        {  rightMostNode=q.front();
           if(q.front()->left!=NULL)
           q.push(q.front()->left);
           if(q.front()->right!=NULL)
           q.push(q.front()->right);
           q.pop();
        }
        cout<<rightMostNode->data<<" ";
       q.pop();
    }
}
void leftView(Node* root)
{  if(root==NULL)
    return;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {    q.push(NULL);
         cout<<q.front()->data<<" ";
         while(q.front()!=NULL)
        { 
           if(q.front()->left!=NULL)
           q.push(q.front()->left);
           if(q.front()->right!=NULL)
           q.push(q.front()->right);
           q.pop();
        }
       q.pop();
    }
}
bool shortestDistanceBetweenTwoNodes(Node* root,int n1,int n2,int *height,bool* both)//return represents anyone is found or not both represents both found or not
{
    if(root==NULL)
    {   *height=0;
        return false;
    }
    if(root->data==n1||root->data==n2)
    {   *height=1;
        return true;
    }
    int leftHeight=0,rightHeight=0;
    bool leftTree=shortestDistanceBetweenTwoNodes(root->left,n1,n2,&leftHeight,both);
    bool rightTree=shortestDistanceBetweenTwoNodes(root->right,n1,n2,&rightHeight,both);
    if(leftTree&&rightTree)
    {*height=leftHeight+rightHeight; 
    *both=true;
     return true;
    }
    if(leftTree)
    {    if(*both==false)
        *height=leftHeight+1;
        else 
        *height=leftHeight;
        return true;
    }
    if(rightTree)
    {    if(*both==false)
        *height=rightHeight+1;
        else
        *height=rightHeight;
        return true;
    }


}

Node* FlattenBinaryTree(Node* root)
{   if(root==NULL)
    return NULL;
    Node* rightMostOfleftTree=FlattenBinaryTree(root->left);
    Node* rightHead=root->right;
    if(root->left!=NULL)
    {root->right=root->left;
    rightMostOfleftTree->right=rightHead;
    }
    root->left=NULL;
    if(root->right==NULL)
       if(rightMostOfleftTree!=NULL)
       return rightMostOfleftTree;
       else
       return root;
    return FlattenBinaryTree(root->right);
}
//Nodes at distance K
void storeSubtreeNodesAtdistanceK(Node *root,int k,vector<int> &v)//using
{ if(root==NULL||k<0)
   return;
   if(k==0)
   {v.push_back(root->data);
   return;
   }
   storeSubtreeNodesAtdistanceK(root->left,k-1,v);
   storeSubtreeNodesAtdistanceK(root->right,k-1,v);
}
int nodesAtDistannceK(Node* root,Node* target,int k,vector<int> &v)//main
{
    if(root==NULL)
    return -1;
    if(root==target)
    {   
        storeSubtreeNodesAtdistanceK(root,k,v);
        return 1;
    }
    int dl=nodesAtDistannceK(root->left,target,k,v);
    int dr=nodesAtDistannceK(root->right,target,k,v);
    if(dl!=-1)
     { if(k-dl==0)
        v.push_back(root->data);
        else
        storeSubtreeNodesAtdistanceK(root->right,k-dl-1,v);
        return dl+1;
     }
     if(dr!=-1)
     {
         if(k-dr==0)
         v.push_back(root->data);
         else
         storeSubtreeNodesAtdistanceK(root->left,k-dr-1,v);
         return dr+1;
     }
   
}

Node* lowestCommonAncestor(Node* root,int n1,int n2,bool* both)
{
    if(root==NULL)
    return NULL;
    if(root->data==n1||root->data==n2)
    return root;
    Node* Right=lowestCommonAncestor(root->right,n1,n2,both);
    Node* Left=lowestCommonAncestor(root->left,n1,n2,both);
    if(Right!=NULL&&Left!=NULL)
    {   *both=true;
        return root;
    }
    if(Left!=NULL)
        return Left;
     if(Right!=NULL)
        return Right;
    return NULL;
}

int maxSumPath(Node *root,int &maxsum)
{   if(root==NULL)
     return 0;
    int Right=maxSumPath(root->right,maxsum);
    int Left=maxSumPath(root->left,maxsum);
    maxsum=max(maxsum,max(root->data,max(root->data+Right+Left,max(root->data+Right,root->data+Left))));
    return max(root->data,max(root->data+Right,root->data+Left));//single path thats why not included rootdata+left+right
}

//MyLogicUSingDeque(like level traversal)
void ZigZagTraversal(Node* root)
{  if(root==NULL)
    return;
    
    deque<Node*> dq;
    dq.push_back(root);
    cout<<root->data<<" ";
    bool RightToLeft=true;
    while(!dq.empty())
    {
        
        if(RightToLeft)
        {   dq.push_back(NULL);
            while(dq.front()!=NULL)
            { if(dq.front()->right!=NULL)
               {   Node *Right=dq.front()->right;
                   cout<<Right->data<<" ";
                   dq.push_back(Right);
               }
               if(dq.front()->left!=NULL)
               {   Node *Left=dq.front()->left;
                   cout<<Left->data<<" ";
                   dq.push_back(Left);
               }
               dq.pop_front();
            }
            dq.pop_front();
           RightToLeft=!RightToLeft;
        }
        else
        {   dq.push_front(NULL);
            while(dq.back()!=NULL)
            {
                if(dq.back()->left!=NULL)
                {   Node* Left=dq.back()->left;
                    cout<<Left->data<<" ";
                    dq.push_front(Left);
                }
                if(dq.back()->right!=NULL)
                {  Node* Right=dq.back()->right;
                   cout<<Right->data<<" ";
                   dq.push_front(Right);
                }
                dq.pop_back();
            }
            dq.pop_back();
            RightToLeft=!RightToLeft;
        }
    }
}
//Using two stack
void ZIGZAGTraversal(Node* root)
{
    if(root==NULL)
    return;
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    currLevel.push(root);
    bool LeftToRight=true;
    while(!currLevel.empty())
    {   Node* temp=currLevel.top();
        currLevel.pop();
        if(temp)//false when temp=NULL
        {
          cout<<temp->data<<" ";
          if(LeftToRight)
          { if(temp->left)
              nextLevel.push(temp->left);
            if(temp->right)
               nextLevel.push(temp->right);
          }
          else
          {  if(temp->right)
               nextLevel.push(temp->right);
             if(temp->left)
              nextLevel.push(temp->left);
          }
          if(currLevel.empty())
          {
              LeftToRight=!LeftToRight;
              swap(currLevel,nextLevel);
          }
        }

    }
}

bool isIdenticalBST(Node* root1,Node* root2)
{  if(root1==NULL&&root2==NULL)
    return true;
    else if(root1==NULL||root2==NULL)
         return false;
    if(root1->data==root2->data)
    {
        bool leftSubTree=isIdenticalBST(root1->left,root2->left);
        bool rightSubtree=isIdenticalBST(root1->right,root2->right);
        return (leftSubTree&&rightSubtree);
    }
    return false;  
}

bool largestBSTinBT(Node* root,int *Min,int *Max,int *Size,int *maxsize)//maxsize of BST in BT
{  if(root==NULL)
    return true;
    int minL=INT_MAX,minR=INT_MAX,maxL=INT_MIN,maxR=INT_MIN,sizeL=0,sizeR=0;
    bool leftSubtree=largestBSTinBT(root->left,&minL,&maxL,&sizeL,maxsize);
    bool rightSubtree=largestBSTinBT(root->right,&minR,&maxR,&sizeR,maxsize);
    if(leftSubtree and rightSubtree)
         if(root->data>maxL and root->data<minR)
         {
             *Min=min(minL,root->data);
             *Max=max(maxR,root->data);
             *Size=sizeL+sizeR+1;
             *maxsize=max(*maxsize,*Size);
             return true;
         }

    return false;
}

//when two nodes of a BST are swapped
void findPropertyViolationPoints(Node* root,Node** first,Node** mid,Node** last,Node** prev)
{  
    if(root=NULL)
    return ;
    findPropertyViolationPoints(root->left,first,mid,last,prev);
    if(*prev && root->data < (*prev)->data)
    {
        if(!first)
        {
            *first=*prev;
            *mid=root;
        }
        else
        *last=root;
    }
    *prev=root;
    findPropertyViolationPoints(root->right,first,mid,last,prev);
}
void restoreBinaryTree(Node* root)
{
    Node *first=NULL,*mid=NULL,*last=NULL,*prev=NULL;
    //first=prev node ,where property violates for the first time
    //mid=root node,where property violates for the first time
    //last=root node,where property violates for the second time(if not adjacent ,this condition will occur )
    //case 1: 1,2,4,3,5,6,7,8 (inorder)
    //case 2: 1,8,3,4,5,6,7,2 (inorder)
    findPropertyViolationPoints(root,&first,&mid,&last,&prev);
    if(first!=NULL and mid!=NULL)
      if(last==NULL)//case  1:adjacent nodes
      {
          int temp=first->data;
          first->data=mid->data;
          mid->data=temp;
      }
      else // non adjacent nodes
      {
          int temp=first->data;
          first->data=last->data;
          last->data=temp;
      }
}
int main()
{
    Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
    root->right->left = new Node(7);
     root->right->left->right = new Node(9);
    root->right->right= new Node(8);

	root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->right = new Node(6);



// cout<<"No of nodes "<<count(root)<<endl;
// cout<<"Sum of nodes "<<sum(root)<<endl;
// cout<<"Height of the tree "<<height(root)<<endl;
// cout<<"Diameter of the tree "<<diameter(root)<<endl;
// int height=0;
// cout<<"Diameter of the tree "<<diameterUsingPointer(root,&height)<<endl;
// levelTraversal(root);
// sumReplace(root);
// levelTraversal(root);
// cout<<endl;
// int height2=0;
// if(balancedBinaryTree(root,&height2))
// cout<<"Balanced"<<endl;
// else
// cout<<"not balanced"<<endl;
// rightView(root);
// leftView(root);

// int height=0;bool both=false;
// if(shortestDistanceBetweenTwoNodes(root,6,9,&height,&both)&&both) //eg.distance between 3 nodes is 2.
// cout<<height<<endl;
// else
// cout<<"not found";

 //FlattenBinaryTree(root);
 //levelTraversal(root);

//  vector<int> v;
//  nodesAtDistannceK(root,root->right->left,3,v);
//  printVector(v);

// bool both=false;
// Node* ans=lowestCommonAncestor(root,8,9,&both);
// if(both)
// cout<<ans->data<<endl;
// else
// cout<<"Not found"<<endl;

// int maxSum=INT_MIN;
// maxSumPath(root,maxSum);
// cout<<maxSum<<endl;

// ZigZagTraversal(root);
//ZIGZAGTraversal(root);

 //Node* root2 = new Node(1);
// 	root2->left = new Node(2);
// 	root2->right = new Node(3);
//     root2->right->left = new Node(7);
//      root2->right->left->right = new Node(9);
//     root2->right->right= new Node(8);

// 	root2->left->left = new Node(4);
//     root2->left->left->left = new Node(5);
//     root2->left->left->right = new Node(6);
//      root2->left->left->right->right = new Node(6);  
// if(isIdenticalBST(root,root2))
//  cout<<"Identical"<<endl;
//  else
//  cout<<"Not Identical"<<endl;

//  Node* root = new Node(40);
// 	root->left = new Node(25);
// 	root->right = new Node(70);
//     root->right->left = new Node(60);
//      root->right->left->right = new Node(65);
//     root->right->right= new Node(75);
// 	root->left->left = new Node(15);
//     root->left->left->left = new Node(10);
//     root->left->left->right = new Node(20);
//  int min=INT_MAX,max=INT_MIN,size=0,maxsize=0;  
// largestBSTinBT(root,&min,&max,&size,&maxsize);
// cout<<" Max size = "<<maxsize<<endl;

    //              1
//         2               3
//      4     NULL    7        8 
//     5  6       NULL   9   NULL NULL
//   N  N N  N 
    return 0;
}