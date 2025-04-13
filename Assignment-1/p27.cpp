//1. Matrix Multiplication

#include <iostream>
using namespace std;

void multiplyMatrices(int first[10][10], int second[10][10], int result[10][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columnFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int first[10][10], second[10][10], result[10][10], rowFirst, columnFirst, rowSecond, columnSecond;

    cout << "Enter rows and columns for first matrix: ";
    cin >> rowFirst >> columnFirst;
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rowFirst; i++)
        for (int j = 0; j < columnFirst; j++)
            cin >> first[i][j];

    cout << "Enter rows and columns for second matrix: ";
    cin >> rowSecond >> columnSecond;

    if (columnFirst != rowSecond) {
        cout << "Matrix multiplication not possible." << endl;
        return 0;
    }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rowSecond; i++)
        for (int j = 0; j < columnSecond; j++)
            cin >> second[i][j];

    multiplyMatrices(first, second, result, rowFirst, columnFirst, rowSecond, columnSecond);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}