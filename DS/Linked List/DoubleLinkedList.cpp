#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;

    node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data"<<val<<endl;
    }

};
void printlist(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int lengthlist(node* &head)
{
    int len=0;
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        len++;
        temp=temp->next;
    }
    return len;
}
void insertathead(node* &head,node* &tail, int d)
{
    if(head==NULL)
    {
        node* temp= new node(d);
        head=temp;
        tail=temp;
    }
    else
    {
        node* temp= new node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;

    }
}
void insertatend(node* &head,node*& tail, int d)
{
    if(tail==NULL)
    {
        node* temp=new node(d);
        tail=temp;
        head=temp;
    }
    else
    {
        node* temp= new node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    
}
void insertatanypos(node* &head, node* &tail,int pos,int d)
{
    if(pos==1)
    {
        insertathead(head,tail,d);
        return;
    }
    int cnt=1;
    node* temp=head;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertatend(head,tail,d);
        return;
    }
    node* nodetoinsert= new node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;

}
void  deletenode(node* &head,node* &tail, int pos)
{
    if(pos==1)
    {
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        int cnt=1;
        node* curr=head;
        node* prev=NULL;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL)
        {
            tail=prev;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    node* head=NULL;
    node* tail=NULL;
    insertathead(head,tail,5);
    insertathead(head,tail,10);
    printlist(head);
    insertatend(head,tail,0);
    printlist(head);
    insertatanypos(head,tail,2,20);
    printlist(head);
    deletenode(head,tail,4);
    printlist(head);
    insertatend(head,tail,100);
    printlist(head);
    return 0;
}