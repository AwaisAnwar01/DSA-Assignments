#include <iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node *next;
    
    Node(){
        data = 0;
        priority = 0;
        next = NULL;
    }
    Node(int d,int p){
        data = d;
        priority = p;
    }
    
};
void insert(Node *n ,Node *&start, Node *&end,int &priority){
    if (start == NULL || priority < start->priority ){
       n->next = start;
       start = n;
       
    }
    else  
    {  
        Node *temp= start;
        while( temp->next != NULL && temp->next->priority <= priority )  
            temp=temp->next;  
        n->next = temp->next;  
       temp->next = n;  
    }
}  
int delete_node(Node *&start , Node *&end){
    Node * temp=start;
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
            cout << " (" << temp->data << ") " << " (" << temp->priority << ") ";
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
int Data = 0;
int Priority= 0;
cout<<"Enter the data of new node: "<<endl;
cin>>Data;
cout<<"Enter the priority of new node: "<<endl;
cin>>Priority;
n->data=Data;
n->priority=Priority;
insert(n, start, end,Priority);
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