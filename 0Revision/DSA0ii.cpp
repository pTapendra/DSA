// To concatenate two string using pointer
#include<iostream>
using namespace std;
int main(){
    char str1[100],str2[100];
    char *ptr1;
    ptr1=str1;
    char *ptr2;
    ptr2=str2;
    int n,i=0,j=0;
    cout<<"Enter a string:"<<endl;
    cin>>str1;
    cout<<"Enter next string:"<<endl;
    cin>>str2;
while(str1[i]!='\0'){
    ++ptr1;
    i++;
}
while(str2[j]!='\0'){
    *ptr1=*ptr2;
    ptr1++;
    ptr2++;
    j++;
}
cout<<"The string after concatenation is:"<<str1;
return 0;
}
