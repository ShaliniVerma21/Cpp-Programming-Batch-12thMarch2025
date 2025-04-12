//4. Dynamic 2D Array Allocation

#include <iostream>
using namespace std;

int** create2DArray(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

void delete2DArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int rows = 3, cols = 4;
    int** array = create2DArray(rows, cols);

    // Assign values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j;
        }
    }

    // Print values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    delete2DArray(array, rows); // Free memory
    return 0;
}