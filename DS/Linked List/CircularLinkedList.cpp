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

    ~node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next= NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};
void insertnode(node* &tail,int element,int d)
{
    if(tail==NULL)//empty circular linked list
    {
        node* temp=new node(d);
        tail=temp;
        temp->next=temp;
    }
    else//non-empty circular linked list
    {
        node* curr=tail;//use cuurent to traverse till insertion point is found out
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        //found pos to insert node
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void printlist(node* &tail)
{
    node* temp=tail;//to save address of print start point
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);

    cout<<endl;

}
void deletenode(node* &tail,int value)
{
    if(tail==NULL)//empty list
    {
        cout<<"Nothing to delete"<<endl;
        return;
    }
    else
    {
        node* prev=tail;
        node* curr=prev->next; //curr ahead of prev
        
        while(curr->data!=value)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(prev==curr)//single node list
        {
            tail=NULL;
        }
        else if(tail==curr)//two or more nodes in list
        {
            tail=prev; //updating tail
        }
        curr->next=NULL;
        delete curr;
    }

}
int main()
{
    node* tail=NULL;
    insertnode(tail,10,3);
    insertnode(tail,3,5);
    printlist(tail);
    insertnode(tail,5,7);
    printlist(tail);
    insertnode(tail,7,9);
    printlist(tail);
    deletenode(tail,5);
    printlist(tail);
    return 0;

}