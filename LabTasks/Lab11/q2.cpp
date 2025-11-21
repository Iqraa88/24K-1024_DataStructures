#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string word;
    Node* next;

    Node(string w) {
        word = w;
        next = NULL;
    }
};

class Dictionary {
private:
    Node* table[100]; 

  
    int hashFunction(string key) {
        int sum = 0;
        for(char c : key) {
            sum += int(c);
        }
        return sum % 100;
    }

public:
    Dictionary() {
        for (int i = 0; i < 100; i++)
            table[i] = NULL;
    }

   
    void Add_Record(string word) {
        int index = hashFunction(word);
        Node* newNode = new Node(word);

      
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Added \"" << word << "\" at bucket " << index << endl;
    }

  
    void Word_Search(string key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp) {
            if (temp->word == key) {
                cout << "Word \"" << key << "\" found at bucket " << index << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Error: Word \"" << key << "\" not found!" << endl;
    }

   
    void Print_Dictionary() {
        cout << "\n--- ASCII Dictionary Contents ---\n";
        for (int i = 0; i < 100; i++) {
            cout << i << ": ";

            if (!table[i]) {
                cout << "NULL\n";
                continue;
            }

            Node* temp = table[i];
            while (temp) {
                cout << temp->word << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};


int main() {
    Dictionary dict;

  
    dict.Add_Record("apple");
    dict.Add_Record("cat");
    dict.Add_Record("banana");
    dict.Add_Record("dog");
    dict.Add_Record("hello");

    cout << endl;

   
    dict.Word_Search("cat");
    dict.Word_Search("mango");

    cout << endl;


    dict.Print_Dictionary();

    return 0;
}
