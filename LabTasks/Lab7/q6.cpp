#include <iostream>
#include <string>
using namespace std;


class Employee {
    public:
    string name;
    int id;
    double salary;
};


void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

   
    while (i < n1 && j < n2) {
        if (L[i].salary > R[j].salary) {
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


void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void displayTop3(Employee arr[], int n) {
    cout << "\n Top 3 Highest Paid Employees:\n";
    cout << "----------------------------------------\n";
    cout << "Rank\tName\t\tID\tSalary\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < 3 && i < n; i++) {
        cout << (i + 1) << "\t" << arr[i].name << "\t\t" 
             << arr[i].id << "\t" << arr[i].salary << endl;
    }
}

int main() {
    Employee employees[12] = {
        {"Ali", 101, 75000},
        {"Sara", 102, 82000},
        {"Bilal", 103, 64000},
        {"Fatima", 104, 95000},
        {"Omar", 105, 72000},
        {"Hina", 106, 87000},
        {"Zain", 107, 66000},
        {"Ayesha", 108, 99000},
        {"Usman", 109, 61000},
        {"Nida", 110, 78000},
        {"Danish", 111, 88000},
        {"Amir", 112, 70000}
    };

    int n = 12;

    cout << "Before Sorting (by salary):\n";
    for (int i = 0; i < n; i++)
        cout << employees[i].name << "\t" << employees[i].id << "\t" << employees[i].salary << endl;

    
    mergeSort(employees, 0, n - 1);

    cout << "\nAfter Sorting (Descending by Salary):\n";
    for (int i = 0; i < n; i++)
        cout << employees[i].name << "\t" << employees[i].id << "\t" << employees[i].salary << endl;

   
    displayTop3(employees, n);

    return 0;
}
