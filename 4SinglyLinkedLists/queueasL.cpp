#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node *node;   
struct Node* front;
struct Node* rear;
class myQueue{
public:
myQueue()
{
    front = NULL;
    rear = NULL; 
    }
void push();
void pop();
void traverse();

};
void myQueue::push(){
    struct Node*temp;
    int data;
    temp =new Node();  
    cout<<"\n Enter the value to be inserted: ";
    cin>>temp->data;
    temp->next=NULL;
    if (rear != NULL)
        rear->next = temp;
        rear=temp;
    if (front == NULL)
        front = rear;
}
void myQueue::pop()
{
if (front == NULL)
{
cout<<"\n Empty Queue!";
rear = NULL;
}
else
{
cout<<"\nThe popped element is = "<<front->data;
if(front != rear)
    front=front->next;
else
    front = NULL;
}}
void myQueue::traverse()
{
if (front==NULL)
cout<<"\nEmpty Queue!";
else
{
node tempf=front;
cout<<"\n Elements of Queue: ";
while(tempf != rear)
{
cout<<tempf->data;
tempf=tempf->next;
};
cout<<tempf->data<<"-->";
}
}
int main()
{
int choice;
char option;
myQueue Q;
do
{
cout<<"\n1. PUSH\n";
cout<<"2. POP\n";
cout<<"3. DISPLAY\n";
cout<<"\n\nEnter your choice = ";
cin>>choice;
switch(choice)
{
case 1:
Q.push();
break;
case 2:
Q.pop();
break;
case 3:
Q.traverse();
break;
}
cout<<"\n\nPress (Y/y) to continue = ";
cin>>option;
}while(option == 'Y'|| option == 'y');
}
