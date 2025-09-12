#include<iostream>
using namespace std;

class Node{

    public:
    string bookName;
    Node *next;

    Node(string title){
    
        bookName= title;
        next= NULL;
    }
};
class LibCatalog{

    public:
    Node *head;
    Node* tail;
    Node *temp;

    LibCatalog(){
    
    head= NULL;
    temp= NULL;
    tail= NULL;

    }

    
    void insertFromEnd(Node *n){
    
        if(head==NULL){
        
            head=n;
            tail=n;
        }
        else{
        tail->next= n;
        tail= n;
        tail->next= NULL;
        }

        
    }

    void deleteFromStart(){
    
        if(head!=NULL){
        
            temp= head->next;
            delete head;
            head= temp;
        }
        else{

        cout<<"Catalog is empty At the moment! :)"<<endl;
        }
    }
    
    void searchBook(string bookTitle){
    
        temp= head;
        bool found= false;
        while(temp!=NULL){
        
            if(temp->bookName== bookTitle){
            
                cout<<" Book found: "<< temp->bookName<<" (:)"<<endl;
                found= true;
                
            }
            temp= temp->next;
        }
        if(!found){
        cout<<"Couldn't find Book!"<<endl;
        }
    }

    void searchByPos(int pos){
    
        int count=1;
        temp= head;
        while(temp!=NULL){
            if(count==pos){
            
                cout<<"Book Found: "<<temp->bookName<< " (:)"<<endl;
                return;
            }
            temp=temp->next;
            count++;
        }

        cout<<"Unable to find book at your entered position/ Invalid Position!"<<endl;
    
    }

    void displayCatalog(){
    
        temp= head;
        cout<<"-----------Displaying Catalog----------"<<endl;
        while(temp!=NULL){
        
            cout<<temp->bookName<<endl;
            temp=temp->next;
        
        }
    }
};
int main()
{

    LibCatalog c1;
    Node *b1= new Node("Forty Rules of Love");
    Node *b2= new Node("Reminders of Him");
    Node *b3= new Node("It Ends With Us");
    Node *b4= new Node("The Kite Runner");
    c1.head= b1;
    c1.head->next = b2;
    b2->next= b3;
    b3->next= b4;
    c1.tail= b4;
    b4->next= NULL;
    c1.displayCatalog();




    Node *b5= new Node("I dont love you anymore!");
    c1.insertFromEnd(b5);
    cout<<"-------------After Insertion-----------"<<endl;
    c1.displayCatalog();
    c1.deleteFromStart();
    cout<<"------------After Deletion------------"<<endl;
    c1.displayCatalog();


    string Bookname;
    cout<<"Enter Book Name you want to search for: "<<endl;
    getline(cin, Bookname);

    c1.searchBook(Bookname);
    
    c1.searchByPos(3);

    

    

  
 return 0;
}
