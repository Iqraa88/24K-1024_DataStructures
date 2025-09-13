#include<iostream>
#include<windows.h>
using namespace std;

class Song{

    public:
    string songTitle;
    Song *next;

    Song(){
    
        songTitle= "";
        next= NULL;
    }

    Song(string title){
    
        songTitle= title;
        next= NULL;
    }

};
class Playlist{

    public:
    Song *head;
    Song *tail;
    Song *temp;

    Playlist(){
    
        head= NULL;
        tail= NULL;
        temp= NULL;
    }

    void addSongAtEnd(){
    
        Song *s=new Song;
        cout<<"Enter song you would like to add?"<<endl;
        getline(cin, s->songTitle);

        if(head== NULL){
        
            head=tail=s;
            tail->next= head;

        }
        else{
        
            tail->next= s;
            tail= s;
            s->next= head;
        }
    }


    void deleteSong(string title){
    
        Song *prev= tail;
        if(head!=NULL){
        
            temp= head;
            do{
            
                if(temp->songTitle==title){
                
                    if(temp== head && temp== tail){
                    
                        head= NULL;
                        tail= NULL;
                    }
                    else if(temp== head){
                    
                        head= head->next;
                        tail->next= head;
                    }
                    else if(temp== tail){
                        tail= prev;
                        tail->next= head;
                        
                    }
                    else{
                    
                        prev->next= temp->next;
                        
                        
                    }
                    delete temp;
                    cout<<"Song: "<< title<< " Deleted!"<<endl;
                    return;

                }
                prev= temp;
                temp= temp->next;


            }while(temp!=head);

            cout<<"Song not found!"<<endl;
            

            
        }
        else{
        
            cout<<"hehe, empty list. nothing to delete!"<<endl;
        }
    }
    void displayPlaylist(){
    
        if(head!=NULL){
        
            temp= head;
           do{
            cout<< " - "<<  temp->songTitle<< " "<< endl;
            temp= temp->next;

            } while(temp!=head);

            cout<<" back to head <- ";
            cout<<endl;
             
        }
        else{
        
            cout<<" hehe, nothing to show in your playlist.. add songs first!"<<endl;
            return;
        }
    }


    void searchSong(string title){
    
        bool found= false;
        if(head!=NULL){
        
            temp= head;
            do{
                if(temp->songTitle== title){
                    found= true;
                    cout<<"Song Found. You searched for: "<< temp->songTitle<< " :)"<<endl;
                    break;

                }
                else{
                temp= temp->next;
                }
            }while(temp!=head);

            if(!found){
            
                cout<<" Couldn't find: "<< title<< " . There might be spelling errors or try adding song first!"<<endl;
            }
        }
        else{
        
            cout<<"hehe, your playlist is empty. "<<endl;
            return;
        }
    }

    void playSong(){
                    string choice;


        if(head!=NULL){
        
            temp= head;
            do{
                
                cout<<"Now Playing: "<< temp->songTitle<< " "<<endl;
                 Sleep(3000); // bas aise hi 
                temp= temp->next;
            }while(temp!=head);

            cout<<"Back to first song again!"<<endl;
            cout<<"=========================="<<endl;
            cout<<"Do you want to play from the start again?"<<endl;
            cin>> choice;
            if(choice== "YES"|| choice=="yes"){playSong();}
            else{return;}
        }
        else{
        
            cout<<" hehe, empty playlist. now what to play? Add some songs dude!"<<endl;
        }
    }

};


int main()
{

    Playlist p1;
    int choice;
    string title;

    do{
        cout<<"---- Playlist Manager ----"<<endl;
        cout<<"1. Add Song at End"<<endl;
        cout<<"2. Remove Song"<<endl;
        cout<<"3. Search Song By Title"<<endl;
        cout<<"4. Display Playlist"<<endl;
        cout<<"5. Play Song"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
                p1.addSongAtEnd();
                break;
            case 2:
            cout<<"Enter Song you wanna delete? "<<endl;
            getline(cin, title);
                p1.deleteSong(title);
                break;
            case 3:
                cout<<"Enter song to search: ";
                cout<<"Enter Song you are looking for? "<<endl;
            getline(cin, title);
                p1.searchSong(title);
                break;
            case 4:
                p1.displayPlaylist();
                break;
            case 5:
            
                p1.playSong();
                break;
            case 6:
                cout<<"Exiting program..."<<endl;
                break;
            default:
                cout<<"Invalid choice jee!! :)."<<endl;
        }
    }
    while(choice != 6);


  
 return 0;
}
