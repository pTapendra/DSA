//Find the factorial for given number N
#include<iostream>
using namespace std;
class Factorial{
    private:
    int n;
    public:
    Factorial(){n=0;}
   int findFact(int);

};
int Factorial::findFact(int a){
    if(a==0){
        return 1;
    }
    else
    {
        return a*findFact(a-1);
    }
    
}
int main(){
    Factorial f1;
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"The fatorial of "<<n<<" is: "<<f1.findFact(n)<<endl;
    return 0;
}