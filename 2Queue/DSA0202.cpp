//2.	Perform enqueue and dequeue operations in Circular Queue
#include<iostream>
using namespace std;
class queue{
    int rear,front;
    int N;
    int *que;
     public:
    queue(int i)
    {
        front=rear=-1;
        N=i;
        que=new int[i];
    }
   
    void enqueue(int data){
        if ((front==0&&rear==N-1)|| (rear==(front-1)%(N-1)))
        {
            cout<<"The queue is full";
            return;
        }
        else if(front==-1)
        {
            front=rear=0;
            que[rear]=data;
        }
        else if(rear==N-1&& front!=0)
        {
            rear=0;
            que[rear]=data;
        }
        else{
            rear++;
            que[rear]=data;
        }
    }
    int dequeue(){
        if(front==-1&& rear == -1){
            cout<<"queue is empty"<<endl;
        }
        int data = que[front]; 
            que[front] = -1; 
            if (front == rear) 
                { 
                    front = -1; 
                     rear = -1; 
        } 
            else if (front == N-1) 
                     front = 0; 
             else
                 front++; 
  
    return data; 
    }
    void display(){
        if(front==-1&& rear == -1){
            cout<<"\n empty queue"<<endl;
            return;
        }
        cout<<"The queue is:"<<endl;
    	    int i= front;
	    while (i != rear )
        {
            cout << que[i] << " ";
            i = (i+1) % N;
        }
        cout << que[rear] << "\n\n";
    
    }
    };
int main(){
    queue mq(7);
    mq.enqueue(2);
    mq.enqueue(5);
    mq.enqueue(80);
    mq.enqueue(9);
    mq.display();
    cout<<"Deleting the elements from queue"<<endl;
    mq.dequeue();
    mq.dequeue();
    mq.display();
    cout<<"After further insertion"<<endl;
    mq.enqueue(20);
    mq.enqueue(40);
    mq.display();


    return 0;


}
