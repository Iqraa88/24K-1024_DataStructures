
#include<iostream>
using namespace std;

class ResearchPaper{

private:

string* authorsNames;
int totalAuthors;

public:

ResearchPaper(){

    cout<<"How many authors you want to add?"<<endl;
    cin>> totalAuthors;
    authorsNames= new string[totalAuthors];

    for(int i=0; i<totalAuthors; i++){
    cout<<"Enter Author "<< i+1<< " Name: "<<endl;
    cin>> authorsNames[i];
    cout<<"Success! :)"<<endl;
    }

}

~ ResearchPaper(){

    delete[] authorsNames;    
}

ResearchPaper(const ResearchPaper& obj){

totalAuthors= obj.totalAuthors;
authorsNames= new string[totalAuthors];

for(int i=0; i<totalAuthors; i++){
    authorsNames[i]= obj.authorsNames[i];

}

cout<<"Copied Successfully! :)"<<endl;

}

ResearchPaper& operator=(const ResearchPaper &obj){

    if(this!= &obj){
        delete[] authorsNames;
    totalAuthors= obj.totalAuthors;
    authorsNames= new string[totalAuthors];
    for(int i=0; i<totalAuthors; i++){
    
        authorsNames[i]= obj.authorsNames[i];
    
    }
}
else{return *this;}

}

void displayNames(){

    cout<<"The Authors Names are: "<<endl;
    for(int i=0; i<totalAuthors; i++){
    
        cout<<i+1<<". "<< authorsNames[i]<< endl;;
    }

}

};


int main()
{

    ResearchPaper r1;
    cout<<"-------------------------------"<<endl;
    cout<<" 'Research Paper 1"<<endl;
    r1.displayNames();

    ResearchPaper r2(r1);
    cout<<"-------------------------------"<<endl;
    cout<<" 'Research Paper 2"<<endl;
    r2.displayNames();

    ResearchPaper r3;
     cout<<"-------------------------------"<<endl;
    cout<<" 'Research Paper 3"<<endl;
    r3.displayNames();

    r1=r3;
     cout<<"-------------------------------"<<endl;
    cout<<" 'Research Paper 1 After Assignment Operator"<<endl;
    r1.displayNames();
    cout<<"R.P2 has still the same copy. "<<endl;
    r2.displayNames();



  
 return 0;
}