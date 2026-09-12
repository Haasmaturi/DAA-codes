#include <iostream>
using namespace std;
const int MAXN = 100;
void add(int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void sub(int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}
void strassen(int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int k = n / 2;
    int A11[MAXN][MAXN], A12[MAXN][MAXN], A21[MAXN][MAXN], A22[MAXN][MAXN];
    int B11[MAXN][MAXN], B12[MAXN][MAXN], B21[MAXN][MAXN], B22[MAXN][MAXN];
    int C11[MAXN][MAXN], C12[MAXN][MAXN], C21[MAXN][MAXN], C22[MAXN][MAXN];
    int M1[MAXN][MAXN], M2[MAXN][MAXN], M3[MAXN][MAXN], M4[MAXN][MAXN];
    int M5[MAXN][MAXN], M6[MAXN][MAXN], M7[MAXN][MAXN];
    int t1[MAXN][MAXN], t2[MAXN][MAXN];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j]; A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j]; A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j]; B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j]; B22[i][j] = B[i + k][j + k];
        }
    add(A11, A22, t1, k); add(B11, B22, t2, k); strassen(t1, t2, M1, k);
    add(A21, A22, t1, k); strassen(t1, B11, M2, k);
    sub(B12, B22, t2, k); strassen(A11, t2, M3, k);
    sub(B21, B11, t2, k); strassen(A22, t2, M4, k);
    add(A11, A12, t1, k); strassen(t1, B22, M5, k);
    sub(A21, A11, t1, k); add(B11, B12, t2, k); strassen(t1, t2, M6, k);
    sub(A12, A22, t1, k); add(B21, B22, t2, k); strassen(t1, t2, M7, k);
    add(M1, M4, t1, k); sub(t1, M5, t2, k); add(t2, M7, C11, k);
    add(M3, M5, C12, k);
    add(M2, M4, C21, k);
    add(M1, M3, t1, k); sub(t1, M2, t2, k); add(t2, M6, C22, k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j]; C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j]; C[i + k][j + k] = C22[i][j];
        }
}
int main() {
    int n;
    cout << "Enter size of square matrix (power of 2): ";
    cin >> n;
    int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
    cout << "Enter elements of matrix A: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];
    cout << "Enter elements of matrix B: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> B[i][j];
    strassen(A, B, C, n);
    cout << "Resultant matrix C = A x B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}
