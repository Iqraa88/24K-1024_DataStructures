#include<iostream>
using namespace std;

class Item{

    public:
    int itemID;
    string itemName;
    double price;
    Item *next;
    Item *prev;

    Item(int id, string name, double p){
        itemID= id;
        itemName= name;
        price= p;
        next=prev= NULL;
    }
};

class ShoppingCart{

    public:
    Item *head;
    Item *tail;
    Item *temp;

    ShoppingCart(){
        head=tail=temp= NULL;
    }

    void insertAtEnd(Item *newItem){
    
        if(head==NULL){
        
            head=tail= newItem;

        }
        else{
        
            tail->next= newItem;
            newItem->prev= tail;
            tail= newItem;
        }

          cout<<"Item Added at end."<<endl;

    }


    void insertAtFront(Item *newItem){
    
        if(head==NULL){
        
            head=tail=newItem;
        }
        else{
        
            head->prev= newItem;
            newItem->next= head;
            head= newItem;
        }
         cout<<"Item Added at front for urgent reasons."<<endl;

    }

    void removeFirstItem(){
    
        if(head==NULL){
        
            cout<<"kuch nahi hai cart mein, kya delete kroge?"<<endl;
            return;
        }
        else if(head==tail){
        
            head=tail= NULL;
        }
        else{
        
            head->next->prev= NULL;
            temp= head->next;
            delete head;
            head= temp;
        }

        cout<<" First Item Deleted!"<<endl;
    }

    void removeLastItem(){
    
        if(head==NULL){
        cout<<"kuch nahi hai bhai, kya delete kroge?"<<endl;
        return;
        }
        else if(head== tail){
        head=tail=NULL;
        }
        else{
        tail->prev->next= NULL;
        temp= tail->prev;
        delete tail;
        tail= temp;
        }

        cout<<" Last Item Deleted!"<<endl;

    }

    Item* searchById(int id){
    
          if(head==NULL){
        
            cout<<"kuch nahi hai cart mein, kya delete kroge?"<<endl;
            return NULL;
        }
        else{
        
            temp= head;
            bool flag=false;
            while(temp!=NULL){
            
                if(temp->itemID==id){
                flag=true;
                cout<<"Item holding ID:  "<< temp->itemID<< " found: "<<endl;
                cout<< "| Item Name: "<< temp->itemName<< " - Price: "<< temp->price<< " $. |"<<endl;
                return temp;
                }
                temp=temp->next;
            }
            if(!flag){
            cout<<"nahi mila bhai kch bhe, allah hafiz."<<endl;
            return NULL;
            }
        }
        
    }

    void updatePrice(int itemID){
    
        Item *update= searchById(itemID);

        if(update!=NULL){
        
            cout<<"The Old price for item# "<<itemID<< " is: "<< update->price<< " $."<<endl;
            cout<<"Enter the new price: "<<endl;
            double newPrice;
            cin>> newPrice;
            update->price= newPrice;
            cout<<"Price Updated!"<<endl;

        }
        else{
        return;
        }
        
    }

    void displayFromStart(){
    

        temp= head;
        cout<<"Displaying Items in your cart (Start->End)"<<endl;
        while(temp!=NULL){
        
            cout<<"| Item: "<< temp->itemName<< " - Price: $"<< temp->price<< " - ID: "<<temp->itemID<< "  |"<<endl;
            temp=temp->next;
        }
        cout<<"No more items in cart."<<endl;
    }

    void displayFromEnd(){
    
        
        temp= tail;
        cout<<"Displaying Items in your cart (End->Start)"<<endl;
       
        while(temp!=NULL){
        
           cout<<"| Item: "<< temp->itemName<< " - Price: $"<< temp->price<< " - ID: "<<temp->itemID<< "  |"<<endl;
            temp= temp->prev;

        }
        cout<<"No more items in cart."<<endl;
    }

    int countItems(Item *count){
    
        if(count==NULL){return 0;}

         return 1+ countItems(count->next);
        
    }

    void expensiveItem(){
    
        if(head==NULL){
        cout<<"Cart Empty!"<<endl;
        return;
        }
        else{
        temp= head;
        Item *highPrice= head;
        while(temp!=NULL){
        if(temp->price > highPrice->price){
        
            highPrice= temp;
        }
        temp=temp->next;
        }
        cout<<"The Item with highest price in your cart is: "<<endl;
         cout<<"| Item: "<< highPrice->itemName<< " - Price: $"<< highPrice->price<< " - ID: "<<highPrice->itemID<< "  |"<<endl;
    }
        
    }
};


int main()
{
    ShoppingCart cart;
    cart.insertAtEnd(new Item(101, "Laptop", 1500));
    cart.insertAtEnd(new Item(102, "Headphones", 40));
    cart.insertAtEnd(new Item(103, "Smartphone", 80));

    cart.insertAtFront(new Item(100, "Charger", 25));

    cout << "----------------------------------"<<endl;
    cart.displayFromStart();

    cout << "----------------------------------"<<endl;
    cart.displayFromEnd();

    cout << "----------------------------------"<<endl;
    cart.searchById(102); 
    cart.searchById(200);  

    cout << "----------------------------------"<<endl;
    cart.updatePrice(103);

    cout << "----------------------------------"<<endl;
    cart.displayFromStart();

    cout << "----------------------------------"<<endl;

    cart.removeFirstItem();
    cart.removeLastItem();

    cout << "----------------------------------"<<endl;
    cart.displayFromStart();

    cout << "----------------------------------"<<endl;
    cout << "Total items in cart: " << cart.countItems(cart.head) << endl;

    cout << "----------------------------------"<<endl;
    cart.expensiveItem();


    
  
 return 0;
}