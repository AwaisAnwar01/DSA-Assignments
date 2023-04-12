#include <iostream>
using namespace std;

void enqueue(int val,int&start,int &end,int queue[]){
    if (end == 0 && start == 0){
        queue[end] = val;
        end++;
    }
    else if(start == 5 && end == 5){
        start = 0;
        end = 0;
        queue[end] = val;
        end++;
    }
    else if(start==0 && end==5)
    {
        cout<<"queue is full "<<endl;
    }
    else if(end==5 && start >0)
        {  end=0;
        queue[end]=val;
            end++;
        }
    else if( start!=end) {
        end = (end ) % 5;
        queue[end] = val;
    end++;}
}

int dequeue(int &start, int &end, int queue[5])
{
    int x = 0;
    if (start == 0)
    {
        x = queue[start];

        queue[start] = 0;
        start++;
        return x;
    }
    else if (start == 5 && end==5)
    {
        start = 0;
        end = 0;
        return 1;
    }
   
    else if (start==5 && end>0)
    {
        start=0;
        queue[start]=0;
        start++;
    }
    else if(start!=end)
    {
        x = queue[start];
        queue[start] = 0;
        start++;
        return x;
    }
}
void display(int queue[5])
    {
        for (int i=0;i<5;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
   
int main()
{int front=0;    
int end=0;
int option;
int queue[5];
for(int i=0;i<5;i++)
{
    queue[i]=0;
}
do{
    cout<<"Press 1 for enqueue :"<<endl;
    cout<<"Press 2 fro dequeue: "<<endl;
    cout<<"Press 3 for display: "<<endl;
    cin>>option;
    switch (option)
    {
   
    case 1:
    int val;
  
    cout<<"Insert value:"<<endl;
    cin>>val;
    enqueue(val,front,end,queue);
    break;
    case 2:
    dequeue(front,end,queue);
    break;
    case 3:
   display(queue);
   break;
   case 0:
   break;

    }
    cout<<"value of end is : "<<end<<endl;
    cout<<"Vale of front is : "<<front<<endl;



}
while (option!=0);


    return 0;
}