#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int size){
    int count=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(arr[j]>arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
            count++; 
        }
    }
    cout<<"Total Comparisions: "<<count<<endl;
}

void selectionSort(int arr[], int size){
    int count=0;
    for(int i=0; i<size-1; i++){
        int min=i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min]){
                min= j;
            }
            count++; 
        }
        int temp= arr[i];
        arr[i]= arr[min];
        arr[min]= temp;
    }
    cout<<"Total Comparisions: "<< count<<endl;
}

void shellSort(int arr[], int n){
    int count=0;
    for(int gap= n/2; gap>0; gap/=2){
        for(int j= gap; j<n; j++){
            int temp= arr[j];
            int res= j;
            while(res>=gap && arr[res-gap]>temp){
                arr[res]= arr[res-gap];
                res-=gap;
                count++;
            }
            arr[res]= temp;
        }
    }
    cout<<"Total Comparisions: "<< count<<endl;
}

void insertionSort(int arr[], int size){
    int count=0;
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
            count++;
        }
        arr[j+1] = key;
    }
    cout<<"Total Comparisions: "<<count<<endl;
}

void displayArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void generateRandomArray(int arr[], int size){
    for(int i=0; i<size; i++){
        arr[i] = rand()%100 + 1;  
    }
}

int main(){
    srand(time(0));
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int* arr = new int[n];

   
    generateRandomArray(arr, n);
    cout<<"----------Using Bubble-Sort------------"<<endl;
    displayArray(arr, n);
    bubbleSort(arr, n);
    displayArray(arr, n);

  
    generateRandomArray(arr, n);
    cout<<"----------Using Selection-Sort------------"<<endl;
    displayArray(arr, n);
    selectionSort(arr, n);
    displayArray(arr, n);

   
    generateRandomArray(arr, n);
    cout<<"----------Using Insertion-Sort------------"<<endl;
    displayArray(arr, n);
    insertionSort(arr, n);
    displayArray(arr, n);

    
    generateRandomArray(arr, n);
    cout<<"----------Using Shell-Sort------------"<<endl;
    displayArray(arr, n);
    shellSort(arr, n);
    displayArray(arr, n);

    delete[] arr;
    return 0;
}
