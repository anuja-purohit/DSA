#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void InsertAtHead(node* &head,node* tail, int d)
{
    if(head==NULL)
    {
        node* temp= new node(d);
        head=temp;
        tail=temp;
    }
    else
    {
        //create new node
        node* temp= new node(d);
        temp->next=head; //connect the nodes
        head=temp; //reset head pointer
    }
    
}
void InsertAtTail(node* &head,node* &tail, int d)
{
    if(tail==NULL)
    {
        node* temp=new node(d);
        tail=temp;
        head=temp;
    }
    else{
        node* temp= new node(d);
        tail->next =temp;
        tail=tail->next; //tail=temp

    }
    
}
void InsertAtMiddle(node* &head, node* &tail, int position,int d)
{
    //for first position
    if(position==1)
    {
        InsertAtHead(head,tail,d);
        return;
    }
    node* temp= head;
    int cnt=1;
    //going to nth position excluding the first and last position
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    //for last position
    if(temp->next==NULL)
    {
        InsertAtTail(head,tail,d);
        return;
    }
    //creating a node
    node* nodetoinsert= new node(d);
    nodetoinsert-> next= temp->next;
    temp->next= nodetoinsert;
}
node* reverselinkedlist(node* &head)
{
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        node* prev=NULL;
        node* curr=head;
        node* forward=head;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
}
void print(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail= node1;
    InsertAtHead(head,tail,12);
    InsertAtTail(head,tail,15);
    InsertAtMiddle(head,tail,4,20);
    InsertAtTail(head,tail,40);
    print(head);
    head=reverselinkedlist(head);
    print(head);

    return 0;
}