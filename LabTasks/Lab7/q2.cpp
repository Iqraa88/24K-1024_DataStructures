#include <iostream>
#include <string>
using namespace std;


class Runner {
    public:
    string name;
    int time;  
};


void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

   
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) {
            arr[k] = L[i];
            i++;
        } else { 
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void displayTop5(Runner arr[], int n) {
    cout << "\n Top 5 Fastest Runners:\n";
    cout << "-----------------------------------\n";
    cout << "Rank\tName\t\tTime (sec)\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < 5 && i < n; i++) {
        cout << (i + 1) << "\t" << arr[i].name << "\t\t" << arr[i].time << endl;
    }
}

int main() {
   
    Runner runners[10] = {
        {"Maha", 320},
        {"Amna", 295},
        {"Fabiha", 310},
        {"Zara", 280},
        {"Afsa", 360},
        {"Fatima", 270},
        {"Ramal", 330},
        {"Iqra", 300},
        {"Maham", 290},
        {"Ayesha", 305}
    };

    int n = 10;

    cout << "Before Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << runners[i].name << "\t" << runners[i].time << " sec\n";

    
    mergeSort(runners, 0, n - 1);

    cout << "\nAfter Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << runners[i].name << "\t" << runners[i].time << " sec\n";

    displayTop5(runners, n);

    return 0;
}
