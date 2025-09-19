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

int interpolationSearch(int arr[], int n, int search) {
    int left=0, right=n-1;

    while(left<=right && search>=arr[left] && search<=arr[right]) {

        if(left==right) {
            if(arr[left]==search) return left;
            return -1;
        }

        int pos = left + ((double)(right-left)/(arr[right]-arr[left]))*(search-arr[left]);

        if(arr[pos]==search) 

        {
            return pos;
        }
        if(arr[pos]<search)
        {
             left=pos+1;
        }
        else
        { 
            right=pos-1;
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

     int arr[8] = {45, 12, 78, 23, 89, 34, 67, 10};


    bubbleSort(arr,8);
    cout<<"-----------Sorted array------------";
    for(int i=0;i<8;i++){
    
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    cout<<"--------------------------------------"<<endl;

int search = 34;
    int result=interpolationSearch(arr,8,search);
    if(result==-1)
    { cout<<"Element "<<search<<" not found"<<endl;
    }

    else {
    cout<<"Element "<<search<<" found at index "<<result<<endl;
    }


    return 0;
}
