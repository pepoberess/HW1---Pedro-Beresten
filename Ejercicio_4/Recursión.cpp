#include <iostream>
#include <chrono>




// bool sonIguales(const char* str1, const char* str2) {
//         // Caso base: si ambos apuntan al final ('\0'), son iguales
//         if (*str1 == '\0' && *str2 == '\0') return true;
    
//         // Si los caracteres actuales son distintos, las cadenas no son iguales
//         if (*str1 != *str2) return false;
    
//         // Llamada recursiva para comparar el siguiente carácter
//         return sonIguales(str1 + 1, str2 + 1);
// }

// int main() {
//     const char* texto1 = "Este es un texto de prueba con más de 64 caracteres para la comparación.";
//     const char* texto2 = "Este es un texto de prueba con más de 64 caracteres para la comparación.";

//     auto startTime = std::chrono::high_resolution_clock::now();
//     bool resultado = sonIguales(texto1, texto2);
//     auto endTime = std::chrono::high_resolution_clock::now();

//     auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    
//     std::cout << "Los textos son " << (resultado ? "iguales" : "diferentes") << std::endl;
//     std::cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << std::endl;

//     return 0;
// }
/*  
   Utilizo chars ya que debe hacerse en tiempo de compilación y constexpr no admite strings  
*/

constexpr bool comparar_rapido(const char* str1, const char* str2) {
    // Caso base: si ambos apuntan al final ('\0'), son iguales
    if (*str1 == '\0' && *str2 == '\0') return true;
    
    // Si los caracteres actuales son distintos, las cadenas no son iguales
    if (*str1 != *str2) return false;

    // Llamada recursiva para comparar el siguiente carácter
    return comparar_rapido(str1 + 1, str2 + 1);
}

void miProcesoAMedir() {
    constexpr const char* texto1 = "Boca mi buen amigo esta campaña volveremos a estar contigo. Te alentaremos de corazón, esta es tu hinchada que te quiere ver campeón";
    constexpr const char* texto2 = "Boca mi buen amigo esta campaña volveremos a estar contigo. Te alentaremos de corazón, esta es tu hinchada que te quiere ver campeón";
    
    auto startTime = std::chrono::high_resolution_clock::now();
    constexpr bool sonIguales = comparar_rapido(texto1, texto2);

    std::cout << "Comparación 1: " << sonIguales << std::endl;
}

int main(){
    auto startTime = std::chrono::high_resolution_clock::now();
    miProcesoAMedir();
    auto endTime = std::chrono::high_resolution_clock::now();

    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;

    return 0;
}


