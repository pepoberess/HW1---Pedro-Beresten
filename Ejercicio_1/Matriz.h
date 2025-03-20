#pragma once

#include <iostream>
#include <vector>

using namespace std;

// Función que genera una matriz cuadrada de tamaño n x n con números secuenciales
std::vector<std::vector<int>> generarMatriz(int n);

// Función que imprime la matriz en orden inverso
void imprimirMatriz(const std::vector<std::vector<int>>& matriz);
