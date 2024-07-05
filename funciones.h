#define FUNCIONES_H

#include <stdio.h>

void listarProductos(FILE *archivo, char productos[][3][40], double precio[], int indice[]);
void buscarXMarca(FILE *archivo, char productos[][3][40], double precio[]);
void buscarXCategoria(FILE *archivo, char productos[][3][40], double precio[]);
void buscarXPrecioMenor(FILE *archivo, char productos[][3][40], double precio[]);
void editarProducto(FILE *archivo, char productos[][3][40], double precio[], int indice[]);