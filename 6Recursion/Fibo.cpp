//Find fibonacci number for given term N
#include<iostream>
using namespace std;
class Fibo{
    public:
    Fibo(){}
   int FiboSeries(int);

};
int Fibo::FiboSeries(int a){
    if(a==0 || a==1){
        return a;
    }
    else
    {
        return FiboSeries(a-1)+FiboSeries(a-2);
    }
    
}
int main(){
    Fibo F;
    int n; 
    cout<<"Enter required term of series: ";
    cin>>n;
    cout<<"The nth Fibonacci Number is: ";
    cout<<F.FiboSeries(n);
}