#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Los niveles de severidad como un enum
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

// Función para convertir el nivel de severidad a string
string LogLevelString(LogLevel level);

// Función para registrar un mensaje en el archivo de log
void logMessage(const string& mensaje, LogLevel nivel);

// Función para registrar errores con archivo y línea de código
void logMessage(const string& Mensaje_de_Error, const string& Archivo, int Linea_de_Codigo);

// Función para registrar accesos de usuario
void logMessage(const string& Mensaje_de_Acceso, const string& Nombre_de_Usuario);

// Función de prueba para capturar un error en runtime
void generarError();