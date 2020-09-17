//Perform push and pull operations in array
#include<iostream>
using namespace std;
int Stack[100],last;
void push(int x){
    ++last;
    Stack[last]=x;

}
void pop(){
    Stack[last]=0;
    --last;

}
bool isEmpty(){
    if(last>=1) return false;
    else return true;
    
}
int top(){
    return Stack[last];
}
int main(){
    last=0;
    push(5);
    push(10);
    push(3);
    while(!isEmpty()){
        cout<<' '<<top();
        pop();
    }
    return 0;

}