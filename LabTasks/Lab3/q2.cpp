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
    
    bool searchBook(string bookTitle){
    
        temp= head;
        while(temp!=NULL){
        
            if(temp->bookName== bookTitle){
            
                return true;
            }
            temp= temp->next;
        }
        return false;
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

    if(c1.searchBook(Bookname)){
        cout<<"Your Book was found!"<<endl;
    }
    else{cout<<"Sorry! Couldn't find book!";}

    

  
 return 0;
}
