#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
void preorder(struct Node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct Node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void TreeFromPreorderAndInorder(struct Node* &root,string pre,string in)
{   if(in.empty())
    return;
    static int index=0;
    int pos=in.find(pre[index]);
    root=new Node(pre[index]-'0');
    index++;
    TreeFromPreorderAndInorder(root->left,pre,in.substr(0,pos));
    TreeFromPreorderAndInorder(root->right,pre,in.substr(pos+1));  
}
//or,  amother pointer technique ,this is because it is struct and not object of a class
// void TreeFromPostorderAndInorder(struct Node** root,string pre,string in)
// {   if(in.empty())
//     return;
//     static int index=0;
//     int pos=in.find(pre[index]);
//     *root=new Node(pre[index]-'0');
//     index++;
//     TreeFromPostorderAndInorder(&((*root)->left),pre,in.substr(0,pos));
//     TreeFromPostorderAndInorder(&((*root)->right),pre,in.substr(pos+1));  
// }
//And in main , Node *h; Three.....(&h,"..","..");

void TreeFromPostorderAndInorder(struct Node* &root,string post,string in)
{   if(in.empty())
    return;
    static int index=post.size()-1;
    int pos=in.find(post[index]);
    root=new Node(post[index]-'0');
    index--;
    TreeFromPostorderAndInorder(root->right,post,in.substr(pos+1)); 
    TreeFromPostorderAndInorder(root->left,post,in.substr(0,pos));
     
}
void levelTraversal(struct Node* root)
{  if(root==NULL)
    return;
    
    queue<struct Node*> q;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty())
    {    q.push(NULL);
        while(q.front()!=NULL)
        {   struct Node* left=q.front()->left;
            if(left!=NULL)
            {cout<<left->data<<" ";
            q.push(left);}
            struct Node* right=q.front()->right;
            if(right!=NULL)
            {cout<<right->data<<" ";
            q.push(right);}
            q.pop();
        }
       q.pop();
    }
}
int sumOfNodesAtKlevel(struct Node* root,int k)
{    if(root==NULL)
    return 0;
    
     int sum=0,i=0;
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty())
    {    q.push(NULL);
        if(i!=k)
        while(q.front()!=NULL)
        {   
            struct Node* left=q.front()->left;
            if(left!=NULL)
            q.push(left);
            struct Node* right=q.front()->right;
            if(right!=NULL)
            q.push(right);
            q.pop();

        }
        if(i==k)
        {
            while(q.front()!=NULL)
           {   sum+=q.front()->data;
               q.pop();
           }
           break;
        }
        i++;
       q.pop();
    }
    return sum;
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
    root->right->left = new Node(7);
     root->right->left->right = new Node(9);
    root->right->right= new Node(8);

	root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->right = new Node(6);
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl<<"Inorder: ";
    inorder(root);
    cout<<endl<<"postorder: ";
    postorder(root);
    
    struct Node* h;
   // TreeFromPreorderAndInorder(h,"124563798","546217938");
   //TreeFromPostorderAndInorder(h,"564297831","546217938");
   //  cout<<endl<<"Preorder: ";
    // preorder(h);
    // cout<<endl<<"Inorder: ";
    // inorder(h);
    // cout<<endl<<"postorder: ";
    // postorder(h);

       cout<<endl;
//    levelTraversal(root);
   cout<<sumOfNodesAtKlevel(root,0)<<endl;


//              1
//         2               3
//      4     NULL    7        8 
//     5  6       NULL   9   NULL NULL
//   N  N N  N     
	return 0;
}
