#include<iostream>
using namespace std;

class Node{

    public:

    string data;
    Node *next;

    Node(){
    
        data= "";
        next= NULL;
    }
};

class LinkedList{

    public:

    Node *head;
    Node *tail;
    Node *temp;

    LinkedList(){
    
        head= NULL;
        tail= NULL;
        temp= NULL;
    }

    void createLL(int size){
    
        for(int i=0; i<size; i++){
            Node *nn= new Node;
            cout<<"Enter Node Data: "<<endl;
            getline(cin, nn->data);
            
            if(head== NULL){
            
                head= nn;
                temp= head;
            }
            else{
            
                temp->next= nn;
                temp= temp->next;
                if(i==size-1){
                    tail= temp;
                tail->next= NULL;
                }
            }
        }
    }

    void display(){
     temp= head;
     while(temp!=NULL){
    
        cout<< temp->data<<" -> ";
        temp= temp->next;
    
    }

        cout<<"null/0";
        cout<<endl;
}

    void insertAtStart(){
    
        Node *nn= new Node;
        cout<<"Enter the Node Data to insert at start: "<<endl;
        getline(cin, nn->data);

        if(head==NULL){
            head= nn;
            tail=nn;
        }
        else{
        
            nn->next= head;
            head= nn;
        }
    }
    void insertAtEnd(){

    Node *nn= new Node;
    cout<<"Enter Node Data you want to insert at end: "<<endl;
    getline(cin, nn->data);
      temp=head;
      if(head==NULL){
        head= nn;
        tail=nn;
    }
   else{
    tail->next= nn;
    tail= nn;
    tail->next= NULL;
    }
}
    void insertAfterData(string data){
    
        temp=head;
        Node *nn= new Node;
        cout<<"Insert New Node Data you want to insert after "<< data << " : "<<endl;
        getline(cin, nn->data);

        if(temp==NULL){
        cout<<"Data not found!"<<endl;
        delete nn;
        return;
        }
        while(temp!=NULL && temp->data!= data){
        
            temp=temp->next;
        }
        nn->next= temp->next;
        temp->next= nn;
    
    }
    bool searchForData(string data){
    
        temp= head;
        while(temp!=NULL){
        
            if(temp->data== data){
            
            return true;
          
            }
            
            
        
            temp= temp->next;

        
    }
            return false;

}

};


int main()
{

    LinkedList l1;
    l1.createLL(4);
    l1.display();
    l1.insertAtStart();
    l1.insertAtEnd();
    if(l1.searchForData("DBS")){
    cout<<"Database Systems exists in the list!"<<endl;
    }
    else{
    cout<<"Not Found!"<<endl;
    }
    l1.display();


 return 0;
}