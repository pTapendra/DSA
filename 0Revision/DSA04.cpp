//4. WAP to swap the values (of type int, double, char) using class template.
#include<iostream>
using namespace std;
template<class T>
void Swap(T &a, T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}

int main(){
  int i1= 5 , i2 = 20;
  char ch1 ='T', ch2 = 'P';
  double d1=40.223, d2=2.03354;
  cout << i1 << " " << i2 << endl;
  cout <<ch1 << " " << ch2 << endl;
  cout << d1 << " " << d2 << endl;
  cout<<"After Swap"<<endl;
  
  Swap(i1, i2);
  Swap(ch1, ch2);
  Swap(d1, d2);
  cout <<i1 <<" "<< i2 << endl;
  cout <<ch1 << " " << ch2 << endl;
  cout <<d1 <<" "<< d2 << endl;
   return 0;
}


