#include<iostream>
struct Node 
{ 
    int coeff;
    int expo; 
    struct Node *link; 
}; 
typedef struct Node *node;        
node create(node start,float coef, int exp) 
{ 
    node p,temp;
    temp=new Node();
    temp->coeff=coef;
    temp->expo=exp; 
   
    if(start == NULL||exp>start->expo) 
    { 
        temp->link=start;
        start=temp;
    } 
    else
    { 
        p=start;
        while(p->link!=NULL&&p->link->expo>exp)
        p=p->link;
    temp->link=p->link;
    p->link=temp;
    if(p->link==NULL)
    temp->link=NULL;
    } 
    return start;
} 

node add(node poly1,node poly2) 
{ 
node poly,p3,temp;
poly=NULL;
if(poly1==NULL && poly2==NULL)
return poly;
while(poly1!=NULL && poly2!=NULL)
{
temp=new Node();
if(poly==NULL)
{
poly=temp;
p3=poly;
}
else
{
p3->link=temp;
p3=p3->link;
}
if(poly1->expo > poly2->expo)
{
temp->coeff=poly1->coeff;
temp->expo=poly1->expo;
poly1=poly1->link;
}
else if(poly2->expo > poly1->expo)
{
temp->coeff=poly2->coeff;
temp->expo=poly2->expo;
poly2=poly2->link;
}
else
if(poly1->expo == poly2->expo)
{
temp->coeff=poly1->coeff+ poly2->coeff;
temp->expo=poly1->expo;
poly1=poly1->link;
poly2=poly2->link;
}
}
while(poly1!=NULL)
{
temp=new Node();
temp->coeff=poly1->coeff;
temp->expo=poly1->expo;
if(poly==NULL)
{
poly=temp;
p3=poly;
}
else
{
p3->link=temp;
p3=p3->link;
}
poly1=poly1->link;
}
while(poly2!=NULL)
{
temp=new Node();
temp->coeff=poly2->coeff;
temp->expo=poly2->expo;
if(poly==NULL)
{
poly=temp;
p3=poly;
}
else
{
p3->link=temp;
p3=p3->link;
}
poly2=poly2->link;
}
p3->link=NULL;
return poly;
}
node enter(node start)
{
int i,n,exp;
float coef;
std::cout<<"\nEnter no of terms in polynomial: ";
std::cin>>n;
for(i=1;i<=n;i++)
{
std::cout<<"\nCoefficient of term "<<i<<": ";
std::cin>>coef;
std::cout<<"Exponent of term "<<i<<": ";
std::cin>>exp;
start=create(start,coef,exp);
}
return start;
}
//This function will display the two polynomials and its added polynomials
void display(node p)
{
if(p==NULL)
{
std::cout<<"\nEmpty polynomial\n";

}
while(p!=NULL)
{
std::cout<<p->coeff<<"x^"<<p->expo<<"+";
p=p->link;
}
std::cout<<"\b \n";
}
int main()
{
node poly1,poly2,poly;
poly1=NULL;
poly2=NULL;
poly=NULL;
std::cout<<"\n Enter first Polynomial:\n";
poly1=enter(poly1);
std::cout<<"\n Enter second Polynomial:\n";
poly2=enter(poly2);
poly=add(poly1,poly2);
std::cout<<"\nFist Polynomial: ";
display(poly1);
std::cout<<"\nSecond Polynomial: ";
display(poly2);
std::cout<<"\nResulting Polynomial: ";
display(poly);
}