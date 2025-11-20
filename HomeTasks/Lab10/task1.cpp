#include<iostream>
using namespace std;

class MinHeap{


    public:
    int heapArr[50];
    int cap;
    int size;

    MinHeap(int cap){
    
        size=0;
        this->cap= cap;
    }

    int parent(int i){return (i-2)/2;}
    

    void insert(int key){
    
        if(size==cap){
        cout<<"Heap Overflow!"<<endl;
        return;
        }

        heapArr[size]= key;
        size++;

        int i=size-1;

        while (i!=0 && heapArr[parent(i)]>heapArr[i]){
        
            swap(heapArr[i],heapArr[parent(i)]);
            i=parent(i);
        }
      
    }

    void display(){
    
        for(int i=0; i<size; i++){
        
            cout<< heapArr[i]<< " ";

        }
        cout<< endl;
    }

};


int main()
{

    MinHeap heap(10);
    heap.insert(1);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
cout<<"Initialized Heap"<<endl;

    heap.display();

    heap.insert(2);
    cout<<"After Inserting Priority2 Package!"<<endl;
    heap.display();
  
 return 0;
}
