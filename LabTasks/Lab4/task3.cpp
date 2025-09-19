#include<iostream>
using namespace std;


void shellSort(int arr[], int n){


    for(int gap= n/2; gap>0; gap/=2){

        for(int j= gap; j<n; j++){

            int temp= arr[j];
            int res= j;

            while(res>=gap && arr[res-gap]>temp){

                arr[res]= arr[res-gap];
                res-=gap;
            }
            arr[res]= temp;
        }
    }
}

    void displayArray(int arr[], int size){
        for(int i=0; i<size; i++){
            
            cout<<arr[i]<<"  ";

    }
    cout<<endl;
}



int main(){

    int arr[10];
    for(int i=0; i<10; i++){
        cout<<"Enter Element "<< i+1<< " : "<<endl;
        cin>>arr[i];
    }
   
    cout<<"-------------Unsorted Array-----------"<<endl;
    displayArray(arr, 10);

    shellSort(arr, 10);
        cout<<"-------------Shell-Sorted Array-----------"<<endl;
    displayArray(arr,10);


    return 0;
}
