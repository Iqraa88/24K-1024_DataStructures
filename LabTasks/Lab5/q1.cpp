#include<iostream>
#include<windows.h>
#include<cstdlib>  
using namespace std;

void guesseNumber (int n , int player) {
    int guess;
    cout<<"enter your guess"<<endl;
    cin >>guess;

    if ( n == guess) {
        cout<<"congrats now get lost"<<endl;
        return;
    }
    else if (n <guess) {
        cout<<"too highh nechai awoo"<<endl;

    }
    else {
        cout<<"bhuttt slowww..uper jw thorraaa"<<endl;
    }
    int nextPlayer =  (player == 1)? 2:1; 

    guesseNumber (n , nextPlayer);
}

int main(){

    int num= rand()%100+1;
    cout<<"chlo game shuru karain"<<endl;
    guesseNumber(num , 1);



    return 0;

}
