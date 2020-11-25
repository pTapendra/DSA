//solve fibonacci using tail recursion
#include<iostream>
using namespace std;
int tailFib(int n, int reso,int res){
        if(n==0){
        return reso;
    }
    if(n==1){
        return res;
    }

    else{
        return tailFib(n-1,res,res+reso);

    }

}
int Fib(int a){
    return tailFib(a-1,0,1);
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"The "<<n<<" th fibonacci number is: "<<Fib(n)<<endl;
    return 0;
}