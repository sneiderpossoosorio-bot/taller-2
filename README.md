# taller
Integrantes Del Grupo:
Janny Sneider Osorio Angulo
Carlos Mario Portocarrero Pestana

# Programa de Estudiantes en C

Este proyecto implementa un sistema sencillo para gestionar estudiantes en *C*, utilizando estructuras (struct), menús y funciones recursivas.

 Funcionalidades

El programa permite:

1. Calcular la nota máxima (usando recursividad).  
2. Calcular el promedio de las notas (usando recursividad).  
3. Ordenar los estudiantes por código mediante Selection Sort recursivo.  
4. Mostrar la lista de estudiantes* (código y nota).  
5. Salir del programa.  

---

 Estructura de datos

Se utiliza un struct llamado Estudiante:

```c
typedef struct {
    int codigo;
    float nota;
} Estudiante;
