#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

#define MAX_PRODUCTOS 100  // Límite máximo de productos

typedef struct {
    char nombre[40];
    char categoria[40];
    char marca[40];
    double precio;
} Producto;

void listarProductos(FILE *archivo, Producto *productos, int numProductos);
void buscarXMarca(FILE *archivo, Producto *productos, int numProductos);
void buscarXCategoria(FILE *archivo, Producto *productos, int numProductos);
void buscarXPrecioMenor(FILE *archivo, Producto *productos, int numProductos);
void editarProducto(FILE *archivo, Producto *productos, int numProductos);
void agregarProducto(FILE *archivo, Producto *productos, int *numProductos);
void eliminarProducto(FILE *archivo, Producto *productos, int *numProductos);

#endif /* FUNCIONES_H */
