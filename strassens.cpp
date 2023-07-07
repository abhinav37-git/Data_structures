#include <bits/stdc++.h>
using namespace std;


//add two matrices
vector<vector<int>> add(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

//subtract two matrices
vector<vector<int>> subtract(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}
vector<vector<int>> strassen(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Step 1: Divide each matrix into four sub-matrices of equal size
    int m = n / 2;

    vector<vector<int>> A11(m, vector<int>(m, 0));
    vector<vector<int>> A12(m, vector<int>(m, 0));
    vector<vector<int>> A21(m, vector<int>(m, 0));
    vector<vector<int>> A22(m, vector<int>(m, 0));
    vector<vector<int>> B11(m, vector<int>(m, 0));
    vector<vector<int>> B12(m, vector<int>(m, 0));
    vector<vector<int>> B21(m, vector<int>(m, 0));
    vector<vector<int>> B22(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    // Step 2: Compute seven matrix products using the sub-matrices
    vector<vector<int>> P1 = strassen(A11, subtract(B12, B22));
    vector<vector<int>> P2 = strassen(add(A11, A12), B22);
    vector<vector<int>> P3 = strassen(add(A21, A22), B11);
    vector<vector<int>> P4 = strassen(A22, subtract(B21, B11));
    vector<vector<int>> P5 = strassen(add(A11, A22), add(B11, B22));
    vector<vector<int>> P6 = strassen(subtract(A12, A22), add(B21, B22));
    vector<vector<int>> P7 = strassen(subtract(A11, A21), add(B11, B12));

    // Step 3: Compute the resulting sub-matrices of the product matrix, C
    vector<vector<int>> C11 = subtract(add(add(P5, P4), P6), P2);
    vector<vector<int>> C12 = add(P1, P2);
    vector<vector<int>> C21 = add(P3, P4);
    vector<vector<int>> C22 = subtract(add(add(P5, P1), P3), P7);

    // Step 4: Combine the sub-matrices to form the resulting product matrix, C
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
    return C;
}
int main() {
    // Example 4x4 matrices
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    // Perform matrix multiplication using Strassen's algorithm
    vector<vector<int>> C = strassen(A, B);

    // Print the result matrix
    cout << "Result matrix:" << endl;
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[0].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

