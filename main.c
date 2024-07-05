#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    FILE *archivo;
    archivo = fopen("resultados.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    Producto productos[MAX_PRODUCTOS];  // Arreglo de productos
    int numProductos = 0;               // Número actual de productos

    int opcion1, opcion2, opcion3;

    do {
        printf("\nElija una opción:\n");
        printf("1. Listar Productos\n");
        printf("2. Buscar Productos\n");
        printf("3. Editar Productos\n");
        printf("4. Agregar Producto\n");
        printf("5. Eliminar Producto\n");
        printf("0. Salir\n>> ");
        scanf("%d", &opcion1);

        switch (opcion1) {
            case 1:
                listarProductos(archivo, productos, numProductos);
                break;
            case 2:
                printf("\nBuscar por:\n");
                printf("1. Marca\n");
                printf("2. Categoría\n");
                printf("3. Precio Menor de\n>> ");
                scanf("%d", &opcion2);
                switch (opcion2) {
                    case 1:
                        buscarXMarca(archivo, productos, numProductos);
                        break;
                    case 2:
                        buscarXCategoria(archivo, productos, numProductos);
                        break;
                    case 3:
                        buscarXPrecioMenor(archivo, productos, numProductos);
                        break;
                    default:
                        fprintf(archivo, "Opción no válida.\n");
                        break;
                }
                break;
            case 3:
                editarProducto(archivo, productos, numProductos);
                break;
            case 4:
                if (numProductos < MAX_PRODUCTOS) {
                    agregarProducto(archivo, productos, &numProductos);
                } else {
                    fprintf(archivo, "No se puede agregar más productos. Límite alcanzado.\n");
                }
                break;
            case 5:
                eliminarProducto(archivo, productos, &numProductos);
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                fprintf(archivo, "Opción no válida.\n");
                break;
        }

        printf("\nDesea elegir otra opción:\n");
        printf("1. Sí\n");
        printf("2. No\n>> ");
        scanf("%d", &opcion3);

    } while (opcion3 == 1);

    fclose(archivo);
    printf("Los resultados se han guardado en 'resultados.txt'\n");

    return 0;
}
