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
void insert_node(Node* n, Node *&top)
{
    if (top == NULL)
    {
        top = n;
        cout << "Node is appended in the Stack. " << endl;
    }
    else{
    n->next = top;
    top = n;
    cout << "node is appended in the stack. " << endl;
}}

int delete_node(Node *&top)

{
    if (top == NULL)
    {
        cout << "Stack is empty! " << endl;
   return -1; }
    else
    {Node * temp=top;
        top = top->next;
    return temp->data; }
}
void Display_stack(Node *&top)

{
    if (top == NULL)
    {
        cout << " stack is Empty! " << endl;
    }
    else

    {
        Node *temp;
        temp = top;
        while (temp != NULL)
        {
            cout << " (" << temp->data << ") ";
            temp = temp->next;
        }
    cout<<endl;}
}

int main()
{
Node *Top=NULL;
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
insert_node(n , Top);
break;
}
case 2:
value=delete_node(Top);
if(value!=-1)
{
    cout<<"The value deleted is: "<<value<<endl<<endl;

}
break;
case 3:
Display_stack(Top);
break;
}

}while(option!=0);
    return 0;
}