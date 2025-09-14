#include<iostream>
using namespace std;

class Item{

    public:
    string name;
    double price;
    Item *next;

    Item(){
    
        name= "";
        price= 0;
        next= NULL;
    }

    Item(string item, double price){
    
       this->name= item;
       this->price= price;
        next= NULL;
    }
};
class ShoppingCart{

    public:

    Item *head;
    Item *tail;
    Item *temp;

    ShoppingCart(){
    
        head= tail= temp= NULL;

        addAtEnd(new Item("Laptop", 1000));
        addAtEnd(new Item("Phone", 700));
        addAtEnd(new Item("Tablet", 400));
        addAtEnd(new Item("HeadPhones", 150));

    }

    void addatFront(Item *i){
    
        if(head==NULL){
        
            head= tail= i;
            
        }

        else{
        
            i->next= head;
            head= i;

        }

    }

    void addAtEnd(Item *i){
    
        if(head==NULL){
        
            head=tail= i;
        }
        else{
        
            tail->next= i;
            tail= i;
        }
    }

    void insertAfterItem(string item, Item *newItem){
    
        if(head==NULL){
        
            head=tail=newItem;
        }
        else{
        
            temp=head;
            while(temp->name!=item){
            
                temp= temp->next;
            }
            newItem->next=temp->next;
            temp->next= newItem;
            cout<<"------Item: "<< newItem->name<< " Added after: "<< item<< " ------"<<endl;
        }
    }

    void searchByName(string itemName){
    
        if(head==NULL){
        
            cout<<" Empty Cart!"<<endl;
            return;
        }
        else{
        
            temp= head;
            bool found= false;
            while(temp!=NULL){
            
                if(temp->name==itemName){
                
                    found= true;
                    cout<<"Item: "<< temp->name<< " Exists."<<endl;
                    cout<<"The Price for your item is: "<< temp->price<< " $"<<endl;
                    break;
                }
                
                temp= temp->next; 
            }
            if(!found){
            
                cout<<" Couldn't find: "<< itemName<< " !"<<endl;
            }
        }
    }

    void displayCart(){
    
        temp= head;
        cout<<"---------Displaying Items in Cart-----------"<<endl;
        while(temp!=NULL){
        
            cout<<" "<<temp->name<< "  -  "<<temp->price<<" $"<<endl;
            temp=temp->next;
        }
        cout<<" No more items."<<endl;
    }
};


int main()
{

    ShoppingCart c1;
    cout<<"--------Adding Item at Front--------"<<endl;
    c1.addatFront(new Item("SmartWatch", 200));

    cout<<"--------Adding Item at End--------"<<endl;
    c1.addAtEnd(new Item("Keyboard", 80));

    cout<<"--------Inserting After --------"<<endl;
    c1.insertAfterItem("Phone",new Item("Monitor", 300));


    cout<<"--------Searching Item--------"<<endl;
    c1.searchByName("Tablet");
    cout<<"-----------------------------------------"<<endl;

    c1.displayCart();


    



  
 return 0;
}