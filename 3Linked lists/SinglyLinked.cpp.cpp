
// 1.	INSERTION OPERATIONS
// a.	INSERT NODE AT BEGINNING OF THE LIST
// b.	INSERT NODE AT END OF THE LIST
// c.	INSERT NODE AFTER SPECIFIC NODE
// d.	INSERT NODE BEFORE SPECIFIC NODE

// 2.	DELETION OPERATIONS
// a.	DELETE NODE FROM BEGINNING OF THE LIST
// b.	DELETE NODE FROM END OF THE LIST
// c.	DELETE NODE AFTER SPECIFIC NODE


#include<iostream>
using namespace std;


class Mylist{

private:

    struct Node{
        int data;
        Node* next;
    }* head;

public:

    class FULL{};
    class EMPTY{};

    Mylist(){
        head = NULL;
    }


    Node* createNode(int num){
        Node* ptr;
        ptr = new Node;
        if(ptr == NULL) throw FULL();
        else{
            ptr->data = num;
            ptr->next = NULL;
        }
        return ptr;
    }



    void insertAtBeginning(int value){
        Node* avail,*new_Node;
        avail = createNode(value);
        if(avail == NULL) throw FULL();
        new_Node = avail;
        avail = avail->next;
        new_Node->data = value;
        new_Node->next = head;
        head = new_Node;
        display();
    }



    void insertAtEnd(int value){
        Node* avail,*new_Node,*ptr;
        avail = createNode(value);
        if(avail == NULL) throw FULL();
        new_Node = avail;
        avail = avail->next;
        new_Node->data = value;
        new_Node->next= NULL;

        ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_Node;
        display();

    }



    void insertAfterNode(int value,int ref_value){
        Node* avail,*new_Node,*ptr,*pre_ptr;
        avail = createNode(value);
        if(avail == NULL) throw FULL();
        new_Node=avail;
        avail=avail->next;
        new_Node->data=value;

        ptr=head;
        pre_ptr=ptr;


        while(pre_ptr->data != ref_value)
        {
            pre_ptr = ptr;
            ptr=ptr->next;
        }

        pre_ptr->next = new_Node;

        new_Node->next=ptr;
        display();
    }



    void insertBeforeNode(int value, int ref_value){
        Node* avail,*new_Node,*ptr,*pre_ptr;
        avail = createNode(value);
        if(avail == NULL) throw FULL();
        new_Node=avail;
        avail=avail->next;
        new_Node->data=value;

        ptr=head;
        pre_ptr=ptr;
        while(ptr->data != ref_value)
        {
            pre_ptr=ptr;
            ptr=ptr->next;
        }

        pre_ptr->next=new_Node;
        new_Node->next=ptr;
        display();
    }



    void deleteFromBeginning(){
        Node* ptr;
        if(head == NULL) throw EMPTY();
        ptr=head;
        head=head->next;
        delete ptr;
        display();

    }



    void deleteFromEnd(){
        if(head == NULL) throw EMPTY();
        Node *ptr,*pre_ptr;
        ptr=head;
        pre_ptr=ptr;

        while(ptr->next != NULL){
            pre_ptr=ptr;
            ptr= ptr->next;
        }
        pre_ptr->next=NULL;
        delete ptr;
        display();
    }



    void deleteAfterNode(int ref_value){
        if(head == NULL) throw EMPTY();
        Node* ptr,*pre_ptr;
        ptr=head;
        pre_ptr = ptr;
        while(pre_ptr->data != ref_value){
            pre_ptr=ptr;
            ptr=ptr->next;
        }
        pre_ptr->next = ptr->next;
        delete ptr;
        display();
    }


    void display(){
        Node* ptr;
        ptr=head;

        if(ptr==NULL) throw EMPTY();
        while(ptr != NULL)
        {
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        cout<<endl;

    }

};

int main() {

   int choice;
   int item;
   int NodeData;

   cout<<"1. INSERT Node AT BEGINNING OF THE LIST"<<endl;
   cout<<"2. INSERT NODE AT END OF THE LIST"<<endl;
   cout<<"3. INSERT NODE AFTER SPECIFIC NODE"<<endl;
   cout<<"4. INSERT NODE BEFORE SPECIFIC NODE "<<endl;
   cout<<"5. DELETE NODE FROM BEGINNING OF THE LIST"<<endl;
   cout<<"6. DELETE NODE FROM END OF THE LIST"<<endl;
   cout<<"7. DELETE NODE AFTER SPECIFIC NODE"<<endl;
   cout<<"8. EXIT"<<endl;

   Mylist sl;

   do {

      cout<<"Enter your choice : "<<endl;
      cin>>choice;

      try{

      switch (choice) {

        case 1:
            cout<<"Enter element:"<<endl;
            cin>>item;
            sl.insertAtBeginning(item);
            break;

        case 2:
            cout<<"Enter element:"<<endl;
            cin>>item;
            sl.insertAtEnd(item);
            break;

        case 3:
            cout<<"Enter element:"<<endl;
            cin>>item;
            cout<<"Enter After which Node:"<<endl;
            cin>>NodeData;
            sl.insertAfterNode(item,NodeData);
            break;

        case 4:
            cout<<"Enter element:"<<endl;
            cin>>item;
            cout<<"Enter Before which Node:"<<endl;
            cin>>NodeData;
            sl.insertBeforeNode(item,NodeData);
            break;

        case 5:
            sl.deleteFromBeginning();
            break;

        case 6:
            sl.deleteFromEnd();
            break;

         case 7:
             cout<<"Enter After which Node:"<<endl;
             cin>>NodeData;
             sl.deleteAfterNode(NodeData);
             break;

         case 8:
             cout<<"Exit"<<endl;
             break;

         default:
              cout<<"Invalid choice"<<endl;
      }}

    catch(Mylist::FULL){
    cout<<"\nException: List is FULL"<<endl;}
    catch(Mylist::EMPTY){
    cout<<"\nException: List is EMPTY"<<endl;}

   } while(choice!=8);
   return 0;
}
