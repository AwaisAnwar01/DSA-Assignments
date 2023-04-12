#include <iostream>
#include <string>
using namespace std;
class Array{
    private:
    int counter;
    public:
    int arr[8];
    friend int binarySearch(Array &A, int left, int right, int x);
    friend int Partition(int arr[], int s, int e);
    friend void  Quick_sort(Array &A, int s, int e);
    friend int linearSearch(Array &A , int n);
    Array()
    {
        counter = -1;
        for (int i = 0; i < 8; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (counter == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (counter == 7)
            return true;
        else
            return false;
    }
     void Insertion(int val)
    {
        if (isFull())
        {
            cout << "Array is  full" << endl;
            return;
        }
        else if (isEmpty())
        {
          counter = 0;
          arr[counter] = val;
        }
        else
        {
           counter++;
           arr[counter] = val;
        }
    }
     int Delete()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Array is Empty" << endl;
            return x;
        }
        else if (counter == 7)
        {
            x = arr[counter];
            counter = -1;
            counter = -1;
            return x;
        }
        else
        {
            cout << "counter value: " << counter << endl;
            x = arr[counter];
            arr[counter] = 0;
            counter++;
            return x;
        }
    }
    int count()
    {
        return (counter + 1);
    }
    void display_array()
    {
        cout << "All values in the Queue are - " << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << arr[i] << "  ";
        }
    }
    void Array_menu(Array &A1)
    {

        int value, option;

        do
        {
            cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
            cout << "1. insertion()" << endl;
            cout << "2. Delete()" << endl;
            cout << "3. isEmpty()" << endl;
            cout << "4. isFull()" << endl;
            cout << "5. count()" << endl;
            cout << "6. display()" << endl;
            cout << "7. Clear Screen" << endl;
            cout<<"0 for back "<<endl;
                 

            cin >> option;

            switch (option)
            {
            case 0:
                break;
            case 1:
                cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
                cin >> value;
                A1.Insertion(value);
                break;
            case 2:
                cout << "Dequeue Operation \nDequeued Value : " << A1.Delete() << endl;
                break;
            case 3:
                if (A1.isEmpty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            case 4:
                if (A1.isFull())
                    cout << "Queue is Full" << endl;
                else
                    cout << "Queue is not Full" << endl;
                break;
            case 5:
                cout << "Count Operation \nCount of items in Queue : " << A1.count() << endl;
                break;
            case 6:
                cout << "Display Function Called - " << endl;
                A1.display_array();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
            }

        } while (option != 0);
    }
};



class Queue
{
private:
    int front;
    int rear;
   

public:
int arr[8];
    friend int binarySearch(Queue &q, int left, int right, int x);
    friend int Partition(int arr[], int s, int e);
    friend void  Quick_sort(int arr[], int s, int e);
    friend int linearSearch(Queue &q, int n);
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 8; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == 7)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return x;
        }
        else if (rear == front)
        {
            x = arr[rear];
            rear = -1;
            front = -1;
            return x;
        }
        else
        {
            cout << "front value: " << front << endl;
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }

    int count()
    {
        return (rear - front + 1);
    }

    void display()
    {
        cout << "All values in the Queue are - " << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << arr[i] << "  ";
        }
    }

    void menu_queue(Queue &q1)
    {

        int value, option;

        do
        {
            cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
            cout << "1. Enqueue()" << endl;
            cout << "2. Dequeue()" << endl;
            cout << "3. isEmpty()" << endl;
            cout << "4. isFull()" << endl;
            cout << "5. count()" << endl;
            cout << "6. display()" << endl;
            cout << "7. Clear Screen" << endl;
            cout<<"0 for back "<<endl;
                 

            cin >> option;

            switch (option)
            {
            case 0:
                break;
            case 1:
                cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
                break;
            case 3:
                if (q1.isEmpty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            case 4:
                if (q1.isFull())
                    cout << "Queue is Full" << endl;
                else
                    cout << "Queue is not Full" << endl;
                break;
            case 5:
                cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
                break;
            case 6:
                cout << "Display Function Called - " << endl;
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
            }

        } while (option != 0);
    }
};


 
int Partition(Array &A, int s, int e)
{
 int pivot = A.arr[e];
 int pIndex = s;
 
 for(int i = s;i<e;i++)
 {
 if(A.arr[i]<pivot)
 {
 int temp = A.arr[i];
 A.arr[i] = A.arr[pIndex];
 A.arr[pIndex] = temp;
 pIndex++;
 }
 }
 
 int temp = A.arr[e];
 A.arr[e] = A.arr[pIndex];
 A.arr[pIndex] = temp;
 
 return pIndex;
}
 
void QuickSort(Array &A, int s, int e)
{
 if(s<e)
 {
 int p = Partition(A,s, e);
 QuickSort(A, s, (p-1)); 
 QuickSort(A, (p+1), e);  
 }
}


int Partition1(Queue &q, int s, int e)
{
 int pivot = q.arr[e];
 int pIndex = s;
 
 for(int i = s;i<e;i++)
 {
 if(q.arr[i]<pivot)
 {
 int temp = q.arr[i];
 q.arr[i] = q.arr[pIndex];
 q.arr[pIndex] = temp;
 pIndex++;
 }
 }
 
 int temp = q.arr[e];
 q.arr[e] = q.arr[pIndex];
 q.arr[pIndex] = temp;
 
 return pIndex;
}
 
void QuickSort(Queue &q, int s, int e)
{
 if(s<e)
 {
 int p = Partition1(q,s, e);
 QuickSort(q, s, (p-1));  
 QuickSort(q, (p+1), e);  
 }
}

int binarySearch(Array &A, int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (A.arr[mid] == x)
        {
            return mid;
        }
        else if (A.arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}




int binarySearch(Queue &q, int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (q.arr[mid] == x)
        {
            return mid;
        }
        else if (q.arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}


int linearSearch(Array &A, int n)
{
    int temp = -1;

    for (int i = 0; i < 8; i++)
    {
        if (A.arr[i] == n)
        {

            temp = i;
            return temp;
            break;
        }
    }

    if (temp == -1)
    {
        return temp;
    }
}

int linearSearch(Queue &q, int n)
{
    int temp = -1;

    for (int i = 0; i < 8; i++)
    {
        if (q.arr[i] == n)
        {

            temp = i;
            return temp;
            break;
        }
    }

    if (temp == -1)
    {
        return temp;
    }
}
int main()
{
    Array a;
    Queue q;
    int option, value;
    do
    {
        cout << "Enter the data type of your choice: " << endl;
        cout << "1 for array1" << endl;
        cout << "2 for queue" << endl;
        cout << "0 to back." << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            a.Array_menu(a);
                int opt;
                do
                {
                    cout << "1 for Quick sort " << endl;
                    cout << "0 for back " << endl;
                    cin >> opt;
                    switch (opt)
                    {
                        int num;
                    case 0:
                        break;
                    case 1:
                    {
                     cout<<"performing quick sort"<<endl;
                      QuickSort(a, 0, 7);
                      for(int i =0 ;i<7;i++){
                          cout<<a.arr[i]<<" " ;
                    }
                      cout<<endl;
                        int opt1;
                        do
                        {
                            cout << "1 for binary search " << endl;
                            cout << "0 for back " << endl;
                            cin >> opt1;
                            switch (opt1)
                            {
                                int num;
                            case 0:
                                break;
                            case 1:
                            {

                                cout << "Enter the num to be searched: " << endl;
                                cin >> num;
                                int output = binarySearch(a, 0, 7, num);
                                if (output == -1)
                                {
                                    cout << "NO value Found!" << endl;
                                }
                                else
                                {
                                    cout << "Value found at  index: " << output << endl;
                                }
                                break;
                            }
                            break;
                           
                            }

                        } while (opt != 0);}
                    break;
                    }

                } while (opt != 0);
        }
                break;
        case 2:
        {
            q.menu_queue(q);
                int opt;
                do
                {
                    cout << "1 for Quick sort " << endl;
                    cout << "0 for back " << endl;
                    cin >> opt;
                    switch (opt)
                    {
                        int num;
                    case 0:
                        break;
                    case 1:
                    {
                     cout<<"performing quick sort"<<endl;
                      QuickSort(a, 0, 7);
                      for(int i =0 ;i<7;i++){
                          cout<<q.arr[i]<<" " ;
                    }
                      cout<<endl;
                        int opt1;
                        do
                        {
                            cout << "1 for binary search " << endl;
                            cout << "0 for back " << endl;
                            cin >> opt1;
                            switch (opt1)
                            {
                                int num;
                            case 0:
                                break;
                            case 1:
                            {

                                cout << "Enter the num to be searched: " << endl;
                                cin >> num;
                                int output = binarySearch(a, 0, 7, num);
                                if (output == -1)
                                {
                                    cout << "NO value Found!" << endl;
                                }
                                else
                                {
                                    cout << "Value found at  index: " << output << endl;
                                }
                               
                            }
                            
                            break;
                           
                            }

                        } while (opt != 0);}
                    break;
                    }

                } while (opt != 0);
        }
                break;
                break;
        case 0:
            break;
    }

    }while (option != 0);
    return 0;
}
                
            
            