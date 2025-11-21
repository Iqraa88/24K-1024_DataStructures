#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    string table[50];   

public:

    int asciiSum(string s) {
        int sum = 0;
        for (char c : s)
            sum += int(c);
        return sum;
    }

    void Add_Employee(string name) {
        int sum = asciiSum(name);
        int h1 = sum % 50;
        int h2 = 7 - (sum % 7);

        int index = h1;

        int i = 1;
        while (table[index] != "" && table[index] != "DELETED") {
            index = (h1 + i * h2) % 50;
            i++;

            if (i > 50) {
                cout << "Hash table is full, cannot insert " << name << endl;
                return;
            }
        }

        table[index] = name;
        cout << "Inserted \"" << name << "\" at index " << index << endl;
    }

    void Search_Employee(string name) {
        int sum = asciiSum(name);
        int h1 = sum % 50;
        int h2 = 7 - (sum % 7);

        int index = h1;

        int i = 1;
        while (table[index] != "") {

            if (table[index] == name) {
                cout << "Employee \"" << name << "\" found at index " << index << endl;
                return;
            }

            index = (h1 + i * h2) % 50;
            i++;

            if (i > 50) break;
        }

        cout << "Employee not found in the directory." << endl;
    }


    void Display_Table() {
        cout << "\n--- EMPLOYEE DIRECTORY (Double Hashing Table) ---\n";
        for (int i = 0; i < 50; i++) {
            cout << "[" << i << "] : ";
            if (table[i] != "" && table[i] != "DELETED")
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.Add_Employee("Ali");
    ht.Add_Employee("Sara");
    ht.Add_Employee("Ahmed");
    ht.Add_Employee("Fatima");

    cout << endl;

    ht.Search_Employee("Sara");
    ht.Search_Employee("John");  
    cout << endl;

    ht.Display_Table();

    return 0;
}
