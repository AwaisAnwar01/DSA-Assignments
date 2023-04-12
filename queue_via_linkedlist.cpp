#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node()
    {
        next = NULL;
        data = 0;
    }
    Node(int data1)
    {
        data = data1;
    }
};
void insert_node(Node* n, Node *&start, Node *&end)
{     

if(start==NULL)
{
    start=n;
    end=n;
}
else{
    end->next=n;
    end=n;
}
    
}

int delete_node(Node *&start , Node *&end)

{Node * temp=start;
    if (start == NULL)
    {
        cout << "Queue is empty! " << endl;
   return -1; }
    else if(start->next==NULL)
    {
        start=NULL;
        end=NULL;
    
    }
    else{
        start = start->next; } 
         return temp->data;
}
void Display_Queue(Node *&start)

{
    if (start == NULL)
    {
        cout << " Queue is Empty! " << endl;
    }
    else

    {
        Node *temp;
        temp = start;
        while (temp != NULL)
        {
            cout << " (" << temp->data << ") ";
            temp = temp->next;
        }
    cout<<endl;}
}

int main()
{
Node *start=NULL;

Node *end=NULL;

int option;
int value;

do{

cout<<"Enter the operation you want to perform : "<<endl;
cout<<"1. for insertion: "<<endl;
cout<<"2. for dicarding: "<<endl; 
cout<<"3. for display: "<<endl;
cout<<"Press 0 to exit. "<<endl;
cin>>option;

switch (option)
{
case 1:
{Node * n=new Node;
int Data;
cout<<"Enter the data of new node: "<<endl;
cin>>Data;
n->data=Data;
insert_node(n, start, end);
break;
}
case 2:
value=delete_node(start,end);
if(value!=-1)
{
    cout<<"The value deleted is: "<<value<<endl<<endl;

}
break;
case 3:
Display_Queue(start);
break;
}

}while(option!=0);
    return 0;
}