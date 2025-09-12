#include<iostream>
using namespace std;



int main(){

    int teams;
    cout<<"How many teamss you want?"<<endl;
    cin>> teams;

    int **scores= new int *[teams];
    int *teamSize= new int[teams];

    for(int i=0; i<teams; i++){

        cout<<"How many scores of team " << i+1<< " you want to add? :"<<endl;
        cin>> teamSize[i];

        scores[i]= new int[teamSize[i]];

    }

    for(int i=0; i< teams; i++){
        cout<<"Enter " <<teamSize[i]<<" scores for Team "<< i+1 << " : "<<endl;
        for(int j=0; j< teamSize[i]; j++){

            cin>> scores[i][j];
        }
       
    }

 
cout << "\n---------- Team Scores ----------\n";
for (int i = 0; i < teams; i++) {
    int total = 0;
    for (int j = 0; j < teamSize[i]; j++) {
        total += scores[i][j];
    }
    cout << "Team " << i + 1 << " Total = " << total << endl;
    cout << "-----------------------" << endl;
}

    for(int i=0; i<teams; i++){

        delete[] scores[i];
    }

    delete[] scores;
    delete[] teamSize;

    return 0;
}

