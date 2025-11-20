#include <iostream>

using namespace std;

class MinHeap {
public:
    int heap[100];
    int size;
    int cap;
    
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    MinHeap(int cap) {
    
        size=0;
        this->cap=cap;
    }
    
    void insert(int price) {
        if(size==cap){cout<<"Heap Overflow!"<<endl;}
        heap[size] = price;
        
        int i = size;
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        
        size++;
    }
    
    void removeMin() {
        if (size == 0) 
        {return;}
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
    
    void display() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap orders(10);
    
    cout<<"Initializing Heap: "<<endl;

    orders.insert(100);
    orders.insert(50);
    orders.insert(75);
    orders.insert(60);
    orders.display();
    
    cout << " After inserting 55: ";
    orders.insert(55);
    orders.display();
    
    cout << " After removing highest priority: ";
    orders.removeMin();
    orders.display();
    
    return 0;
}
