

#include <stdio.h>

// Definición de la estructura Estudiante
typedef struct {
    int codigo;   // Código del estudiante
    float nota;   // Nota del estudiante
} Estudiante;

// Número de estudiantes
#define NUM_ESTUDIANTES 6

// Arreglo con datos de los estudiantes
Estudiante estudiantes[NUM_ESTUDIANTES] = {
    {2024101, 4.5},
    {2024102, 3.2},
    {2024103, 2.9},
    {2024104, 4.0},
    {2024105, 3.8},
    {2024106, 4.7}
};

// Función para mostrar estudiantes
void mostrarEstudiantes(const Estudiante arr[], int n) {
    printf("\nCod\tNota\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%.2f\n", arr[i].codigo, arr[i].nota);
}

// Opciones del menú como enumeración
enum OpcionesMenu { NOTA_MAX = 1, PROMEDIO, ORDENAR_COD, MOSTRAR, SALIR };

// Función para mostrar el menú y leer opción
int mostrarMenu() {
    int op;
    printf("\n=== MENÚ ===\n");
    printf("1. Nota máxima (recursivo)\n");
    printf("2. Promedio (recursivo)\n");
    printf("3. Ordenar por código (Selection Sort Recursivo)\n");
    printf("4. Mostrar estudiantes\n");
    printf("5. Salir\n");
    printf("Opción: ");
    scanf("%d", &op);
    return op; // Devuelve la opción elegida
}

// Prototipos de funciones
float notaMaxRec(const Estudiante arr[], int n);
float sumaNotasRec(const Estudiante arr[], int n);
void ordenarCodRec(Estudiante arr[], int n, int inicio);
int buscarMinIdx(const Estudiante arr[], int n, int inicio, int minIdx);

// Función principal
int main() {
    int opcion;
    int ordenado = 0; // Para indicar si ya se ordenó

    // Bucle principal del menú
    do {
        opcion = mostrarMenu(); // Mostrar menú y leer opción
        switch(opcion) {
            case NOTA_MAX: // Opción 1: nota máxima
                printf("Nota máxima: %.2f\n", notaMaxRec(estudiantes, NUM_ESTUDIANTES));
                break;
            case PROMEDIO: // Opción 2: promedio
                printf("Promedio: %.2f\n", sumaNotasRec(estudiantes, NUM_ESTUDIANTES)/NUM_ESTUDIANTES);
                break;
            case ORDENAR_COD: // Opción 3: ordenar
                ordenarCodRec(estudiantes, NUM_ESTUDIANTES, 0);
                ordenado = 1;
                printf("Estudiantes ordenados por código.\n");
                break;
            case MOSTRAR: // Opción 4: mostrar
                mostrarEstudiantes(estudiantes, NUM_ESTUDIANTES);
                break;
            case SALIR: // Opción 5: salir
                printf("Saliendo...\n");
                break;
            default: // Opción inválida
                printf("Opción no válida.\n");
        }
    } while(opcion != SALIR); // Repetir hasta que elija salir

    return 0;
}

// Función recursiva para encontrar la nota máxima
float notaMaxRec(const Estudiante arr[], int n) {
    if (n == 1) return arr[0].nota; // Caso base: un solo estudiante
    float maxRest = notaMaxRec(arr, n-1); // Máximo del resto
    return (arr[n-1].nota > maxRest) ? arr[n-1].nota : maxRest;
}

// Función recursiva para sumar las notas
float sumaNotasRec(const Estudiante arr[], int n) {
    if (n == 0) return 0; // Caso base: sin estudiantes
    return arr[n-1].nota + sumaNotasRec(arr, n-1); // Nota actual + resto
}

// Función recursiva para ordenar por código (Selection Sort)
void ordenarCodRec(Estudiante arr[], int n, int inicio) {
    if (inicio >= n-1) return; // Caso base: ya está ordenado
    int minIdx = buscarMinIdx(arr, n, inicio, inicio); // Buscar mínimo
    if (minIdx != inicio) { // Intercambiar si es necesario
        Estudiante tmp = arr[inicio];
        arr[inicio] = arr[minIdx];
        arr[minIdx] = tmp;
    }
    ordenarCodRec(arr, n, inicio+1); // Llamada recursiva al resto
}

// Función recursiva para buscar el índice del menor código
int buscarMinIdx(const Estudiante arr[], int n, int inicio, int minIdx) {
    if (inicio >= n) return minIdx; // Caso base: fin del arreglo
    if (arr[inicio].codigo < arr[minIdx].codigo)
        minIdx = inicio; // Actualiza el índice mínimo
    return buscarMinIdx(arr, n, inicio+1, minIdx); // Recurre al siguiente
}


¿Quieres que también te haga un diagrama de flujo del menú principal para que veas el funcionamiento más visual?
