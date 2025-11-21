#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = NULL;
    }
};


class HashTable {
    Node** table;   
    int bucketCount;

public:
    HashTable(int n) {
        bucketCount = n;
        table = new Node*[bucketCount];

        for (int i = 0; i < bucketCount; i++) {
            table[i] = NULL;
        }
    }

    int hashFunction(string key) {
        int sum = 0;
        for (char c : key)
            sum += int(c);
        return sum % bucketCount;
    }

    void insert(string key) {
        int index = hashFunction(key);

        Node* newNode = new Node(key);

      
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Inserted: " << key << " at bucket " << index << endl;
    }

    
    void display() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < bucketCount; i++) {
            cout << i << " --> ";
            Node* temp = table[i];

            if (!temp) {
                cout << "NULL";
            } else {
                while (temp) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};


int main() {
    HashTable ht(5); 

    ht.insert("apple");
    ht.insert("banana");
    ht.insert("cat");
    ht.insert("dog");
    ht.insert("apple");  
    ht.insert("mango");

    ht.display();

    return 0;
}
