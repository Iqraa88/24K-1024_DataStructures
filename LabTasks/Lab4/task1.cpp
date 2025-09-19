#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
int count=0;
    for(int i=0; i<size; i++){

        for(int j=0; j<size-1; j++){

            if(arr[j]>arr[j+1]){

                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
                count++;
            }

        }
    }
    cout<<"Total Copmparisions: "<<count<<endl;
}

    void displayArray(int arr[], int size){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<"  ";

    }
}



int main(){

    int arr[7]={64, 34,25, 12, 22,11,90};
    bubbleSort(arr, 7);
    cout<<"------------After Sorting-------------- "<<endl;
    displayArray(arr, 7);


    return 0;
}
