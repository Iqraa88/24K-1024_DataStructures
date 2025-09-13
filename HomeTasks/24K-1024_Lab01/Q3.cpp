#include<iostream>
using namespace std;

class Exam{

private:

int *marks;

public:

Exam(int m){

    marks= new int(m);
}

void showMarks(){
cout<<"Marks: "<< *marks<< " "<< endl;

}

void changeMarks(int newMarks){

    *marks= newMarks;
}


};
int main()
{

    Exam e1(90);
    cout<<"-------------For Exam1---------------"<<endl;
    e1.showMarks();
    Exam e2(e1);
    cout<<"-------------For Exam2---------------"<<endl;
    e2.showMarks();
    e2.changeMarks(85);
    cout<<"------------- After Changing Marks, Exam2---------------"<<endl;
    e2.showMarks();
    cout<<"------------- After Changing Marks, Exam1 (Shallow Copy Issue)---------------"<<endl;
    e1.showMarks();



  
 return 0;
}