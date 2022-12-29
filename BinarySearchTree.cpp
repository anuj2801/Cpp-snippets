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
//Binary Search Tree 
//N DUPLICATE NODES
//all datas of Left Subtree are less than current Node's value
//all datas of Right Subtree are greater than current Node's value
Node* insertBST(Node* root,int val)
{ 
    if(root==NULL)
     return new Node(val);
    if(root->data<val)
    root->right=insertBST(root->right,val);
    else 
        //when root->data > val
       root->left=insertBST(root->left,val);
    return root;
}

Node* search(Node* root,int val)
{   if(root==NULL)
     return NULL;
    if(root->data==val)
    return root;
    else if(root->data<val)
    return search(root->right,val);
    else
    return search(root->left,val);
}
//delete a node
Node* InorderSuccessor(Node* root)
{ Node* curr=root;
 while(curr and curr->left!=NULL)
 curr=curr->left;
 return curr;
}
Node* deleteBst(Node* root,int val)
{    if(root==NULL)
      return NULL;
    if(root->data==val)
    {
        if(root->left==NULL)
        {   Node* temp= root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
             Node* temp= root->left;
            free(root);
            return temp;
        }
        else
         {
             Node* temp=InorderSuccessor(root->right);
             root->data=temp->data;
             root->right=deleteBst(root->right,temp->data);
         }
    }
    else if(root->data<val)
    root->right=deleteBst(root->right,val);
     else 
      root->left=deleteBst(root->left,val);
 return root;
}

//Build BST using preorder
Node* buildBSTFromPreoder(string preorder,int min,int max)
{   static int index=0;
    if(index==preorder.size())
    return NULL;
    if((preorder[index]-'0')<max and (preorder[index]-'0')>min)
    {Node* temp=new Node(preorder[index++]-'0');
     temp->left=buildBSTFromPreoder(preorder,min,temp->data);
     temp->right=buildBSTFromPreoder(preorder,temp->data,max);
     return temp;
    }
    return NULL;
}

bool checkBST(Node* root,int min,int max)
{
    if(root==NULL)
    return true;
    if(root->data<max and root->data>min)
      return (checkBST(root->left,min,root->data) and checkBST(root->right,root->data,max));
    return false;
}

Node* buildBalancedBSTUsingSortedArray(int arr[],int start,int end)
{  if(start>end)
    return NULL;
  int mid=(start+end)/2;
  Node* root=new Node(arr[mid]);
  root->left=buildBalancedBSTUsingSortedArray(arr,start,mid-1);
  root->right=buildBalancedBSTUsingSortedArray(arr,mid+1,end);
  return root;
}
void levelTraversal(Node* root)
{  if(root==NULL)
    return;
    
    queue<Node*> q;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty())
    {    q.push(NULL);
      cout<<endl;
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
//Incase of BST inorder is sorted
void inorder(Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main()
{
    // Node* root = new Node(40);
	// root->left = new Node(25);
	// root->right = new Node(70);
    // root->right->left = new Node(60);
    //  root->right->left->right = new Node(65);
    // root->right->right= new Node(75);

	// root->left->left = new Node(15);
    // root->left->left->left = new Node(10);
    // root->left->left->right = new Node(20);

    Node *root=new Node(40);
    insertBST(root,25);
    insertBST(root,70);
    insertBST(root,15);
    insertBST(root,60);
    insertBST(root,75);
    insertBST(root,10);
    insertBST(root,20);
    insertBST(root,65);

    // levelTraversal(root);
    // insertBST(root,34);
    
    
    // if(search(root,70)!=NULL)
    // cout<<"key exists"<<endl;
    // else
    // cout<<"not found"<<endl;

    // levelTraversal(root);
    // deleteBst(root,40);
    

    
    //Node* build=buildBSTFromPreoder("754689",INT_MIN,INT_MAX);
   

    // if(checkBST(root,INT_MIN,INT_MAX))
    // cout<<"It is VALID BST"<<endl;
    // else
    //  cout<<"It is NOT VALID BST"<<endl;
    int arr[]={10,20,30,40,50};
   Node* head=buildBalancedBSTUsingSortedArray(arr,0,*(&arr+1)-arr-1);



levelTraversal(head);
inorder(head);

    //              40
//         25               70
//      15     NULL     60        75 
//    10  20       NULL    65   NULL NULL
//   N  N N  N 
    return 0;
}