#include <iostream>
#include <string>

using namespace std;

class Task {
    public:
    
    string name;
    int priority;
    
    Task() : name(""), priority(0) {}
    Task(string n, int p) : name(n), priority(p) {}
};

class MaxHeap {
public:

    Task* heap;
    int capacity;
    int size;

     MaxHeap() {
        capacity = 10;
        size = 0;
        heap = new Task[capacity];
    }

       void resize() {
        capacity *= 2;
        Task* newHeap = new Task[capacity];
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)].priority < heap[index].priority) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
    
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < size && heap[left].priority > heap[largest].priority) {
            largest = left;
        }
        
        if (right < size && heap[right].priority > heap[largest].priority) {
            largest = right;
        }
        
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
 

    
    void insert(const string& name, int priority) {
        if (size == capacity) {
            resize();
        }
        
        heap[size] = Task(name, priority);
        heapifyUp(size);
        size++;
        
        cout << "Inserted: " << name << "(" << priority << ")" << endl;
    }
    
    Task removeMax() {
        if (size == 0) {
           cout<<"Heap is empty!"<<endl;
        }
        
        Task maxTask = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        
        cout << "Removed highest priority task: " << maxTask.name << "(" << maxTask.priority << ")" << endl;
        return maxTask;
    }

       ~MaxHeap() {
        delete[] heap;
    }
    
    void display() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        for (int i = 0; i < size; i++) {
            cout << heap[i].name << "(" << heap[i].priority << ")" << "  ";
            
        }

        cout << endl;
    }
        
      
};

int main() {
    MaxHeap taskHeap;
    

    
   
    taskHeap.insert("A", 5);
    taskHeap.insert("B", 3);
    taskHeap.insert("C", 8);
    taskHeap.display();
 
    
    
    Task removed = taskHeap.removeMax();
    taskHeap.display();
   
    

    cout << "Inserting new task D(6):" << endl;
    taskHeap.insert("D", 6);
    taskHeap.display();
    
    return 0;
}
