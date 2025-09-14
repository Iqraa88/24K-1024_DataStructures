#include<iostream>
using namespace std;

class Ticket{

    public:

    int id;
    string name;
    string ride;
    Ticket *next;

    Ticket(int id, string name, string ride){
    
        this->id= id;
        this->name= name;
        this->ride= ride;
        next= NULL;
    }

};
class Booking{

    public:

    Ticket *head;
    Ticket *tail;
    Ticket *temp;

    Booking(){
    
        head=tail=temp= NULL;
    }

    void issueAtEnd(Ticket *t){
    
        if(head==NULL){
        
            head=tail= t;
            tail->next= head;
        }
        else{
        
            tail->next= t;
            tail= t;
            t->next= head;
        }

        cout<<"New Ticket Added."<<endl;
    }

    void issueAtFirst(Ticket *t){
        
        if(head== NULL){
        
            head=tail= t;
            tail->next= head;
        }
        else{
        
            t->next= head;
            head= t;
            tail->next=head;
        }
        cout<<"VIP Ticket Added."<<endl;


    }

    void cancelTicketByID(int id){
    
        if(head==NULL){
            cout<<"No tickets issued currently."<<endl;
            return;
        }
        else{
            Ticket *prev= tail;
            bool flag= false;
            temp= head;
            do{
                if(temp->id==id){
                flag= true;
                if(temp== head){
                temp= head->next;
                delete head;
                head= head->next;
                tail->next= head;

                }
                else if(temp==head && temp==tail){
                
                    head=tail= NULL;
                }
                else if(temp==tail){
                
                    prev->next= head;
                    delete tail;
                    tail= prev;
                }
                else{
                
                    prev->next= temp->next;
                    delete temp;
                    temp= prev->next;
                }
                cout<<"Ticket with ID: "<< temp->id<< " was deleted."<<endl;
                break;
                }
                prev=temp;
                temp=temp->next;
            }
            while(temp!=head);
            if(!flag){
            cout<<"Couldn't find the ID to delete."<<endl;
            return;
            }
        }
    }

    void cancelFirstTicket(){
    
        if(head==NULL){
        cout<<"No tickets issued currently!"<<endl;
        return;
        }
        else{
        
            temp= head->next;
            delete head;
            head=temp;
            tail->next= head;

            cout<<"First Ticket deleted."<<endl;
        }
    }

    void searchTicket(int id){
    
        if(head==NULL){
            cout<<"No tickets to show."<<endl;
            return;
        }
        else{
            bool flag= false;
            temp=head;
            do{
                if(temp->id== id){
                    flag=true;
                    cout<<"Ticket Found: "<<endl;
                    cout<< " | Ticket ID: "<< temp->id<< " - Customer Name: "<< temp->name<< " - Ride: "<< temp->ride<< "  |"<<endl;
                    break;
                }
                temp= temp->next;
            }while(temp!=head);

            if(!flag){
            cout<<"No result found for your searched ID."<<endl;
            }
        }
    }

    void displayTickets(){
    
        if(head==NULL){
            cout<<"No tickets to show."<<endl;
            return;
        }
        else{
        temp=head;
        do{
        
        cout<< " | Ticket ID: "<< temp->id<< " - Customer Name: "<< temp->name<< " - Ride: "<< temp->ride<< "  |"<<endl;
            temp= temp->next;
        }while(temp!=head);

        cout<< "back to first ticket"<<endl;
        }

    }

    int countTickets(Ticket *t){
    
        if(head==NULL){
        return 0;
        }
        
        
            if(t->next== head){
            return 1;
            }
            return 1+ countTickets(t->next);  
    }

    void findNextTicket(int id){
     bool found= false;
        if(head==NULL){
            cout<<"No tickets to show."<<endl;
            return;
        }
        do{
           
            temp=head;
            if(temp->id== id){
                
                cout<<"Customer-> "<< temp->next->name<< " with TicketID: "<< temp->next->id<< " is next in the line."<<endl;
                found= true;
            break;
            }

            temp=temp->next;
        }while(temp!=head);

        if(!found){
        cout<<"No result for your desired id was found. "<<endl;
        cout<<"Couldn't retrieve next customer's info.... Failed!"<<endl;
        }
        
    }
};


int main()
{

    Booking b;
    int choice,id;
    string name, ride;

    while(true){
        cout<<"--- Ticket Booking System ---"<<endl;
        cout<<"1. Issue Ticket at End"<<endl;
        cout<<"2. Issue VIP Ticket (Front)"<<endl;
        cout<<"3. Cancel Ticket by ID"<<endl;
        cout<<"4. Cancel First Ticket"<<endl;
        cout<<"5. Search Ticket by ID"<<endl;
        cout<<"6. Display All Tickets"<<endl;
        cout<<"7. Count Tickets"<<endl;
        cout<<"8. Find Next Customer"<<endl;
        cout<<"9. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter ID, Name, Ride: ";
                cin>>id>>name>>ride;
                b.issueAtEnd(new Ticket(id,name,ride));
                break;
            case 2:
                cout<<"Enter ID, Name, Ride: ";
                cin>>id>>name>>ride;
                b.issueAtFirst(new Ticket(id,name,ride));
                break;
            case 3:
                cout<<"Enter Ticket ID to cancel: ";
                cin>>id;
                b.cancelTicketByID(id);
                break;
            case 4:
                b.cancelFirstTicket();
                break;
            case 5:
                cout<<"Enter Ticket ID to search: ";
                cin>>id;
                b.searchTicket(id);
                break;
            case 6:
                b.displayTickets();
                break;
            case 7:
                cout<<"Total Tickets: "<< b.countTickets(b.head)<<endl;
                break;
            case 8:
                cout<<"Enter Ticket ID to find next: ";
                cin>>id;
                b.findNextTicket(id);
                break;
            case 9:
                cout<<"Exiting program..."<<endl;
                return 0;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }
  
 return 0;
}