#include <bits/stdc++.h>
using namespace std;
 // A linked list node
class Node{
public:
    int data;
    Node* next;
};
//DELETE REVERSE ARE SELF WRITTEN
  void deleteNode(Node* &head,int val)
{    if(head==NULL||(head->data==val&&head->next==NULL))
     {head=NULL;
     return;
     }
     else if(head->data==val&&head->next!=NULL)
     {
         head=head->next;
         return;
     }
     Node* temp=head;
     while(temp->next!=NULL&&temp->next->data!=val)
         temp=temp->next;
     if(temp->next!=NULL)
     temp->next=temp->next->next;
}
void reverseNode(Node* &head)
{
    Node* prev=NULL;
    Node* current=head;
    Node*  nextt;
    while(current!=NULL)
    {   nextt=current->next;
        current->next=prev;
        prev=current;
        current=nextt;
    }
    head=prev;
}
Node* reverseNodeRecursion(Node* &head)
{  if(head==NULL||head->next==NULL)
    return head;
    Node* newhead=reverseNodeRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
Node* reverseKnoodes(Node* &head,int k)
{  
    Node* prev=NULL;
    Node* current=head;
    Node* nextt;
    Node*temp=head;
    int i=k;
    while(current!=NULL&&i!=0)
    {   nextt=current->next;
        current->next=prev;
        prev=current;
        current=nextt;
        i--;
    }
    if(current!=NULL&&k>0)
    temp->next=reverseKnoodes(current,k);
    return prev;
}

//cycle forms after n terms
bool detectCycle(Node* &head)
 { Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL) {
    slow=slow->next;
    fast=fast->next->next;
    if(fast==slow)
    return true;
    }
    return false;
}
void makeCycle(Node* &head,int pos)
{   Node* temp=head;
    Node* startNode;
    int count=1;
    while(temp->next!=NULL) {
        if(count=pos)
        startNode=temp;
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}
void removeCycle(Node* &head){ //FLOYD's ALGO

     Node* slow=head; 
     Node* fast=head;

    do{
    slow=slow->next;
    fast=fast->next->next;

    } while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next)
   {  slow=slow->next;
      fast=fast->next;
   }
    slow->next=NULL;
}
//append k nodes at begining
int length(Node* &head,Node* &last)
{ int l=0;
  Node* temp=head;
  while(temp!=NULL)
  {   last=temp;
      temp=temp->next;
   l++;
  }

  return l;

}
Node* appendLastKNodesAtBegining(Node* &head,int k)
{    if(head==NULL)
      return head;
    Node* temp=head;
    Node* last=NULL;// will store last node when length will be called
    int len=length(head,last);
    int c=1;
    while(c+k<len)
    {
        temp=temp->next;
        c++;
    }
    last->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}
//merge two sorted arrays
Node* MergeTwoSortedList(Node* &head1,Node* &head2)
{   if(head1==NULL)
       return head2;
       else if(head2==NULL)
             return head1;
    Node *head,*temp;
    if(head1->data<head2->data)
    {head=head1;temp=head1;head1=head1->next;}
    else
    {head=head2;temp=head2;head2=head2->next;}

    while(head1!=NULL&&head2!=NULL)
     {if(head1->data<head2->data)
     {   temp->next=head1;
         head1=head1->next;
     }
     else{
      temp->next=head2;
      head2=head2->next;
     }
     temp=temp->next;
     }
    if(head1!=NULL)
     temp->next=head1;
     else
     temp->next=head2;
return head;
}
//add even position nodes after odd position Nodes
void addEvenPosafterOddPos(Node* &head)
{   if(head==NULL||head->next==NULL)
    return;
    Node *odd=head,*evenHead=head->next,*even=head->next;
    while(odd->next!=NULL&&even->next!=NULL)
    { even=odd->next;
      odd->next=even->next;
      odd=odd->next;
      if(odd->next!=NULL)
      {even->next=odd->next;
       even=even->next;
      }
    }
    odd->next=evenHead;
    even->next=NULL; 
}
// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the
// list.
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
     
    // Start with the empty list
    Node* head = NULL;
   Node* b=NULL;
    // Add elements in linked list
 push(&head, 8);
    push(&head, 7);
     push(&head, 6);
    push(&head, 5);
 push(&head,4);
      push(&head,3);
       push(&head,2);
     // push(&head, 1);

    //   push(&b,7);
    //   push(&b,6);
    //   push(&b,5);
    //   push(&b,3);
 
    puts("Created Linked List: ");
    printList(head);
    // cout<<endl;
    // printList(b);
 
    // deleteNode(head, 2);
    //head=reverseNodeRecursion(head);
    //head=reverseKnoodes(head,5);
   
   //works except size =0,1,2
    // makeCycle(head,4);
    // cout<<detectCycle(head);
    // if(detectCycle(head))
    // removeCycle(head);

    //appendLastKNodesAtBegining(head,5);
  //  b=MergeTwoSortedList(head,b);
 addEvenPosafterOddPos(head);
     puts("\nLinked List after :");
    printList(head);
    //  printList(b);
     
    return 0;
}