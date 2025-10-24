#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;


int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

  
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

   
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void displayRanks(int arr[], int n) {
    cout << " Sorted Scores with Ranks:"<<endl;
    cout << "---------------------------------"<<endl;
    for (int i = n - 1, rank = 1; i >= 0; i--, rank++) {
        cout << "Rank " << rank << " : " << arr[i] << endl;
    }
}

int main() {
    srand(time(0));

    const int n = 50;
    int scores[n];

    for (int i = 0; i < n; i++)
        scores[i] = rand() % 101;

    cout << "Original Scores: "<<endl;
    for (int i = 0; i < n; i++)
        cout << scores[i] << " ";
    cout << "---------------------------------"<<endl;
   
    radixSort(scores, n);

   
    displayRanks(scores, n);

    return 0;
}
