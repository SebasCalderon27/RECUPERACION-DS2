#include <stdio.h>
#include <string.h>

void listarProductos(FILE *archivo, char productos[][3][40], double precio[], int indice[]) {
    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", indice[i], productos[i][0], productos[i][1], productos[i][2], precio[i]);
    }
}

void buscarXMarca(FILE *archivo, char productos[][3][40], double precio[]) {
    char marca[40];
    printf("Ingrese la marca a buscar: ");
    scanf("%s", marca);
    
    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(productos[i][2], marca) == 0) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i][0], productos[i][1], productos[i][2], precio[i]);
        }
    }
}

void buscarXCategoria(FILE *archivo, char productos[][3][40], double precio[]) {
    char categoria[40];
    printf("Ingrese la categoria a buscar: ");
    scanf("%s", categoria);

    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(productos[i][1], categoria) == 0) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i][0], productos[i][1], productos[i][2], precio[i]);
        }
    }
}

void buscarXPrecioMenor(FILE *archivo, char productos[][3][40], double precio[]) {
    double limite;
    printf("Ingrese el precio limite: ");
    scanf("%lf", &limite);

    fprintf(archivo, "Numero\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        if (precio[i] < limite) {
            fprintf(archivo, "%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i][0], productos[i][1], productos[i][2], precio[i]);
        }
    }
}

void editarProducto(FILE *archivo, char productos[][3][40], double precio[], int indice[]) {
    int num;
    printf("Ingrese el numero del producto a editar: ");
    scanf("%d", &num);
    num--;  

    printf("Editar Nombre (actual: %s): ", productos[num][0]);
    scanf("%s", productos[num][0]);
    printf("Editar Categoria (actual: %s): ", productos[num][1]);
    scanf("%s", productos[num][1]);
    printf("Editar Marca (actual: %s): ", productos[num][2]);
    scanf("%s", productos[num][2]);
    printf("Editar Precio (actual: %.2f): ", precio[num]);
    scanf("%lf", &precio[num]);

    fprintf(archivo, "Producto editado exitosamente.\n");
    fprintf(archivo, "Nuevo producto: %d\t%s\t\t%s\t\t%s\t\t%.2f\n", indice[num], productos[num][0], productos[num][1], productos[num][2], precio[num]);
}