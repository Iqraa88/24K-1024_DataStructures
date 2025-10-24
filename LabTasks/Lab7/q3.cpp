#include<iostream>
using namespace std;

class Product{
    public:

    string name;
    double price;
    string descrip;
    string available;


};


void quickSort(Product arr[], int left, int right) {
    if (left < right) {
      
        double pivot = arr[right].price;   
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j].price < pivot) {   
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

void displayProducts(Product arr[], int n) {
    cout << " Product List (Sorted by Price): "<<endl;
    cout << "-------------------------------------------"<<endl;

    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name << endl;
        cout << "Price: $" << arr[i].price << endl;
        cout << "Description: " << arr[i].descrip << endl;
        cout << "Availability: " << arr[i].available << endl;
        cout << "-------------------------------------------\n";
    }
}



int main(){

 Product products[3] = {
        {"Laptop", 950.50, "High performance laptop with 16GB RAM", "In Stock"},
        {"Headphones", 120.00, "Wireless noise-cancelling headphones", "In Stock"},
        {"Smartwatch", 250.75, "Water-resistant smartwatch with GPS", "Out of Stock"}
    };

    cout << "Before Sorting (by price):\n";
    for (int i = 0; i < 3; i++) {
        cout << products[i].name << " - $" << products[i].price << endl;
    }

    quickSort(products, 0, 2);

    
    displayProducts(products, 3);


    return 0;
}
