/*Write a program to implement the following two functions on string using pointer:

i. To calculate length of given string
*/
#include<iostream>
using namespace std;
int main(){
    int strsize(char *);
    char str[100];
    char *ptr;
    ptr=str;
    int n;
    cout<<"Enter a string:"<<endl;
    cin>>ptr;
    n=strsize(ptr);
    cout<<"Length of string is"<<n;


}
int strsize(char *ptr)
{
    int count=0;
    while(*ptr!='\0')
    {
        count++;
        *ptr++;
    }
    return (count);
}