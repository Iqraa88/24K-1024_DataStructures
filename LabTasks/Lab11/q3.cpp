#include <iostream>
using namespace std;

class Hash {
private:
    int size;
    int *table;
    int EMPTY = -1;
    int DELETED = -2;

public:
    Hash(int s) {
        size = s;
        table = new int[size];

        for (int i = 0; i < size; i++)
            table[i] = EMPTY;
    }

    int hashFunction(int key) {
        return key % size;
    }

   
    void insert(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
                table[newIndex] = key;
                cout << "Inserted: " << key << " at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash Table Full! Cannot insert " << key << endl;
    }

 
    bool search(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex] == EMPTY) {
                return false; 
            }

            if (table[newIndex] == key) {
                cout << "Found at index " << newIndex << endl;
                return true;
            }
        }
        return false;
    }

    
    void deleteKey(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i) % size;

            if (table[newIndex] == EMPTY)
                break;

            if (table[newIndex] == key) {
                table[newIndex] = DELETED;
                cout << "Deleted: " << key << " from index " << newIndex << endl;
                return;
            }
        }

        cout << "Key not found: " << key << endl;
    }

    
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            if (table[i] == EMPTY)
                cout << i << " : EMPTY\n";
            else if (table[i] == DELETED)
                cout << i << " : DELETED\n";
            else
                cout << i << " : " << table[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    Hash h(10);

    h.insert(12);
    h.insert(22);
    h.insert(32);
    h.insert(5);

    h.display();

    h.search(22);
    h.search(100);

    h.deleteKey(22);
    h.display();

    return 0;
}
