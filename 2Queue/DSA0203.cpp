// 3.	Perform operations in Deque( Double ended queue) for:
// a.	Add at beginning
// b.	Add at end
// c.	Delete from beginning
// d.	Delete from end
#include<iostream>
// #include<deque>
// using namespace std;
// void display(deque <int> e){
//     deque <int>::iterator i;
//     for(i=e.begin();i!=e.end();++i){
//         cout<<' '<<*i;

//     }
//     cout<<endl;
// }
// int main(){
//     deque<int> myqueue;
//     //insert at end
//     myqueue.push_back(12);
//     myqueue.push_back(13);
//     myqueue.push_back(15);
//     //insert at beginning
//     myqueue.push_front(14);
//     myqueue.push_front(10);
//     cout<<"The deque is: "<<endl;
//     display(myqueue);
//     myqueue.pop_front();
//     myqueue.pop_front();
//     cout<<"After deletion from beginning:"<<endl;
//     display(myqueue);
//     myqueue.pop_back();
//     myqueue.pop_back();
//     cout<<"After deletion from end:"<<endl;
//     display(myqueue);
//     return 0;
// #include<bits/stdc++.h>
#define MAX 5
using namespace std;

class Deque{
private:
    int A[MAX];
    int front,rear;
public:
    Deque(){
        front = -1;
        rear = -1;
    }
    void enqueuefront(int );
    void enqueuerear(int );
    void dequeuefront();
    void dequeuerear();
    void print();

};

void Deque::enqueuefront(int xf){
    if((front==0 && rear==MAX-1) || (front==rear+1))
        cout<<"queue is full";
    else if(front == -1 && rear== -1){
        front=rear=0;
        A[front] = xf; 
    }
    else if(front == 0)
    {
        front = MAX -1;
        A[front] = xf;
    }
    else{
        front --;
        A[front] =xf;
    }
}

void Deque::enqueuerear(int xr){
     if((front==0 && rear==MAX-1) || (front==rear+1))
        cout<<"queue is full";
    else if(front == -1 && rear== -1){
        front=rear=0;
        A[rear] = xr; 
    }
    else if(rear == MAX -1){
        rear = 0;
        A[rear] = xr;
    }
    else{
        rear++;
        A[rear] = xr;
    }
}

void Deque::dequeuefront(){
    if(front==-1 && rear == -1){
        cout<<"underflow condition";
        return;
    }
    else if(front == rear){
        front=rear= -1;
    }
    else if(front == MAX -1){
       front = 0;
    }
    else{
        front ++;
    }
}

void Deque::dequeuerear(){
    if(front==-1 && rear == -1){
        cout<<"underflow condition";
        return;
    }
    else if(front == rear){
        front=rear= -1;
    }
    else if(rear == 0){
        rear = MAX -1;
    }
    else{
        rear --;
    }
}

void Deque::print(){
    int i = front; 
    while(i!=rear){
        cout<<A[i]<<" ";
        i = (i+1)%MAX;
    }
    cout<<A[rear]<<endl; 
}


int main(){
    Deque D;
    D.enqueuefront(2);
    D.enqueuefront(5); 
    D.print();
    D.enqueuerear(-1); 
    D.print();
    D.enqueuerear(0); 
    D.enqueuefront(7); 
    cout<<" -------------"<<endl;
    D.dequeuefront();
    D.dequeuerear();
    D.dequeuefront();
    D.print();

}

