#include<iostream>
using namespace std;


bool isSafe(int **arr, int x, int y, int size){

    if(x<size && y<size && arr[x][y]==1){
    return true;
    }
    return false;

}

bool iceCreamShop(int **arr, int x, int y, int size, int **solArr){


    if(x==size-1 && y==size-1){ 
    solArr[x][y]=1;
    return true;
    }

    if(isSafe(arr, x, y, size)){
    
        solArr[x][y]=1;

        if(iceCreamShop(arr,x+1,y, size, solArr)){
        return true;
        }

        if(iceCreamShop(arr, x, y+1, size, solArr)){
        return true;
        }

        if(iceCreamShop(arr, x-1, y, size, solArr)){
        return true;
        }

        if(iceCreamShop(arr, x, y-1, size, solArr)){
        return true;
        }
       

        solArr[x][y]=0;
        return false;

    }
    return false;
}

int main()
{

    int size= 7;
    int maze[7][7]= {
    {1,0,1,1,1,0,1},
    {1,1,1,0,1,1,1},
    {0,1,0,1,0,1,0},
    {1,1,1,1,1,0,1},
    {0,0,0,0,1,1,1},
    {1,1,1,0,1,0,1},
    {0,0,1,1,1,1,1}
    };

    int **arr = new int*[size];
    int **solArr = new int*[size];

     for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        solArr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            arr[i][j] = maze[i][j];
            solArr[i][j] = 0;
        }
    }

     if (iceCreamShop(arr, 0, 0, size, solArr)) {
        cout << "Solution Path (Child's movement):" << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
    }
  

 return 0;
}