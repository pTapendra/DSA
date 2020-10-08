#include <iostream>
#define size 20
int available[size];

template<typename R>
class Node
{
public:
    R info;
    int next;
    Node() : info(-1), next(-1) { }
};

template<typename T>
class mylist
{
    int rear, front;
    Node<T> node[size];
    bool empty();
    bool avail(int n);
    int getNode();
    void freeNode(int n);
public:
    mylist() : rear(-1), front(-1) { }
    void insert(T n);
    void remove();
    void show();
};

template<typename T>
void mylist<T>::show()
{
    // int index = front;
    std::cout << "Index                info                next" << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (available[i] != 0)
        {
            std::cout << i << "                    " << node[i].info << "                    " <<node[i].next << "\n";
        }
        else
        {
            std::cout << i << "                    " << '-' << "                    " << '-' << "\n";
        }
    }
    std::cout << "Rear = " << rear << "  Front = " << front << std::endl;
}

template<typename T>
bool mylist<T>::empty()
{
    return front == -1;
}

template<typename T>
bool mylist<T>::avail(int n)
{
    return available[n] == 0;
}

template<typename T>
void mylist<T>::freeNode(int n)
{
    available[n] = 0;
}

template<typename T>
int mylist<T>::getNode()
{
    int catcher;
    for (int i = front + 1; i < size; i++)
    {
        if (avail(i))
        {
            catcher = i;
            available[catcher] = 1;
            return catcher;
        }
    }
    std::cout << "Node not available!!!\n";
    exit(1);
}

template<typename T>
void mylist<T>::insert(T n)
{
    int index = getNode();
    node[index].info = n;
    node[index].next = -1;
    if (rear == -1)
    {
        front = index;
    }
    else
    {
        node[rear].next = index;
    }
    rear = index;
}

template<typename T>
void mylist<T>::remove()
{
    if (empty())
    {
        std::cout << "list is empty!!!\n";
    }
    int remem_ = front;
    front = node[front].next;
    freeNode(remem_);
}

int main()
{
    mylist<int> q;
    q.insert(12);
    q.insert(11);
    q.insert(13);
    q.insert(14);
    q.insert(15);
    q.show();
    q.remove();
    q.remove();
    q.insert(3);
    q.insert(5);
    q.insert(7);
    q.remove();
    q.remove();
    q.show();
}
