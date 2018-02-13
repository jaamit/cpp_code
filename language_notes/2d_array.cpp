// Example program 2D array
#include <iostream>
#include <string>

const int N = 3;
const int M = 4;

using namespace std;

int main()
{
    // dynamic allocation
    int **arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
    }
    
    // enter data
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = i*(j+1);
        }
    }
    
    // print data
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // free 
    for (int i = 0; i < N; i++) {
        delete [] arr[i];
    }
    delete[] arr;   

}
/*
0 0 0 0 
1 2 3 4 
2 4 6 8 
*/
