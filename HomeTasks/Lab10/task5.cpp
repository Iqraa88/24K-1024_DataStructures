#include<iostream>
using namespace std;


class MaxHeap{


    public:
    int heapArr[50];
    int cap;
    int size;

    MaxHeap(int cap){size=0; this->cap=cap;}

    int parent(int i){return (i-1)/2;}
    int leftChild(int i){return (2*i)+1;}
    int rightChild(int i){return (2*i)+2;}

    void insert(int key){
    
        if(size==cap){
        cout<<"Heap OverFlow!"<<endl;
        return;
        }

        heapArr[size]= key;
        size++;

        int i= size -1;
        
        while (i!=0 && heapArr[parent(i)]<heapArr[i]){
        
            swap(heapArr[i],heapArr[parent(i)]);
            i=parent(i);
        }

    }

    int removeMax(){
    
        if(size==0){
        cout<<"Heap is empty!"<<endl;
        return -1;
        }

        int root= heapArr[0];
        heapArr[0]= heapArr[size-1];
        size--;

        heapify(0);
        return root;
        
    }

    void heapify(int i){
    
        int largest=i;
        int left= leftChild(i);
        int right= rightChild(i);

        if(left<size && heapArr[left]>heapArr[largest]){
        largest=left;
        }
        if(right<size && heapArr[right]>heapArr[largest]){
        largest=right;
        }
        if(largest!=i){
        
            swap(heapArr[i],heapArr[largest]);
            heapify(largest);
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

    MaxHeap players(10);

    players.insert(1500);
    players.insert(1200);
    players.insert(1800);
    players.insert(1600);
 

    cout<<"Initialized Heap: "<<endl;
    players.display();

    players.insert(1700);
    cout<<"After Inserting 1700: "<<endl;
    players.display();

        cout<<"After Removing Max: "<<endl;
    players.removeMax();
    players.display();
  
 return 0;
}
