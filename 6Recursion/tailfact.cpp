//solve factorial using tail recursion
#include<iostream>
using namespace std;
int tailFac(int n, int res){
    if(n==1){
        return res;
    }
    else{
        return tailFac(n-1,n*res);

    }

}
int Fact(int n){
        return tailFac(n,1);
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"The fatorial of "<<n<<" is: "<<Fact(n)<<endl;
    return 0;
}