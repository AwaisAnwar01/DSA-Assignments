#include <iostream>
using namespace std;

void insert(int value, int &start, int &end, int queue[5])
{
    int count;
    count = start;
   if (end==5 && start>0)
    {
        int j = 0;
        while (j != count)
        {

            for (int i = 0; i < 5; i++)
            {
                queue[i] = queue[i + 1];
            }

            j++;
        }
        int end_val;
        end_val=5-start;
        end=end_val;
         for (int i = end_val; i < 5; i++)
         {
              queue[i] = 0;
        }
        
        queue[end]=value;
        end++;
        start=0;}
        else if(start==0 && end==0)
        {
            queue[end]=value;
            end++;
        }

        else if(end==5 && start==0)
        {
            cout<<"queue is full"<<endl;
        }
    
        
    else if(end!=start)
    {
        queue[end]=value;
        end++;
    }
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
{   for(int i=0;i<5;i++)
    cout<<queue[i]<<" ";
    cout<<endl;

}
int main()
{
    int start = 0;
    int end = 0;
    int option;
    int queue[5];
    for (int i = 0; i < 5; i++)
    {
        queue[i] = 0;
    }
    do
    {
        cout << "Press 1 for enqueue :" << endl;
        cout << "Press 2 for dequeue: " << endl;
        cout << "Press 3 for display: " << endl;
        cin >> option;
        switch (option)
        {

        case 1:
            int val;
            cout<<"insert value"<<endl;
            cin >> val;
            insert(val, start, end, queue);
            break;
        case 2:
            dequeue(start, end, queue);
            break;
        case 3:
            display(queue);
            break;
        case 0:
            break;
        }
    } while (option != 0);

    return 0;
}
