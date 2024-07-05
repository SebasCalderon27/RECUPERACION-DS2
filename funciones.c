#include "funciones.h"
#include <stdio.h>
#include <string.h>

void listarProductos(FILE *archivo, Producto *productos, int numProductos) {
    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, productos[i].precio);
    }
}

void buscarXMarca(FILE *archivo, Producto *productos, int numProductos) {
    char marca[40];
    printf("Ingrese la marca a buscar: ");
    scanf("%s", marca);
    
    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].marca, marca) == 0) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, productos[i].precio);
        }
    }
}

void buscarXCategoria(FILE *archivo, Producto *productos, int numProductos) {
    char categoria[40];
    printf("Ingrese la categoria a buscar: ");
    scanf("%s", categoria);

    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].categoria, categoria) == 0) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, productos[i].precio);
        }
    }
}

void buscarXPrecioMenor(FILE *archivo, Producto *productos, int numProductos) {
    double limite;
    printf("Ingrese el precio limite: ");
    scanf("%lf", &limite);

    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].precio < limite) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].categoria, productos[i].marca, productos[i].precio);
        }
    }
}

void editarProducto(FILE *archivo, Producto *productos, int numProductos) {
    int num;
    printf("Ingrese el numero del producto a editar: ");
    scanf("%d", &num);
    num--;  // Convertir a índice (restamos 1)

    printf("Editar Nombre (actual: %s): ", productos[num].nombre);
    scanf("%s", productos[num].nombre);
    printf("Editar Categoria (actual: %s): ", productos[num].categoria);
    scanf("%s", productos[num].categoria);
    printf("Editar Marca (actual: %s): ", productos[num].marca);
    scanf("%s", productos[num].marca);
    printf("Editar Precio (actual: %.2f): ", productos[num].precio);
    scanf("%lf", &productos[num].precio);

    fprintf(archivo, "Producto editado exitosamente.\n");
    fprintf(archivo, "Nuevo producto: %d\t%s\t\t%s\t\t%s\t\t%.2f\n", num + 1, productos[num].nombre, productos[num].categoria, productos[num].marca, productos[num].precio);
}

void agregarProducto(FILE *archivo, Producto *productos, int *numProductos) {
    if (*numProductos < MAX_PRODUCTOS) {
        printf("Ingrese el nombre del nuevo producto: ");
        scanf("%s", productos[*numProductos].nombre);
        printf("Ingrese la categoria del nuevo producto: ");
        scanf("%s", productos[*numProductos].categoria);
        printf("Ingrese la marca del nuevo producto: ");
        scanf("%s", productos[*numProductos].marca);
        printf("Ingrese el precio del nuevo producto: ");
        scanf("%lf", &productos[*numProductos].precio);

        fprintf(archivo, "Producto agregado exitosamente.\n");
        fprintf(archivo, "Nuevo producto: %d\t%s\t\t%s\t\t%s\t\t%.2f\n", *numProductos + 1, productos[*numProductos].nombre, productos[*numProductos].categoria, productos[*numProductos].marca, productos[*numProductos].precio);

        (*numProductos)++;
    } else {
        fprintf(archivo, "No se puede agregar más productos. Límite alcanzado.\n");
    }
}

void eliminarProducto(FILE *archivo, Producto *productos, int *numProductos) {
    int num;
    printf("Ingrese el numero del producto a eliminar: ");
    scanf("%d", &num);
    num--;  // Convertir a índice (restamos 1)

    if (num >= 0 && num < *numProductos) {
        fprintf(archivo, "Producto eliminado exitosamente: %d\t%s\t\t%s\t\t%s\t\t%.2f\n", num + 1, productos[num].nombre, productos[num].categoria, productos[num].marca, productos[num].precio);

        // Mover todos los productos posteriores una posición hacia atrás
        for (int i = num; i < *numProductos - 1; i++) {
            strcpy(productos[i].nombre, productos[i + 1].nombre);
            strcpy(productos[i].categoria, productos[i + 1].categoria);
            strcpy(productos[i].marca, productos[i + 1].marca);
            productos[i].precio = productos[i + 1].precio;
        }

        (*numProductos)--;
    } else {
        fprintf(archivo, "Número de producto no válido.\n");
    }
}
