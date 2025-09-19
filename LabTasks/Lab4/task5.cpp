#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){

    for(int i=0; i<size; i++){

        for(int j=0; j<size-1; j++){

            if(arr[j]>arr[j+1]){

                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            
            }

        }
    }
    
}

int binarySearch(int arr[], int n, int search) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (arr[mid] == search) {
        return mid;
    }

        else if (arr[mid] < search)
        {
             left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}


    void displayArray(int arr[], int size){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<"  ";

    }
}



int main(){

   int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<< i+1<< " :"<<endl;
        cin>> arr[i];
    }
    
    bubbleSort(arr, n);
    displayArray(arr, n);
    int index= binarySearch(arr, n, 4);
    cout<<" Your searched element was found at index: "<< index<< "!";



    return 0;
}
