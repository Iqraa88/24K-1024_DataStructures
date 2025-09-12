#include<iostream>
using namespace std;

class TwoDimensionalArray{

    private:
    int **arr;
    int r;
    int c;


    public:
    TwoDimensionalArray(int r, int c){
    
        this->r=r;
        this->c= c;

        arr= new int*[r];
        for(int i=0; i<r; i++){
        
            arr[i]= new int[c];
        }
    }

    void destroyMem(){
    
        for(int i=0; i<r; i++){
        delete[] arr[i];
        }

        delete[] arr;
    }

    void inputArr(){
    
        for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
        cout<<"Enter element at row "<< i+1<< " and column "<< j+1<< " :"<<endl;
        cin>> arr[i][j];
        }
        cout<<endl;
        }
    }

    void resizeMatrix(int newRows, int newCols, int fillVal){
    
        int **newArr;
        if(newRows!=r && newCols!= c){
        newArr= new int*[newRows];
        for(int i=0; i<newRows; i++){
        
            newArr[i]= new int[newCols];
        }
    }
    else{
        cout<<"Already Existing Sizes!"<<endl;
    }

    for(int i=0; i<newRows; i++){
    
        for(int j=0; j<newCols; j++){
        
            if(i<r && j<c){
            newArr[i][j]= arr[i][j];
            }
            else{
            newArr[i][j]= fillVal;
            }
        }
    }

    destroyMem();

    r= newRows;
    c= newCols;
    arr= newArr;

    }

    void transposeArr(){
    
        int **transposedArray= new int *[c];
        for(int i=0; i<c; i++){
        transposedArray[i]= new int[r];
        }

        for(int i=0; i<c;i++){
        for(int j=0; j<r;j++){
        transposedArray[i][j]= arr[j][i];
        }
        }
    
        destroyMem();

        int temp= r;
        r=c;
        c=temp;
        arr= transposedArray;
    }

    void printArr(bool printMethod=false){
    
        for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(printMethod && (i+j)%2!=0){
            arr[i][j]+=2;
        
            }

            cout<<arr[i][j]<<"    ";
        
        }
        cout<< endl;
        }
    }
};
int main()
{

    TwoDimensionalArray a1(2, 2);
    a1.inputArr();
    
    a1.printArr(false);
    
    a1.transposeArr();
    cout<<"------------Transposed Matrix------------"<<endl;

    a1.printArr(false);
    cout<<endl;


    a1.resizeMatrix(3,3, 0);
        cout<<"------------Resized Matrix------------"<<endl;
    a1.printArr(true);
    
  
 return 0;
}