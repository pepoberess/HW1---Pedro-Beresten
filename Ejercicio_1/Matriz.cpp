#include "Matriz.h"

// Para hacer este ejercicio utilizo dos ciclos para primero crear la matriz y luego la imprimo inversamente con un solo for.

vector<vector<int>> generarMatriz(int n) {
    vector<vector<int>> matriz(n, vector<int>(n)); // Crea una matriz n x n
    int valor = 1;
    for (int i = 0; i < n; ++i) {      // Recorre las filas
        for (int j = 0; j < n; ++j) {  // Recorre las columnas
            matriz[i][j] = valor++;    // Asigna un número secuencial
        }
    }
    return matriz; // Retorna la matriz generada
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = n * n - 1; i >= 0; --i) { // Recorre la matriz en orden inverso
        int fila = i / n;     // Calcula la fila correspondiente
        int columna = i % n;  // Calcula la columna correspondiente
        cout << "M[" << fila << "][" << columna << "] = " << matriz[fila][columna] << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz (n > 1): ";
    cin >> n;

    if (n <= 1) { // Valida que n sea mayor a 1
        cout << "El valor de n debe ser mayor a 1." << endl;
        return 1; // Termina el programa si n es inválido
    }

    vector<vector<int>> matriz = generarMatriz(n); // Genera la matriz
    imprimirMatriz(matriz); // Imprime la matriz en orden inverso

    return 0;
}