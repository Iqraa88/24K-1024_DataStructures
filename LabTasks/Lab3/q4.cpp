#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(){
    
        data= 0;
        next= NULL;
    }

};
class LinkedList{

    public:
    Node *head;
    Node* temp;
    Node *tail;

    LinkedList(){
    
        head= NULL;
        tail= NULL;
        temp= NULL;
    }

    void createLL(int size){
    
        for(int i=0; i<size; i++){
        Node *nn= new Node;
        cout<<"Enter Data: "<<endl;
        cin>> nn->data;

        if(head== NULL){
        head=nn;
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

    void sortLL(){
    
        Node *move= new Node;
        int  safeData;
        temp= head;
        while(temp!=NULL){
        move= temp->next;
        while(move!=NULL){
        
            if(temp->data > move->data){
            safeData= temp->data;
            temp->data= move->data;
            move->data= safeData;
                
            }
            move= move->next;
        }
        temp= temp->next;

        }
    }

    void concatLinkedLists(LinkedList &l1, LinkedList&l2){
    
        l1.tail->next= l2.head;
        head= l1.head;
        tail= l2.tail;
        

    }

    void middleElement(){
    
        Node *slow= head;
        Node *fast= head;

        while(fast!=NULL && fast->next!=NULL){
        
            slow= slow->next;
            fast= fast->next->next;

        }

        cout<<"The middle element is: "<< slow->data<< " ."<<endl;
    }

    void delDuplicates(int num){
    
        Node *prev= new Node;
        temp= head;
        while(temp!=NULL){
        
            if(temp->data== num){
                if(temp==head){
                
                    temp= head->next;
                    delete head;
                    head= temp;
                }
                else{
                    prev->next= temp->next;
                    delete temp;
                    temp= prev->next;
                

                }
            

            }
            else{
            
             prev= temp;
            temp= temp->next;
            }
        }
        

    
    }

    void mergeSortedLL(LinkedList &l1, LinkedList &l2){
    
        concatLinkedLists(l1, l2);
        sortLL();
        
    }

    void display(){
    
        temp=head;
        while(temp!=NULL){
        
            cout<<temp->data<< " -> ";
            temp=temp->next;
        }

        cout<< "end"<<endl;
    }

};
int main()
{

    LinkedList l1;
    l1.createLL(4);
    cout<< "LinkedList1 Creation Success!"<<endl;
    l1.display();
    cout<<"------------------------------"<<endl;
    l1.sortLL();
    cout<<"----Sorted LinkedList1----"<<endl;
    l1.display();

    LinkedList l2;
    l2.createLL(4);
    cout<< "LinkedList2 Creation Success!"<<endl;
    l2.display();
        cout<<"------------------------------"<<endl;
    l2.sortLL();
        cout<<"----Sorted LinkedList2----"<<endl;
    l2.display();

    LinkedList l3;
    l3.concatLinkedLists(l1,l2);
    cout<<"Concatenated Linked Lists: "<<endl;
    l3.display();

    l3.mergeSortedLL(l1, l2);
     cout<<"Merged & Sorted Linked Lists: "<<endl;
    l3.display();
    l3.delDuplicates(2);

    l3.display();
    l3.middleElement();
  
 return 0;
}
