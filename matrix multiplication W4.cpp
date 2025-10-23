#include <iostream>
using namespace std;

int main() {
    // ----------------------------
    // Step 1: Make a 2D array (matrix)
    // ----------------------------
    int A[2][3] = { {1, 2, 3},
                    {4, 5, 6} };

    int B[3][2] = { {7, 8},
                    {9, 10},
                    {11, 12} };

    // Result matrix (2x2)
    int C[2][2] = {0};  

    // ----------------------------
    // Step 2: Print Matrix A
    // ----------------------------
    cout << "Matrix A (2x3):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // ----------------------------
    // Step 3: Print Matrix B
    // ----------------------------
    cout << "Matrix B (3x2):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // ----------------------------
    // Step 4: Multiply A x B
    // Rule: C[i][j] = sum of (A[i][k] * B[k][j])
    // ----------------------------
    for (int i = 0; i < 2; i++) {         // rows of A
        for (int j = 0; j < 2; j++) {     // cols of B
            for (int k = 0; k < 3; k++) { // shared dimension
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // ----------------------------
    // Step 5: Print Result Matrix
    // ----------------------------
    cout << "Result Matrix C = A x B (2x2):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
