 
#include <iostream>
#include <omp.h>

#define TAMANO 10000
#define BLOQUE 150
#define MOSTRAR 15

void mostrarArreglo(const float* arreglo, const char* nombre);

int main() {
    std::cout << "Sumando elementos de arreglos en paralelo!\n";

    float arreglo1[TAMANO], arreglo2[TAMANO], resultado[TAMANO];

    // Inicialización de los arreglos
#pragma omp parallel for schedule(static, BLOQUE)
    for (int i = 0; i < TAMANO; i++) {
        arreglo1[i] = i * 20;
        arreglo2[i] = i * 1.6;
        resultado[i] = arreglo1[i] + arreglo2[i]; // Suma directa en el mismo bucle
    }

    // Impresión de los resultados
    mostrarArreglo(arreglo1, "Arreglo 1");
    mostrarArreglo(arreglo2, "Arreglo 2");
    mostrarArreglo(resultado, "Resultado");

    return 0;
}

void mostrarArreglo(const float* arreglo, const char* nombre) {
    std::cout << "Primeros " << MOSTRAR << " valores de " << nombre << ": ";
    for (int i = 0; i < MOSTRAR; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;
}
