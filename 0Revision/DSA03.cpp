//3. WAP to swap the values (of type int, double, char) using function template.
#include<iostream>
using namespace std;
template<typename T>
class zwap
{
T a,b;
public:
  zwap(T a1, T b1) : a(a1), b(b1){ } ;
  void swap(){
    T temp = a;
    a = b;
    b = temp;
   }
void display(){
    cout << a << " " << b << endl;
  }

};
int main()
{
  zwap<int> i(2, 3);
  zwap<char> c('A', 'Z');
  zwap<double> d(4.5,10.2245);
  i.display();
  i.swap();
  i.display();

  c.display();
  c.swap();
  c.display();

  d.display();
  d.swap();
  d.display();

  
}
