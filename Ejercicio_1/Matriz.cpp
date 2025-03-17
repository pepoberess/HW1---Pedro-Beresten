#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generarMatriz(int n);
void imprimirMatriz(const vector<vector<int>>& matriz);

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz (n > 1): ";
    cin >> n;
    if (n <= 1) {
        cout << "El valor de n debe ser mayor a 1." << endl;
        return 1;
    }
    
    vector<vector<int>> matriz = generarMatriz(n);
    imprimirMatriz(matriz);

    return 0;
}

vector<vector<int>> generarMatriz(int n) {
    vector<vector<int>> matriz(n, vector<int>(n));
    int valor = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = valor++;
        }
    }
    return matriz;
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = n * n - 1; i >= 0; --i) {
        int fila = i / n;
        int columna = i % n;
        cout << "M[" << fila << "][" << columna << "] = " << matriz[fila][columna] << endl;
    }
}

