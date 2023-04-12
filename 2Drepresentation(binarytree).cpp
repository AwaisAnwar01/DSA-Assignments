#include<iostream>
//#include<conio.h>
#include<iomanip>
using namespace std;
struct b_bax
{
     
    int data;
    b_bax *left;
    b_bax *right;
    b_bax()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    b_bax(int data1)
    {
        data = data1;
    }
};
void printTree(int arr[7]) {
    cout<<setw(50)<<"("<<arr[0]<<")\n";
    cout<<setw(48)<<"/"<<setw(7)<<"\\\n";
    cout<<setw(46)<<"("<<arr[1]<<")"<<setw(6)<<"("<<arr[2]<<")"<<endl;
    cout<<setw(45)<<"/"<<setw(3)<<"\\"<<setw(6)<<"/"<<setw(3)<<"\\\n";
    cout<<setw(43)<<"("<<arr[3]<<")"<<setw(3)<<"("<<arr[4]<<")"<<setw(2)<<"("<<arr[5]<<")"<<setw(3)<<"("<<arr[6]<<")";
}
void printTree1(int new_arr[7]) {
    cout<<setw(50)<<"("<<new_arr[0]<<")\n";
    cout<<setw(48)<<"/"<<setw(7)<<"\\\n";
    cout<<setw(46)<<"("<<new_arr[1]<<")"<<setw(6)<<"("<<new_arr[4]<<")"<<endl;
    cout<<setw(45)<<"/"<<setw(3)<<"\\"<<setw(6)<<"/"<<setw(3)<<"\\\n";
    cout<<setw(43)<<"("<<new_arr[2]<<")"<<setw(3)<<"("<<new_arr[3]<<")"<<setw(2)<<"("<<new_arr[5]<<")"<<setw(3)<<"("<<new_arr[6]<<")";
}
// function to sort array
void bubbleSort(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < (7 - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
  //function to get binary serach tree from  sorted  array;
b_bax * convert_Array(int arr[],int start , int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
     b_bax* parent=new b_bax(arr[mid]);
     parent->left=convert_Array(arr,start,mid-1);
     parent->right=convert_Array(arr,mid + 1,end);
     return parent;
}
// function to print binary serach tree from  sorted  array
void show(b_bax * parent)
{
    if(parent!=NULL)
    {   cout<<parent->data<<" ";
        show(parent->left);
        show(parent->right);

    }
}

// function to get sorted  array from  binary serach tree 
void baba_convert(b_bax *parent, int A[])
{
    static int pos = 0;
    if(parent == NULL) return;
    A[pos++] = parent->data;
   baba_convert(parent->left, A);
    baba_convert(parent->right, A);

}

int main()
{int arr[7];
int new_arr[7];
cout<<"Enter the integers in any order :"<<endl;
for(int i=0;i<7;i++)
{
    cin>>arr[i];
}
cout<<"Unsorted Array : "<<endl;
for(int i=0;i<7;i++)
{
   cout<<arr[i]<<" ";
}cout<<endl;
bubbleSort(arr);
cout<<"Sorted  Array : "<<endl;
for(int i=0;i<7;i++)
{
   cout<<arr[i]<<" ";
}cout<<endl;
 cout << "binary serach tree from sorted  array : "<<endl;
 b_bax * parent=convert_Array(arr, 0 , 7);
show(parent);
cout<<endl;
baba_convert(parent,new_arr);
    cout << " sorted  array from  binary serach tree: "<<endl;
    for(int i = 0; i <7; i++){
        cout << new_arr[i] << " ";

}
cout << "Graphical representation of binary tree"<<endl;
printTree( arr);
cout<<endl;
cout << "Graphical representation of binary search tree"<<endl;
printTree1(new_arr);



    return 0;
}