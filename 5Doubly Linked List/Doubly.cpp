
// 1.	INSERTION OPERATIONS
// a.	INSERT Node AT BEGINNING OF THE LIST
// b.	INSERT Node AT END OF THE LIST
// c.	INSERT Node AFTER SPECIFIC Node
// d.	INSERT Node BEFORE SPECIFIC Node

// 2.	DELETION OPERATIONS
// a.	DELETE Node FROM BEGINNING OF THE LIST
// b.	DELETE Node FROM END OF THE LIST
// c.	DELETE Node AFTER SPECIFIC Node
// d.   DELETE Node BEFORE SPECIFIC Node
#include<iostream>
using namespace std;
class MyList{
    private:
    struct Node
    {
        Node *left;
        int DATA;
        Node *right;
    }* start;
    typedef struct Node *NODE;
    public:
    MyList(){
        start=NULL;
    }
    void InsertAtBeg(int num)
    {
        NODE temp;
        temp=new Node();
        temp->left=NULL;
        temp->DATA=num;
        temp->right=start;
        if(start == NULL){
            start = temp;
        }
        start->left=temp;
        start=temp;

    }
    void InsertAtEnd(int num)
    {
            NODE temp,p;
            p=start;
            temp=new Node();
            temp->DATA=num;
            temp->right = NULL;
            while(p->right!= NULL)
            {
                p=p->right;
            }
            p->right = temp;
            temp->DATA=num;
            temp->right=NULL;
            temp->left=p;
    }
    void InsertAfter(int num,int pos)
    {
        NODE temp,p;
        int i;
        p=start;
    for(i=0;i<pos-1;i++)
    {
         p=p->right;
    }
    if(p==NULL)
    {
    cout<<"There are less than "<<pos<<"elements in the list."<<endl;
    return ;
    }
    temp=new Node();
    temp->DATA=num;
    temp->right=p->right;
    temp->left=p;
    p->right->left=temp;
    p->right=temp;
    }
    void InsertBefore(int num,int pos){
    NODE temp,p;
    int i;
    p=start;
    if(p==NULL)
    {
    cout<<"There are less than "<<pos<<"elements in the list."<<endl;
    }
    temp=new Node();
    temp->DATA=num;
        if(pos == 1){
             InsertAtBeg(num);
        }else{
            InsertAfter(num, pos-1);
        
         }

    }
    void DeleteFromBeg()
    {   NODE temp;
        if(start == NULL)
        {
            cout<<"Empty list!"<<endl;
            }
        temp = start;
        start = start->right;
        start->left = NULL;
        delete temp;
        cout<<"Element at the begining deleted!"<<endl;

    }
    void DeleteAtEnd()
    {   
        NODE temp,p;
        p=start;
        if(start == NULL)
        {
            cout<<"Empty list!"<<endl;
            }
        while(p->right!=NULL) /*last element deleted*/
        {
            p=p->right;
        } 
        temp=p;
        p=p->left;
        p->right=NULL;
        delete temp;
        cout<<"Element at the end deleted!"<<endl;
        }
    void DeleteAfter(int pos){
        NODE temp,p;
        p=start;
        for(int i=0;i<pos-1;i++)
        {
            p=p->right;
        }
        temp=p->right;
        p->right=temp->right;
        temp->right->left=p;
        delete temp;
    }
    void DeleteBefore(int pos){
        if(pos==1){
            cout<<"Enter Valid Position!"<<endl;
        }
        else if(pos==2){
            DeleteFromBeg();
        }
        else{
            DeleteAfter(pos-2);
        }

    }
    void display()
    {
        NODE ptr;
        ptr=start;
    if(ptr==NULL)
        {
            cout<<"Empty List!"<<endl;
        }
    else
    {
        cout<<"\n My List:"<<endl;
        while(ptr!=NULL)
        {
            cout<<ptr->DATA<<"\t-->";
            ptr=ptr->right;
        }
    }

    }
};
int main()
{

   int choice,n;
   int item;
   int NodeData;
   char option;
   MyList L1;
   cout<<"Operations:"<<endl;
   cout<<"1. INSERT Node AT BEGINNING OF THE LIST"<<endl;
   cout<<"2. INSERT NODE AT END OF THE LIST"<<endl;
   cout<<"3. INSERT NODE AFTER SPECIFIC NODE"<<endl;
   cout<<"4. INSERT NODE BEFORE SPECIFIC NODE "<<endl;
   cout<<"5. DELETE NODE FROM BEGINNING OF THE LIST"<<endl;
   cout<<"6. DELETE NODE FROM END OF THE LIST"<<endl;
   cout<<"7. DELETE NODE AFTER SPECIFIC NODE"<<endl;
   cout<<"8. DELETE NODE BEFORE SPECIFIC NODE"<<endl;
   cout<<"9. DISPLAY LIST"<<endl;
   cout<<"10. EXIT"<<endl;
  do{
   cout<<"Enter Choice: ";
   cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter element:"<<endl;
        cin>>item;
        L1.InsertAtBeg(item);
        L1.display();
        break;
    case 2:
        cout<<"Enter element:"<<endl;
        cin>>item;
        L1.InsertAtEnd(item);
        L1.display();
        break;
    case 3:
        cout<<"Enter element:"<<endl;
        cin>>item;
        cout<<"Insertion After which Node:"<<endl;
        cin>>NodeData;
        L1.InsertAfter(item,NodeData);
        L1.display();
        break;
    case 4:
        cout<<"Enter element:"<<endl;
        cin>>item;
        cout<<"Insertion Before which Node:"<<endl;
        cin>>NodeData;
        L1.InsertBefore(item,NodeData);
        L1.display();
        break;

    case 5:
        L1.DeleteFromBeg();
        L1.display();
        break;
    case 6:
        L1.DeleteAtEnd();
        L1.display();
        break;
    case 7:
        cout<<"Deletion after which Node:"<<endl;
        cin>>NodeData;
        L1.DeleteAfter(NodeData);
        L1.display();
        break;
    case 8:
        cout<<"Deletion before which Node:"<<endl;
        cin>>NodeData;
        L1.DeleteBefore(NodeData);
        L1.display();
        break;

    case 9:
        L1.display();
        break;
    case 10:
        cout<<"Successfully Terminated!"<<endl;
        exit(0);
        break;
    default:
    cout<<"\n Enter any of above choices or exit.";}
    cout<<"\nContinue? Y/N:"<<endl;
    cin>>option;}while((option=='Y')|| (option=='y'));
 return 0;
}