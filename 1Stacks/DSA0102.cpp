//Convert infix to postfix expression
#include<iostream>
#include<stack>
using namespace std;

int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*'||c=='/')
    return 2;
    else if(c=='+'||c=='-')
    return 1;
    else 
    return -1;
}
void InToPost(string s)
{
    stack<char>str;
    str.push('#');
    int len=s.length();
    string newst;
    for(int i=0;i<len;i++){
        if((s[i]>='a'&&s[i]<='z')||( s[i]>='A'&& s[i]<='Z')){
            newst+=s[i];}
        else if(s[i] == '(') 
            str.push('('); 
        else if(s[i]==')'){
            while(str.top()!='#'&& str.top() != '('){
                char c = str.top(); 
                str.pop();
                newst+=c;
            }
            if(str.top() == '(') 
            { 
                char c = str.top(); 
                str.pop(); 
            } 
        } 
          

        else{ 
            while(str.top() != '#' && prec(s[i]) <= prec(str.top())) 
            { 
                char c = str.top(); 
                str.pop(); 
                newst += c; 
            } 
            str.push(s[i]); 
        } 
  
    } 
    cout<<"\nThe postfix expression: "<<newst<<endl;
    while(str.top() != '#') 
    { 
        char c = str.top(); 
        str.pop(); 
        newst += c; 
    } 
    cout<<"\nAfter popping the remaining elements in stack:"<<endl;
    cout<<"Required Output:"<<endl; 
    cout << newst << endl; 
  
} 
  
int main() 
{ 
    string exp;
    cout<<"Enter ypur infix expression:"<<endl;
    cin>>exp; 
    InToPost(exp); 
    return 0; 
} 
