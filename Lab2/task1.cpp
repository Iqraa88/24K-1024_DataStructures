#include <iostream>
#include <vector>
using namespace std;

class OneDDynamicArray {
public:
    vector<int> data;

public:
   
    void push_back(int val) {
        data.push_back(val);
    }

   
    void print() {
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

 
    int getSize() {
        return data.size();
    }

   
    int getCapacity() {
        return data.capacity();
    }
};

int main() {
    OneDDynamicArray arr;
    arr.push_back(10);
    arr.push_back(22);
    arr.push_back(12);

    arr.print();

    cout << "Size: " << arr.getSize() << endl;
    cout << "Capacity: " << arr.getCapacity() << endl;


    arr.push_back(212);
    arr.push_back(167);
    arr.push_back(312);

    arr.print();

    cout << "Size: " << arr.getSize() << endl;
    cout << "Capacity: " << arr.getCapacity() << endl;

    return 0;
}