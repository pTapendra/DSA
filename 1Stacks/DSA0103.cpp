//Convert infix operation to prefix operation
#include<iostream>
#include<stack>
#include<cstring>
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
void reverse(string st){
    int len=st.length();
    string revstring;
    for(int i=len;i>=0;i--){
        if((st[i]>='a'&&st[i]<='z')||( st[i]>='A'&& st[i]<='Z'))
        revstring+=st[i];
        else if(st[i] == '('){st[i]=')';revstring+=st[i];}
        else if(st[i] == ')'){st[i]='(';revstring+=st[i];}
        else if(st[i]=='+'||st[i]=='-' ||st[i]=='*' ||st[i]=='/'){revstring+=st[i];}
        else{revstring+=st[i];}
    


    }

    st=revstring;
    cout<<st;

}
void InToPref(string s)
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
     s=newst;
     cout<<s<<endl;
     cout<<"The required prefix is:"<<endl;
      reverse(s);
  
} 




int main() 
{ 
    string exp;
    exp="((A+B)*C-(D-E))$(F+G)";
    cout<<"reverse of given expression is:"<<endl;
    reverse(exp);

    cout<<"\n The postfix of reversed expression is:";
    InToPref(exp);
    cout<<endl;
    return 0; 
} 
