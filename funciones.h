#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

#define MAX_PRODUCTOS 10

typedef struct {
    char nombre[40];
    char categoria[40];
    char marca[40];
} Producto;

void listarProductos(FILE *archivo, Producto productos[], double precio[], int indice[]);
void buscarXMarca(FILE *archivo, Producto productos[], double precio[]);
void buscarXCategoria(FILE *archivo, Producto productos[], double precio[]);
void buscarXPrecioMenor(FILE *archivo, Producto productos[], double precio[]);
void editarProducto(FILE *archivo, Producto productos[], double precio[], int indice[]);
void agregarProducto(FILE *archivo, Producto productos[], double precio[], int *numProductos, int *nextIndex);
void eliminarProducto(FILE *archivo, Producto productos[], double precio[], int *numProductos);

#endif 
