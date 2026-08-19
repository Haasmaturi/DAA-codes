#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* front=NULL;
    Node* rear=NULL;
    int choice,value;

    while(true){
        cout<<"\n--- QUEUE MENU ---\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1){
            cout<<"Enter value: ";
            cin>>value;

            Node* newNode=new Node();
            newNode->data=value;
            newNode->next=NULL;

            if(front==NULL){
                front=rear=newNode;
            }
            else{
                rear->next=newNode;
                rear=newNode;
            }

            cout<<"Element inserted successfully.\n";
        }

        else if(choice==2){
            if(front==NULL){
                cout<<"Queue Underflow.\n";
            }
            else{
                Node* temp=front;
                cout<<"Deleted element: "<<front->data<<endl;
                front=front->next;

                if(front==NULL){
                    rear=NULL;
                }

                delete temp;
            }
        }

        else if(choice==3){
            if(front==NULL){
                cout<<"Queue is empty.\n";
            }
            else{
                cout<<"Front element: "<<front->data<<endl;
            }
        }

        else if(choice==4){
            if(front==NULL){
                cout<<"Queue is empty.\n";
            }
            else{
                Node* temp=front;
                cout<<"Queue: ";

                while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }

                cout<<endl;
            }
        }

        else if(choice==5){
            cout<<"Exiting...\n";
            break;
        }

        else{
            cout<<"Invalid choice.\n";
        }
    }

    return 0;
}