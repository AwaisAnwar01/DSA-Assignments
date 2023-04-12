#include <iostream>
using namespace std;
struct Q
{
    int data;
    int priority;
};
void extension_func(Q *&queue,int &extension)
{extension=1;
    Q * old_q=new Q [5];
  
    old_q=queue;
    queue=new Q [7];

    for(int i=0;i<5 ;i++)
    {
        queue[i]=old_q[i];
    }

    for(int i=5;i<8;i++)
    {
        queue[i].data=0;
        queue[i].priority=0;
       
        
    }
        delete[] old_q;
}
void insert(int value, int priority, int &front, int &end, Q *&queue,int &counter,int &extension)
{
    if (front == 0 && end == 0)
    {
        queue[end].data = value;
        queue[end].priority = priority;
        end++;
        counter++;
    }

    else if (counter==5)
    { 
        extension_func(queue,extension);
        queue[end].data = value;
        queue[end].priority = priority;
        end++;
        counter++;
    }

    else if(counter==7)
    {
        cout<<"Queue is full."<<endl;

    }



    else if (end == 7 && front > 0)
    {
        int count = front;
        int j = 0;
        while (j != count)
        {
           for(int i=0;i<7;i++)
           {
            queue[i]=queue[i+1];
           }
            j++;
        }
        int end_val = 7 - front;
   
        for (int i = end_val; i < 7; i++)
        {
            queue[i].data = 0;
            queue[i].priority = 0;
        } int i = end_val - 1;
        while (i != -1)
        {
            if (priority > queue[i].priority)
            {  if (i==0)
                {
                queue[i + 1] = queue[i];
                queue[i ].data = value;
                queue[i].priority=priority;
                counter++;
                break;
                }
                else{
                queue[i + 1] = queue[i];
                }
                i--;
                end=end_val;
                end++;
                counter++;
                front=0;
            }
            else
            {
                queue[i + 1].data = value;
                queue[i + 1].priority = priority;
                end++;
                counter++;
                break;
            }
        }
    }

    else if (front != end)
    {
        int i = end - 1;
        while (i != -1)
        {
            if (priority > queue[i].priority)
            {  if (i==0)
                {
                queue[i + 1] = queue[i];
                queue[i ].data = value;
                queue[i].priority=priority;
                end++;
                counter++;
                break;
                }
                else{
                queue[i + 1] = queue[i];
                }
                i--;
            }
            else
            {
                queue[i + 1].data = value;
                queue[i + 1].priority = priority;
                end++;
                counter++;
                break;
            }
        }
        
    
    }
}


void dequeue(int &front, int &end, Q queue[5],int &counter)
   {
    if(front==5)
    { front=0;
    queue[front].data=0;
    queue[front].priority=0;
    front++;    
    counter--;
    }
   
    else if (front == 5 && end==5)
    {
        queue[front].data=0;
        queue[front].priority=0;
        
    }
   
    else if (front==5 && end>0)
    {
        front=0;
        queue[front].data=0;
        queue[front].priority=0;
        front++;
        counter--;
    }
    else if(front!=end)
    {
        queue[front].data=0;
        queue[front].priority=0;
        front++;
        counter--;
        
    }
}

void display(Q queue[5],int &extension)
{if (extension==0)
{


    for (int j = 0; j < 5; j++)
    {
        cout <<"( data: " <<queue[j].data<<"  " << "Priority: " << queue[j].priority<<"),";
        
    }
    cout<<endl;}
    else
    {
     for (int j = 0; j < 7; j++)
    {
        cout <<"( data: " <<queue[j].data<<"  " << "Priority: " << queue[j].priority<<"),";
        
    }
    cout<<endl;   
    }
    
}


int main()
{
    Q * queue;
    int counter=0;
    queue= new Q [5];
    int extension=0;
    int end = 0;
    int front = 0;
    for (int i = 0; i < 5; i++)
    {
        queue[i].data = 0;
        queue[i].priority = 0;
    }
   int option;
  

   do{
    
    cout<<"Enter 1 for insert: "<<endl;
    cout<<"Enter 2 for delete: "<<endl;
    cout<<"Enter 3 for display: "<<endl;
    cout<<"Enter 0 to exit the program: "<<endl;
    cout<<"Start is :"<<front<<endl;
    cout<<"End is :"<< end<<endl;
    cout<<"counter : "<<counter<<endl;

    cin>>option;
    switch(option)
    {
        case 1:
        int val,pr;
        cout<<"Enter the data: "<<endl;
        cin>>val;
        cout<<"Enter the priority: "<<endl;
        cin>>pr;
        insert(val,pr, front ,end, queue,counter,extension);
        break;
        case 2:
        dequeue(front,end,queue,counter);
        break;
        case 3:
        display(queue,extension);
        break;
    }
   }while (option!=0);
   
   
    return 0;
}
 