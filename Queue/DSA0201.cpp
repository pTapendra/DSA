//1.	Perform enqueue and dequeue operations in Linear Queue  
#include<iostream>
using namespace std;

int front=0;
int rear=-1;
#define N 10
int queue[N];
   int peek() {
   return queue[front];
}
 
bool isfull() {
   if(rear == N-1)
      return true;
   else
      return false;
}
bool isempty() {
   if(front < 0 || front > rear) 
      return true;
   else
      return false;
}
int enqueue(int data){      
   if(isfull()){cout<<"The queue is full"<<endl; return 0;}
      rear = rear + 1;
      queue[rear] = data;
      return 1;
}
int dequeue() {
   if(isempty()){cout<<"The queue is empty"<<endl; return 0;}
   int data = queue[front];
   front = front + 1;

   return data;
}
int display(){
        if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            cout<<queue[i]<<" ";
    } 
}
int main(){
    enqueue(2);
    enqueue(4);
    enqueue(5);
    enqueue(8);
    enqueue(10);
    cout<<"Queue after enqueue operation:"<<endl;
    display();
     int d1= dequeue();
    cout<<"\n"<<d1<<" is removed"<<endl;
    int d2= dequeue();
    cout<<d2<<" is removed"<<endl;
    int f1= peek();
    cout<<f1<<" is the element at front"<<endl;
    cout<<"Queue after dequeue operation:"<<endl;
    display();


}