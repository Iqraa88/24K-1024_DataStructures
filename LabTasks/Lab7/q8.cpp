#include <iostream>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    double totalPrice;
};


void quickSort(Order arr[], int left, int right) {
    if (left < right) {
        double pivot = arr[right].totalPrice;   
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j].totalPrice < pivot) {  
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[right]);          
        int pi = i + 1;                        

   
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

void displayOrders(Order arr[], int n) {
    cout << "Order List (Sorted by Total Price):" << endl;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Order ID: " << arr[i].orderID << endl;
        cout << "Customer Name: " << arr[i].customerName << endl;
        cout << "Total Price: $" << arr[i].totalPrice << endl;
        cout << "-------------------------------------------\n";
    }
}

int main() {
    Order orders[6] = {
        {1001, "Ali", 2500.50},
        {1002, "Sara", 1800.75},
        {1003, "Usman", 3200.00},
        {1004, "Hina", 1500.25},
        {1005, "Omar", 2900.00},
        {1006, "Zara", 2100.10}
    };

    cout << "Before Sorting (by total price):" << endl;
    for (int i = 0; i < 6; i++) {
        cout << orders[i].orderID << " - " << orders[i].customerName
             << " - $" << orders[i].totalPrice << endl;
    }

    quickSort(orders, 0, 5);

   
    displayOrders(orders, 6);

    return 0;
}
