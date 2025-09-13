#include<iostream>
using namespace std;

class Box{

    private:

    int *volume;

    public:

    Box(){
    
        volume= new int(0);
        cout<<"Box Created!"<<endl;
    }

    Box(int inputVol){
    
        volume= new int(inputVol);
        cout<<"Box Created!"<<endl;

    }

    Box(const Box& obj){
    
        volume= new int(*obj.volume);
    
    }

    void changeVolume(int newVol){
    
        *volume= newVol;
    }

    void displayVolume(){
    
        cout<<"Volume is: "<< *volume<<endl;
    
    }

};


int main()
{
    Box b1;
     cout<<"-------------------------------"<<endl;
    cout<<" 'Box 1' "<<endl;
    b1.displayVolume();

    Box b2(1000);
     cout<<"-------------------------------"<<endl;
    cout<<" 'Box 2' "<<endl;
    b2.displayVolume();

    Box b3(b2);
    cout<<"-------------------------------"<<endl;
    cout<<" Box 3 Before Changing Volume: "<<endl;
    b3.displayVolume();
    b3.changeVolume(1500);
      cout<<" Box 3 After Changing Volume: "<<endl;
    b3.displayVolume();
      cout<<" Box 2 After Changing Volume of Box 3 (Unaffected): "<<endl;
    b2.displayVolume();

  
 return 0;
}