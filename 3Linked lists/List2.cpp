#include <iostream>
using namespace std;

template<typename R>
class Node
{
    public:
    R data;
    Node *next;
    Node () : data(0) { }
    Node(R n, Node *node = nullptr) : data(n), next(nullptr) { }
};

template<typename T>
class mylist{
  int count;
  Node<T> *head;
  Node<T> *front;
public:
  mylist() : count(0), head(nullptr), front(nullptr) { }
  void dequeue();
  T top();
  T bottom();
  void enqueue(T x);
  bool empty();
};

template<typename T>
bool mylist<T>::empty()
{
    return count == 0;
}

template<typename T>
void mylist<T>::enqueue(T x)
{
    if(empty())
    {
        head = new Node<T>(x);
        front = head;
        count++;
    }
    else
    {
        Node<T> *temp = new Node<T>(x);
        front->next = temp;
        front = front->next;
        count++;
    }
}

template<typename T>
void mylist<T>::dequeue()
{
    if(empty())
    {
        cout << "Stack is empty, Unable to dequeue!!!" << endl;
    }
    else
    {
        Node<T> *temp = head;
        head = head->next;
        count--;
        delete temp;
    }   
}

template<typename T>
T mylist<T>::top()
{
    if(!empty())
    {
        return front->data;
    }
    else
    {
        cout << "Stack is empty, Nothing is at the top!!!" << endl;
        return -1;;
    }   
}

template<typename T>
T mylist<T>::bottom()
{
    if(!empty())
    {
        return head->data;
    }
    else
    {
        cout << "Stack is empty, Nothing is at the top!!!" << endl;
        return -1;;
    }   
}

int main()
{
    mylist<int> l;
    l.enqueue(123);
    l.enqueue(23);
    l.enqueue(145);
    l.enqueue(900);
    l.dequeue();
    l.dequeue();
    cout << l.bottom();
}