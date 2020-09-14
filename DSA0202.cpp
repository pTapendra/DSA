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
    while(str.top() != '#') 
    { 
        char c = str.top(); 
        str.pop(); 
        newst += c; 
    } 
      
    cout << newst << endl; 
  
} 
  
int main() 
{ 
    string exp = "a+b/c*d-b/e*a^b"; 
    InToPost(exp); 
    return 0; 
} 
