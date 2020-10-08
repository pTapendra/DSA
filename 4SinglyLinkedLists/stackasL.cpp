#include<iostream>
using namespace std;
    struct Node{
    int data;
    struct Node* link;
};
struct Node* top;
class myList {
    
public:
myList()
{top=NULL;}
void push();
int isEmpty();
void peek();
void pop();
void display();

};
void myList::push(){
    struct Node*temp;
    int data;
    temp =new Node();
    cout<<"\n Enter the value to be inserted: ";
    cin>>data;
    temp->data=data;
    temp->link=top;
    top=temp;
    
}
int myList::isEmpty(){
   return top==NULL;
}
void myList::peek(){
    if(!isEmpty())
    cout<<top->data;
    else
    {
        cout<<"Empty List"<<endl;
    }
    
}

void myList::pop(){
    struct Node* temp;
    if(isEmpty()){
        cout<<"Stack is empty!";
    }
    else{
        temp=top;
        cout<<"The popped element is:"<<temp->data;
        top=top->link;
        temp->link=NULL;
        free(temp);
    }

}
void myList::display(){
       struct Node* temp;
       if(isEmpty()){
           cout<<"Empty stack";
       }
       else{
           cout<<"\nThe list is: "<<endl;
           temp=top;
           while(temp!=NULL){
               cout<<temp->data<<"\t-->";
               temp=temp->link;
           }
       }
}
int main()
{
myList l;
int a;
char option;
do{
cout<<"Operations:";
cout<<"\n1.Push elements"<<endl;
cout<<"2.Display top element\n";
cout<<"3.Pop top element\n";
cout<<"4.Display list\n";
cout<<"\nEnter any of above choices : ";
cin>>a;
switch(a)
{
case 1:
l.push();
break;
case 2:
l.peek();
break;
case 3:
l.pop();
break;
case 4:
l.display();
default:
cout<<"\n Enter any of above choices or exit.";}
cout<<"\nContinue? Y/N:"<<endl;
cin>>option;
}while((option=='Y')|| (option=='y'));
}