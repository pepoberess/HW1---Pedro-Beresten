#include "Recursión.h"

// En este último ejercicio utilizo chars para ser comparados en una función recursiva. Los chars son más fáciles de comparar que los strings ya que tienen una comparación directa por tanto me convienen para realizar mi función.
// Luego mido el tiempo que tarda mi código en ejecución y en compilación.


bool sonIguales(const char* str1, const char* str2) { 
        // Caso base: si ambos apuntan al final ('\0'), son iguales
        if (*str1 == '\0' && *str2 == '\0') return true;
    
        // Si los caracteres actuales son distintos, las cadenas no son iguales
        if (*str1 != *str2) return false;
    
        // Llamada recursiva para comparar el siguiente carácter
        return sonIguales(str1 + 1, str2 + 1);
}

//Ejercicio en tiempo de compilación
constexpr bool comparar_rapido(const char* str1, const char* str2) {
    // Caso base: si ambos apuntan al final ('\0'), son iguales
    if (*str1 == '\0' && *str2 == '\0') return true;
    
    // Si los caracteres actuales son distintos, los textos ya no son iguales
    if (*str1 != *str2) return false;

    // Llamada recursiva para comparar el siguiente caracter
    return comparar_rapido(str1 + 1, str2 + 1);
}

void miProcesoAMedir() {
    //Textos a comparar
    const char* texto1 = "Boca mi buen amigo esta campaña volveremos a estar contigo. Te alentaremos de corazón, esta es tu hinchada que te quiere ver campeón";
    const char* texto2 = "Boca mi buen amigo esta campaña volveremos a estar contigo. Te alentaremos de corazón, esta es tu hinchada que te quiere ver campeón";
   
    const bool sonIdenticos = sonIguales(texto1, texto2);

    std::cout << "Comparación 1: " << (sonIdenticos? "iguales" : "distintos") << std::endl;
}

void miProcesoAMedir1() {
    //Textos a comparar
    constexpr const char* texto1 = "Boca mi buen amigo esta campaña volveremos a estar contigo. Te alentaremos de corazón, esta es tu hinchada que te quiere ver campeón";
    constexpr const char* texto2 = "Boca mi buen amigo esta campaña volveremos a estar contigo. Te alentaremos de corazón, esta es tu hinchada que te quiere ver campeón";
   
    constexpr bool sonIguales = comparar_rapido(texto1, texto2);

    std::cout << "Comparación 1: " << (sonIguales? "iguales" : "distintos") << std::endl;
}

int main(){
    //Comienzo el cronómetro
    auto startTime = std::chrono::high_resolution_clock::now();
    miProcesoAMedir();
    //Termino el cronómetro
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);


    //Comienzo el cronómetro
    auto startTime1 = std::chrono::high_resolution_clock::now();
    miProcesoAMedir1();
    //Termino el cronómetro
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto elapsedTime1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime1 - startTime1);
    
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;
    std::cout << "A miProcesoAMedir1 le tomó: " << elapsedTime1.count() << " nanosegundos" << std::endl;
    return 0;
}

/*Ya que gran parte de miProcesoAMedir1 se hace en tiempo de compilación tarda 
considerablemente menos que miProcesoAMedir el cual se hace en tiempo de ejecución. 
*/


