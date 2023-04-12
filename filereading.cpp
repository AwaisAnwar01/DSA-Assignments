#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class node
{
    public:
    string name;
    string numbers;
    node*next;
    node*previous;
    node()
    {
        next=NULL;
        previous=NULL;
       
    }
  node(string n,string d)
  {   next=NULL;
  previous=NULL;
      name=n;
      numbers=d;
  }
};
class list
{
  public:
  node * start;
  node*end;
  list()
  {
      start=NULL;
      end=NULL;
     
  }
  void insert(string Name, string Numbers)
  {
      node* n=new node(Name,Numbers);
      if(start==NULL)
      {
          start=n;
          end=n;
         
      }
      else{
      node*temp =start;
      while(temp->next!=NULL)
      {
          temp=temp->next;
         
      }
      temp->next=n;
      end=n;
  }}
  void display()
  {
      node*temp=start;
      while(temp->next!=NULL)
      {cout<< " Name is "<<temp->name<<" numbers are "<<temp->numbers<<endl;
     
          temp=temp->next;
      }
     
  }
};
int main()

{
    int count=0;list l1;

    string name;
string numbers;
ifstream file("data.txt");

while(!file.eof())
{if (count==0)

{
    string temp;
    getline(file,temp);
    count=1;
}
else{
   getline(file,name,',');
   getline(file,numbers);
   l1.insert(name, numbers);
   
 }}
 l1.display();
 
 
return 0;
}