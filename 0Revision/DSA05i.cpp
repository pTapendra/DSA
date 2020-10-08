/*Write a C++ program to perform arithmetic operations on two numbers and throw an exception if the dividend is zero or does not contain an operator.
 Enter the input as a+b, where ‘a’ and ‘b’ are input numbers and ‘+’ as operator. 
 Check for the valid operators and perform the different operations like addition, subtraction, multiplication and division accordingly.
 Perform no.5 with and without using Exception Class*/
 #include<stdio.h>
 using namespace std;
 #include<iostream>
using namespace std;
int main(){
    float a,b,add,sub,mul,div;
    char opr;
    char msg1[100];
    int msg2;
    cout<<"Enter the expression as- a(operation)b: "<<endl;
    cin>>a>>opr>>b;
    try{
        if(opr=='-'){sub=a-b;cout<<sub<<endl;}
          
         else if(opr=='+'){add=a+b;cout<<add<<endl;}
        
        else if(opr=='*'){mul=a*b;cout<<mul<<endl;}
        
        else if(opr=='/'){
            if(b!=0){div=a/b;cout<<div<<endl;}
            else{throw msg1;}
        }
         else{throw msg2;}
       

    }

   catch(char a[]){
       cout<<"Denominator must be non zero.Try again"<<endl;
       main();
   }
   catch(int ){
       cout<<"Try again with valid operator.Try again"<<endl;
       main();
   }
return 0;}