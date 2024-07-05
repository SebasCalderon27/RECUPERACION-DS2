#include "funciones.h"
#include <stdio.h>
#include <string.h>

void listarProductos(FILE *archivo, Producto productos[], double precio[], int indice[]) {
    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", indice[i], productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
        printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", indice[i], productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
    }
}

void buscarXMarca(FILE *archivo, Producto productos[], double precio[]) {
    char marca[40];
    printf("Ingrese la marca a buscar: ");
    scanf("%s", marca);
    
    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (strcmp(productos[i].marca, marca) == 0) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
            printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
        }
    }
}

void buscarXCategoria(FILE *archivo, Producto productos[], double precio[]) {
    char categoria[40];
    printf("Ingrese la categoria a buscar: ");
    scanf("%s", categoria);

    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (strcmp(productos[i].categoria, categoria) == 0) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
            printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
        }
    }
}

void buscarXPrecioMenor(FILE *archivo, Producto productos[], double precio[]) {
    double limite;
    printf("Ingrese el precio limite: ");
    scanf("%lf", &limite);

    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (precio[i] < limite) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
            printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, precio[i]);
        }
    }
}

void editarProducto(FILE *archivo, Producto productos[], double precio[], int indice[]) {
    int num;
    printf("Ingrese el numero del producto a editar: ");
    scanf("%d", &num);
    num--;  

    printf("Editar Nombre (actual: %s): ", productos[num].nombre);
    scanf("%s", productos[num].nombre);
    printf("Editar Categoria (actual: %s): ", productos[num].categoria);
    scanf("%s", productos[num].categoria);
    printf("Editar Marca (actual: %s): ", productos[num].marca);
    scanf("%s", productos[num].marca);
    printf("Editar Precio (actual: %.2f): ", precio[num]);
    scanf("%lf", &precio[num]);

    fprintf(archivo, "Producto editado exitosamente.\n");
    fprintf(archivo, "Nuevo producto: %d\t%s\t\t%s\t\t%s\t\t%.2f\n", indice[num], productos[num].nombre, productos[num].categoria, productos[num].marca, precio[num]);
    printf("Producto editado exitosamente.\n");
}

void agregarProducto(FILE *archivo, Producto productos[], double precio[], int *numProductos, int *nextIndex) {
    if (*numProductos >= MAX_PRODUCTOS) {
        fprintf(archivo, "No se puede agregar más productos. Límite alcanzado (%d productos).\n", MAX_PRODUCTOS);
        printf("No se puede agregar más productos. Límite alcanzado (%d productos).\n", MAX_PRODUCTOS);
        return;
    }

    printf("Ingrese el nombre del nuevo producto: ");
    scanf("%s", productos[*numProductos].nombre);
    printf("Ingrese la categoría del nuevo producto: ");
    scanf("%s", productos[*numProductos].categoria);
    printf("Ingrese la marca del nuevo producto: ");
    scanf("%s", productos[*numProductos].marca);
    printf("Ingrese el precio del nuevo producto: ");
    scanf("%lf", &precio[*numProductos]);

    (*numProductos)++;
    fprintf(archivo, "Producto agregado correctamente.\n");
    fprintf(archivo, "Nuevo producto: %d\t%s\t\t%s\t\t%s\t\t%.2f\n", *nextIndex, productos[*numProductos - 1].nombre, productos[*numProductos - 1].categoria, productos[*numProductos - 1].marca, precio[*numProductos - 1]);
    printf("Producto agregado correctamente.\n");
    (*nextIndex)++;
}

void eliminarProducto(FILE *archivo, Producto productos[], double precio[], int *numProductos) {
    int num;
    printf("Ingrese el numero del producto a eliminar: ");
    scanf("%d", &num);
    num--;

    fprintf(archivo, "Producto eliminado correctamente.\n");
    fprintf(archivo, "Producto eliminado: %d\t%s\t\t%s\t\t%s\t\t%.2f\n", num + 1, productos[num].nombre, productos[num].categoria, productos[num].marca, precio[num]);
    printf("Producto eliminado correctamente.\n");


    strcpy(productos[num].nombre, productos[*numProductos - 1].nombre);
    strcpy(productos[num].categoria, productos[*numProductos - 1].categoria);
    strcpy(productos[num].marca, productos[*numProductos - 1].marca);
    precio[num] = precio[*numProductos - 1];

    (*numProductos)--;
}
