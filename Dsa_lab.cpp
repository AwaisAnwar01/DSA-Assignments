#include<iostream>
#include<string>
using namespace std;
class Stack {
  private:
    int top;
  int arr[5];
  public:
    Stack() {
      top = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }
  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == 4)
      return true;
    else
      return false;
  }
  void push(int val) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else {
      top++; // 1
      arr[top] = val;
    }
  }
  int pop() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
    }
  }
  int count() {
    return (top + 1);
  }
  int peek(int pos) {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
      return arr[pos];
    }
  }
  void change(int pos, int val) {
    arr[pos] = val;
    cout << "value changed at location " << pos << endl;
  }
  void display() {
    cout << "All values in the Stack are " << endl;
    for (int i = 4; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  }
void menu(){
  int option, postion, value;

  do {
    cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. peek()" << endl;
    cout << "6. count()" << endl;
    cout << "7. change()" << endl;
    cout << "8. display()" << endl;
    cout << "9. Clear Screen" << endl << endl;

    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enter an item to push in the stack" << endl;
      cin >> value;
      push(value);
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << pop() << endl;
      break;
    case 3:
      if (isEmpty())
        cout << "Stack is Empty" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
      if (isFull())
        cout << "Stack is Full" << endl;
      else
        cout << "Stack is not Full" << endl;
      break;
    case 5:
      cout << "Enter position of item you want to peek: " << endl;
      cin >> postion;
      cout << "Peek Function Called - Value at position " << postion << " is " << peek(postion) << endl;
      break;
    case 6:
      cout << "Count Function Called - Number of Items in the Stack are: " << count() << endl;
      break;
    case 7:
      cout << "Change Function Called - " << endl;
      cout << "Enter position of item you want to change : ";
      cin >> postion;
      cout << endl;
      cout << "Enter value of item you want to change : ";
      cin >> value;
      change(postion, value);
      break;
    case 8:
      cout << "Display Function Called - " << endl;
      display();
      break;
    case 9:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
  } while (option != 0);
 
}
};
class CircularQueue {
  private:
    int front;
  int rear;
  int arr[5];
  int itemCount;
  public:
    CircularQueue() {
      itemCount = 0;
      front = -1;
      rear = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }
  bool isEmpty() {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if ((rear + 1) % 5 == front)
      return true;
    else
      return false;
  }
  void enqueue(int val) {
    if (isFull()) {
      cout << "Queue full" << endl;
      return;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
      arr[rear] = val;
    } else {
      rear = (rear + 1) % 5;
      arr[rear] = val;
    }
    itemCount++;
  }
  int dequeue() {
    int x = 0;
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return x;
    } else if (rear == front) {
      x = arr[rear];
      rear = -1;
      front = -1;
      itemCount--;
      return x;
    } else {
      cout << "front value: " << front << endl;
      x = arr[front];
      arr[front] = 0;
      front = (front + 1) % 5;
      itemCount--;
      return x;
    }
  }
  int count() {
    return (itemCount);
  }
  void display() {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 5; i++) {
      cout << arr[i] << "  ";
    }
  }
  void queue_menu(){
  int value, option;
  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;
    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
      cin >> value;
      enqueue(value);
      break;
    case 2:
      cout << "Dequeue Operation \nDequeued Value : " << dequeue() << endl;
      break;
    case 3:
      if (isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << count() << endl;
      break;
    case 6:
      cout << "Display Function Called - " << endl;
      display();
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
// singly linked list
class Node {
  public:
    int key;
  int data;
  Node * next;
  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};
class SinglyLinkedList {
  public:
    Node * head;
  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(Node * n) {
    head = n;
  }
  // 1. CHeck if node exists using key value
  Node * nodeExists(int k) {
    Node * temp = NULL;
    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;
    }
    return temp;
  }
  // 2. Append a node to the list
  void appendNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended" << endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "Node Appended" << endl;
      }
    }
  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
      n -> next = head;
      head = n;
      cout << "Node Prepended" << endl;
    }
  }
  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {
      if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
      } else {
        n -> next = ptr -> next;
        ptr -> next = n;
        cout << "Node Inserted" << endl;
      }
    }
  }
  // 5. Delete node by unique key
  void deleteNodeByKey(int k) {
    if (head == NULL) {
      cout << "Singly Linked List already Empty. Cant delete" << endl;
    } else if (head != NULL) {
      if (head -> key == k) {
        head = head -> next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        } else {
          cout << "Node Doesn't exist with key value : " << k << endl;
        }
      }
    }
  }
  // 6th update node
  void updateNodeByKey(int k, int d) {
    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }
  }
  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }
  }
  void menu_l1(){
      int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      appendNode(n1);
      break;
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      prependNode(n1);
     break;
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      insertNodeAfter(k1, n1);
      break;
    case 4:
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      deleteNodeByKey(k1);
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      updateNodeByKey(key1, data1);
      break;
    case 6:
      printList();
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
  //doubly linked list
class Node_2 {
  public:
    int key;
  int data;
  Node_2 * next;
  Node_2 * previous;
  Node_2() {
    key = 0;
    data = 0;
    next = NULL;
    previous = NULL;
  }
  Node_2(int k, int d) {
    key = k;
    data = d;
  }
};
class DoublyLinkedList {
  public:
    Node_2 * head;
    Node_2 * previous;
  DoublyLinkedList() {
    head = NULL;
    previous = NULL;
  }
  DoublyLinkedList(Node_2 * n) {
    head = n;
  }
  // 1. CHeck if Node_2 exists using key value
  Node_2 * Node_2Exists(int k) {
    Node_2 * temp = NULL;
    Node_2 * ptr = head;
    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;
    }
    return temp;
  }
  // 2. Append a Node_2 to the list
  void appendNode_2(Node_2 * n) {
    if (Node_2Exists(n -> key) != NULL) {
      cout << "Node_2 Already exists with key value : " << n -> key << ". Append another Node_2 with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node_2 Appended as Head Node_2" << endl;
      } else {
        Node_2 * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        n -> previous = ptr;
        cout << "Node_2 Appended" << endl;
      }
    }
  }
  // 3. Prepend Node_2 - Attach a Node_2 at the start
  void prependNode_2(Node_2 * n) {
    if (Node_2Exists(n -> key) != NULL) {
      cout << "Node_2 Already exists with key value : " << n -> key << ". Append another Node_2 with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node_2 Prepended as Head Node_2" << endl;
      } else {
        head -> previous = n;
        n -> next = head;
        head = n;
        cout << "Node_2 Prepended" << endl;
      }
    }
  }
  // 4. Insert a Node_2 after a particular Node_2 in the list
  void insertNode_2After(int k, Node_2 * n) {
    Node_2 * ptr = Node_2Exists(k);
    if (ptr == NULL) {
      cout << "No Node_2 exists with key value: " << k << endl;
    } else {
      if (Node_2Exists(n -> key) != NULL) {
        cout << "Node_2 Already exists with key value : " << n -> key << ". Append another Node_2 with different Key value" << endl;
      } else {
        Node_2 * nextNode_2 = ptr -> next;
        // inserting at the end
        if (nextNode_2 == NULL) {
          ptr -> next = n;
          n -> previous = ptr;
          cout << "Node_2 Inserted at the END" << endl;
        }
        //inserting in between
        else {
          n -> next = nextNode_2;
          nextNode_2 -> previous = n;
          n -> previous = ptr;
          ptr -> next = n;
          cout << "Node_2 Inserted in Between" << endl;
        }
      }
    }
  }
  // 5. Delete Node_2 by unique key. Basically De-Link not delete
  void deleteNode_2ByKey(int k) {
    Node_2 * ptr = Node_2Exists(k);
    if (ptr == NULL) {
      cout << "No Node_2 exists with key value: " << k << endl;
    } else {
      if (head -> key == k) {
        head = head -> next;
        cout << "Node_2 UNLINKED with keys value : " << k << endl;
      } else {
        Node_2 * nextNode_2 = ptr -> next;
        Node_2 * prevNode_2 = ptr -> previous;
        // deleting at the end
        if (nextNode_2 == NULL) {
          prevNode_2 -> next = NULL;
          cout << "Node_2 Deleted at the END" << endl;
        }
        //deleting in between
        else {
          prevNode_2 -> next = nextNode_2;
          nextNode_2 -> previous = prevNode_2;
          cout << "Node_2 Deleted in Between" << endl;
        }
      }
    }
  }
  // 6th update Node_2
  void updateNode_2ByKey(int k, int d) {
    Node_2 * ptr = Node_2Exists(k);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node_2 Data Updated Successfully" << endl;
    } else {
      cout << "Node_2 Doesn't exist with key value : " << k << endl;
    }
  }
  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Node_2s in Doubly Linked List";
    } else {
      cout << endl << "Doubly Linked List Values : ";
      Node_2 * temp = head;
      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") <--> ";
        temp = temp -> next;
      }
    }
  }
  void menu_l2(){
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode_2()" << endl;
    cout << "2. prependNode_2()" << endl;
    cout << "3. insertNode_2After()" << endl;
    cout << "4. deleteNode_2ByKey()" << endl;
    cout << "5. updateNode_2ByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node_2 * n1 = new Node_2();
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node_2 Operation \nEnter key & data of the Node_2 to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      appendNode_2(n1);
      break;
    case 2:
      cout << "Prepend Node_2 Operation \nEnter key & data of the Node_2 to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      prependNode_2(n1);
      break;
    case 3:
      cout << "Insert Node_2 After Operation \nEnter key of existing Node_2 after which you want to Insert this New Node_2: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node_2 first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      insertNode_2After(k1, n1);
      break;
    case 4:
      cout << "Delete Node_2 By Key Operation - \nEnter key of the Node_2 to be deleted: " << endl;
      cin >> k1;
     deleteNode_2ByKey(k1);
      break;
    case 5:
      cout << "Update Node_2 By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      updateNode_2ByKey(key1, data1);
      break;
    case 6:
     printList();
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
// circular linked list
class Node_3 {
  public:
    int key;
  int data;
  Node_3 * next;
  Node_3() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node_3(int k, int d) {
    key = k;
    data = d;
  }
};
class CircularLinkedList {
  public:
    Node_3 * head;
  CircularLinkedList() {
    head = NULL;
  }
  // 1. CHeck if Node_3 exists using key value
  Node_3 * Node_3Exists(int k) {
    Node_3 * temp = NULL;
    Node_3 * ptr = head;
    if (ptr == NULL) {
      return temp;
    } else {
      do {
        if (ptr -> key == k) {
          temp = ptr;
        }
        ptr = ptr -> next;
      } while (ptr != head);
      return temp;
    }
  }
  // 2. Append a Node_3 to the list
  void appendNode_3(Node_3 * new_Node_3) {
    if (Node_3Exists(new_Node_3 -> key) != NULL) {
      cout << "Node_3 Already exists with key value : " <<
        new_Node_3 -> key <<
        ". Append another Node_3 with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_Node_3;
        new_Node_3 -> next = head;
        cout << "Node_3 Appended at first Head position" << endl;
      } else {
        Node_3 * ptr = head;
        while (ptr -> next != head) {
          ptr = ptr -> next;
        }
        ptr -> next = new_Node_3;
        new_Node_3 -> next = head;
        cout << "Node_3 Appended" << endl;
      }
    }
  }
  // 3. Prepend Node_3 - Attach a Node_3 at the start
  void prependNode_3(Node_3 * new_Node_3) {
    if (Node_3Exists(new_Node_3 -> key) != NULL) {
      cout << "Node_3 Already exists with key value : " <<
        new_Node_3 -> key <<
        ". Append another Node_3 with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_Node_3;
        new_Node_3 -> next = head;
        cout << "Node_3 Prepended at first Head position" << endl;
      } else {
        Node_3 * ptr = head;
        while (ptr -> next != head) {
          ptr = ptr -> next;
        }
        ptr -> next = new_Node_3;
        new_Node_3 -> next = head;
        head = new_Node_3;
        cout << "Node_3 Prepended" << endl;
      }
    }
  }
  // 4. Insert a Node_3 after a particular Node_3 in the list
  void insertNode_3After(int k, Node_3 * new_Node_3) {
    Node_3 * ptr = Node_3Exists(k);
    if (ptr == NULL) {
      cout << "No Node_3 exists with key value OF: " << k << endl;
    } else {
      if (Node_3Exists(new_Node_3 -> key) != NULL) {
        cout << "Node_3 Already exists with key value : " <<
          new_Node_3 -> key <<
          ". Append another Node_3 with different Key value" <<
          endl;
      } else {
        if (ptr -> next == head) {
          new_Node_3 -> next = head;
          ptr -> next = new_Node_3;
          cout << "Node_3 Inserted at the End" << endl;
        } else {
          new_Node_3 -> next = ptr -> next;
          ptr -> next = new_Node_3;
          cout << "Node_3 Inserted in between" << endl;
        }
      }
    }
  }
  // 5. Delete Node_3 by unique key
  void deleteNode_3ByKey(int k) {
    Node_3 * ptr = Node_3Exists(k);
    if (ptr == NULL) {
      cout << "No Node_3 exists with key value OF : " << k <<
        endl;
    } else {
      if (ptr == head) {
        if (head -> next == NULL) {
          head = NULL;
          cout << "Head Node_3 Unlinked... List Empty";
        } else {
          Node_3 * ptr1 = head;
          while (ptr1 -> next != head) {
            ptr1 = ptr1 -> next;
          }
          ptr1 -> next = head -> next;
          head = head -> next;
          cout << "Node_3 UNLINKED with keys value : " << k << endl;
        }
      } else {
        Node_3 * temp = NULL;
        Node_3 * prevptr = head;
        Node_3 * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        prevptr -> next = temp -> next;
        cout << "Node_3 UNLINKED with keys value : " << k << endl;
      }
    }
  }
  // 6th update Node_3
  void updateNode_3ByKey(int k, int new_data) {
    Node_3 * ptr = Node_3Exists(k);
    if (ptr != NULL) {
      ptr -> data = new_data;
      cout << "Node_3 Data Updated Successfully" << endl;
    } else {
      cout << "Node_3 Doesn't exist with key value : " << k << endl;
    }
  }
  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Node_3s in Circular Linked List";
    } else {
      cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;
      Node_3 * temp = head;
      do {
        cout << "(" << temp -> key << "," << temp -> data << "," << temp -> next << ") --> ";
        temp = temp -> next;
      } while (temp != head);
    }
  }
  void menu_l3(){
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode_3()" << endl;
    cout << "2. prependNode_3()" << endl;
    cout << "3. insertNode_3After()" << endl;
    cout << "4. deleteNode_3ByKey()" << endl;
    cout << "5. updateNode_3ByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
    cin >> option;
    Node_3 * n1 = new Node_3();
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node_3 Operation \nEnter key & data of the Node_3 to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      appendNode_3(n1);
      break;
    case 2:
      cout << "Prepend Node_3 Operation \nEnter key & data of the Node_3 to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      prependNode_3(n1);
      break;
    case 3:
      cout << "Insert Node_3 After Operation \nEnter key of existing Node_3 after which you want to Insert this New Node_3: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node_3 first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      insertNode_3After(k1, n1);
      break;
    case 4:
      cout << "Delete Node_3 By Key Operation - \nEnter key of the Node_3 to be deleted: " << endl;
      cin >> k1;
      deleteNode_3ByKey(k1);
      break;
    case 5:
      cout << "Update Node_3 By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      updateNode_3ByKey(key1, data1);
      break;
    case 6:
    printList();
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
int main(){
    Stack s;
    CircularQueue q;
    SinglyLinkedList l1;
    DoublyLinkedList l2;
    CircularLinkedList l3;
    int option;
    do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. STACK" << endl;
    cout << "2. QUEUE" << endl;
    cout << "3. LINKED LIST " << endl;

    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "stack called" <<endl;
      s.menu();
      break;
    case 2:
      cout << "queue called "<< endl;
      q.queue_menu();
      break;
    case 3:
      cout << "LINKED LIST called"<< endl;
      int option_2;
      cout<<"Enter the list of your choice: "<<endl;
 
     
   
    do{
        cout<<"Enter 1 for Singly Linked List: "<<endl;
        cout<<"Enter 2 for doubly linked list: "<<endl;
        cout<<"Enter 3 for circular Linked list: "<<endl;
        cout<<"Enter 0 to exit: "<<endl;
        cin>>option_2;
        switch(option_2){
        case 0:
        break;
        case 1:
        cout<<"Singly linked list called: "<<endl;
        l1.menu_l1();
        break;
        case 2:
        cout<<"Doubly linked list called: "<<endl;
        l2.menu_l2();
        break;
        case 3:
        cout<<"circular linked listcalled: "<<endl;
        l3.menu_l3();
        break;
       
       
        }
       
       
        }while(option_2!=0);
       break;
    }
    }while (option != 0);  

  return 0;
   
}