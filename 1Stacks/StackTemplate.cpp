//Perform push and pull operations in Stack
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>abc;
    abc.push(1);
    abc.push(3);
    abc.push(5);
    abc.push(2);

    abc.pop();
    while(!abc.empty()){
        cout<<' '<<abc.top();
        abc.pop();
      
    }
return 0;
}
