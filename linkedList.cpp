#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
        Node(int value)
        {
            data=value;
            next=NULL;
        }
};
class linkedList
{
    private:
        Node* head;
    public:
        linkedList()
        {
            head=NULL;
        }
        void insertAtBeginning(int value)
        {
            Node* newNode=new Node(value);
            newNode->next=head;
            head=newNode;
        }
        void insertAtEnd(int value)
        {
            Node* newNode=new Node(value);
            if(head==NULL)
            {
                head=newNode;
                return;
            }
            Node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
        void insertAtPosition(int value,int position)
        {
            Node* newNode=new Node(value);
            if(position==1)
            {
                newNode->next=head;
                head=newNode;
                return;
            }
            Node* temp=head;
            for(int i=1;i<position-1 && temp->next!=NULL;i++)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
        void deleteAtBeginning()
        {
            if(head==NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        void deleteAtEnd()
        {
            if(head==NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            if(head->next==NULL)
            {
                delete head;
                head=NULL;
                return;
            }
            Node* temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
        }
        void deleteAtPosition(int position)
        {
            if(head==NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            if(position==1)
            {
                Node* temp=head;
                head=head->next;
                delete temp;
                return;
            }
            Node* temp=head;
            for(int i=1;i<position-1 && temp->next!=NULL;i++)
            {
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                cout<<"Position out of bounds"<<endl;
                return;
            }
            Node* nodeToDelete=temp->next;
            temp->next=nodeToDelete->next;
            delete nodeToDelete;
        }
        void display()
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            Node* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};
int main()
{
    linkedList list;
    int c,v,p;
    do
    {
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Insert at position"<<endl;
        cout<<"4. Delete at beginning"<<endl;
        cout<<"5. Delete at end"<<endl;
        cout<<"6. Delete at position"<<endl;
        cout<<"7. Display list"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c)
        {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>v;
                list.insertAtBeginning(v);
                break;
            case 2:
                cout<<"Enter value to insert: ";
                cin>>v;
                list.insertAtEnd(v);
                break;
            case 3:
                cout<<"Enter value to insert: ";
                cin>>v;
                cout<<"Enter position to insert: ";
                cin>>p;
                list.insertAtPosition(v,p);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout<<"Enter position to delete: ";
                cin>>p;
                list.deleteAtPosition(p);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout<<"Exiting...."<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(c!=8);
    return 0;
}