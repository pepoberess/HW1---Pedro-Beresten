#pragma once

#include <iostream>
#include <chrono>

//Función para comparar dos textos
bool sonIguales(const char* str1, const char* str2);

//Función para comparar dos textos en tiempo de compilación
constexpr bool comparar_rapido(const char* str1, const char* str2);

//Función del proceso
void miProcesoAMedir();

//Función del proceso en tiempo de compilación
void miProcesoAMedir1();
