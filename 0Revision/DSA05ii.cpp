//Perform no.5 using Exception Class
 #include<stdio.h>
 using namespace std;
 #include<iostream>
using namespace std;
class except{
    public:
    except(){
        cout<<"Cannot divide by zero   ";
    }
};
int main(){
    float a,b,add,sub,mul,div;
    char opr;
    char msg1[100];
    int msg2;
    cout<<"Enter the expression as- a(operation)b: "<<endl;
    cin>>a>>opr>>b;
        if(opr=='-'){sub=a-b;cout<<sub<<endl;}
          
        else if(opr=='+'){add=a+b;cout<<add<<endl;}
        
        else if(opr=='*'){mul=a*b;cout<<mul<<endl;}
        
        else if(opr=='/'){
            if(b!=0){div=a/b;cout<<div<<endl;}
            else{throw except();}
        }
         else{ cout<<"Try again with valid operator.Try again"<<endl;}
      
 
   }