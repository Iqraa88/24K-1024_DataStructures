#include<iostream>
using namespace std;

class Node{

    public:
    int compartmentNo;
    Node *next;
    Node* prev;


    Node(){
    
        compartmentNo= 0;
        next= NULL;
        prev= NULL;

    }

    Node(int num){
    
        compartmentNo= num;
        next= NULL;
        prev= NULL;
    
    }

};
class RailwaySyt{

    public:
    Node* head;
    Node* temp;
    Node * tail;


    RailwaySyt(){
    
        head=NULL;
        tail=NULL;
        temp=NULL;
    }

    

    void addAtEnd(){

        Node *nn= new Node;
        cout<<"Enter Compartment Number you want to add at the end? "<<endl;
        cin>> nn->compartmentNo;

        if(head==NULL){
        head=nn;
        tail=nn;
        }
        else{
        
            tail->next= nn;
            nn->prev= tail;
            tail= nn;
            tail->next= NULL;
        }

    }

    void removeFromStart(){
    
        if(head!=NULL){
        
            temp= head->next;
            head->next->prev= NULL;
            delete head;
            head= temp;
        }
        else{
        cout<<"Train is empty!"<<endl;
        }
    }

    void searchCompNum(int num){
    
        temp= head;
        while(temp!=NULL){
        
        if(temp->compartmentNo== num){
            cout<<"Compartment Number Found: "<< temp->compartmentNo<<" :)"<<endl;
        }   
        temp= temp->next; 
        
        }
        cout<<"Couldn't find your desired compartment number!"<<endl;
    }

    void display(){
    
        temp= head;
        while(temp!=NULL){
        
            cout<<temp->compartmentNo<<" -> ";
            temp=temp->next;
        }
        cout<<"end";
        cout<<endl;
    }

};


int main()
{

    RailwaySyt r1;
     int choice;
     int cNum;

    do{
        cout<<"---- Railway System Menu ----"<<endl;
        cout<<"1. Add Compartment at End"<<endl;
        cout<<"2. Remove Compartment from Start"<<endl;
        cout<<"3. Search Compartment by Number"<<endl;
        cout<<"4. Display Train"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                r1.addAtEnd();
                break;
            case 2:
                r1.removeFromStart();
                break;
            case 3:
                cout<<"Enter compartment number to search: ";
                cin>>cNum;
                r1.searchCompNum(cNum);
                break;
            case 4:
                r1.display();
                break;
            case 5:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice jee!! :)."<<endl;
        }
    }
    while(choice != 5);


  
 return 0;
}
