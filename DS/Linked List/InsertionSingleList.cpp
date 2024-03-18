#include<iostream>
using namespace std;

class Node
{
    public: //data members
    int data;
    Node* next;
    //constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void InsertAtHead(Node* &head, int d)
{
    //create new node
    Node* temp= new Node(d);
    temp->next=head; //connect the nodes
    head=temp; //reset head pointer
}
void InsertAtTail(Node* &tail, int d)
{
    Node* temp= new Node(d);
    tail->next =temp;
    tail=tail->next; //tail=temp
}
void InsertAtMiddle(Node* &head, Node* &tail, int position,int d)
{
    //for first position
    if(position==1)
    {
        InsertAtHead(head,d);
        return;
    }
    Node* temp= head;
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
        InsertAtTail(tail,d);
        return;
    }
    //creating a node
    Node* nodetoinsert= new Node(d);
    nodetoinsert-> next= temp->next;
    temp->next= nodetoinsert;
}
void DeleteNode(int position,Node* &head,Node* &tail)
{
    //deleting first node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        
        if(curr->next==NULL)
        {
            tail=prev;
        }
        prev->next=curr->next;
        //delete curr node
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail= node1;
    print(head);
    cout<<head->data<<endl;
    cout<<head->next<<endl;
    InsertAtHead(head,12);
    InsertAtTail(tail,15);
    InsertAtMiddle(head,tail,5,20);
    InsertAtTail(tail,40);
    print(head);
    DeleteNode(3,head,tail);
    print(head);
    cout<<tail->data<<endl;
    return 0;
}