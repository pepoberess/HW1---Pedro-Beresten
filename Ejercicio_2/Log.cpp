#include "Log.h"

// Los niveles de severidad con un enum
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

// Función para convertir el nivel de severidad a string
string LogLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

// Función para registrar un mensaje en el archivo de log
void logMessage(const string& mensaje, LogLevel nivel) {
    ofstream logFile("log.txt", ios::app); // Abre el archivo para poder escribir
    if (!logFile) { // Verifica si el archivo se abrió correctamente
        cerr << "Ocurrió un error al abrir el archivo." << endl;
        return;
    }

    logFile << "[" << LogLevelString(nivel) << "] " << mensaje << endl; // Escribe el mensaje en el archivo
    logFile.close();
}

// Función para registrar errores con archivo y línea de código
void logMessage(const string& Mensaje_de_Error, const string& Archivo, int Linea_de_Codigo) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) { // Verifica si el archivo se abrió correctamente
        cerr << "Ocurrió un error al abrir el archivo." << endl;
        return;
    }

    logFile << "[ERROR] " << Mensaje_de_Error << " (Archivo: " << Archivo << ", Línea: " << Linea_de_Codigo << ")" << endl; // Escribe el mensaje en el archivo
    logFile.close();
}

// Función para registrar eventos de seguridad con el nombre de usuario
void logMessage(const string& Mensaje_de_Acceso, const string& Nombre_de_Usuario) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) { // Verifica si el archivo se abrió correctamente
        cerr << "Ocurrió un error al abrir el archivo." << endl;
        return;
    }

    logFile << "[SECURITY] " << Mensaje_de_Acceso << " (Usuario: " << Nombre_de_Usuario << ")" << endl; // Escribe el mensaje en el archivo
    logFile.close();
}

// Función de prueba para capturar un error en runtime
void generarError() {
    try {
        throw runtime_error("Rompiste el programa"); // Genera un error de tiempo de ejecución
    } catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__); // Registra el error con la información del archivo y la línea
        cerr << "Se cierra todo" << endl;
        exit(1); // Termina la ejecución del programa
    }
}

int main() {

    // **LIMPIA el log al inicio de cada ejecución**
    ofstream logFile("log.txt", ios::trunc);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return 1;
    }
    logFile.close();  // Cierra el archivo después de limpiarlo

    // Prueba de la función con todos los niveles de severidad
    logMessage("Error", LogLevel::DEBUG);
    logMessage("Error 2", LogLevel::INFO);
    logMessage("Error 3", LogLevel::WARNING);
    logMessage("Error 4", LogLevel::ERROR);
    logMessage("Error 5", LogLevel::CRITICAL);

    // Mensaje de error con archivo y línea
    logMessage("No se encuentra archivo", __FILE__, __LINE__);

    // Registro de accesos de usuario
    logMessage("Access Granted", "Bere");
    logMessage("Access Denied", "Gallina");

    // Generamos un error en runtime para demostrar la funcionalidad
    generarError();

    return 0;
}

