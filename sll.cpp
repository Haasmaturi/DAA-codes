#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* top=NULL;
    int choice,value;

    while(true){
        cout<<"\n--- STACK MENU ---\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
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
            newNode->next=top;
            top=newNode;

            cout<<"Element pushed successfully.\n";
        }

        else if(choice==2){
            if(top==NULL){
                cout<<"Stack Underflow.\n";
            }
            else{
                Node* temp=top;
                cout<<"Popped element: "<<top->data<<endl;
                top=top->next;
                delete temp;
            }
        }

        else if(choice==3){
            if(top==NULL){
                cout<<"Stack is empty.\n";
            }
            else{
                cout<<"Top element: "<<top->data<<endl;
            }
        }

        else if(choice==4){
            if(top==NULL){
                cout<<"Stack is empty.\n";
            }
            else{
                Node* temp=top;
                cout<<"Stack: ";

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