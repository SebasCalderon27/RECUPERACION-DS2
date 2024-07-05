#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    FILE *archivo;
    archivo = fopen("resultados.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char productos[10][3][40] = {
        {"Jordan", "Zapatos", "Nike"},
        {"Classic", "Camisas", "Nike"},
        {"Terrex", "Zapatos", "Adidas"},
        {"Classic", "Zapatos", "Puma"},
        {"Venture", "Camisas", "Nike"},
        {"Superst", "Zapatos", "Adidas"},
        {"Terrex", "Chompas", "Adidas"},
        {"Classic", "Chompas", "Puma"},
        {"Venture", "Chompas", "Adidas"},
        {"Hoddie", "Chompas", "Puma"}
    };
    double precio[10] = {120, 40, 122, 89, 150, 110, 150, 120, 40, 45};
    int indice[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int opcion1, opcion2, opcion3;

    do {
        printf("Elija una opción:\n1. Listar Productos\n2. Buscar Productos\n3. Editar Productos\n>> ");
        scanf("%d", &opcion1);
        switch (opcion1) {
            case 1:
                listarProductos(archivo, productos, precio, indice);
                break;
            case 2:
                printf("Buscar por:\n1. Marca\n2. Categoria\n3. Precio Menor de\n>> ");
                scanf("%d", &opcion2);
                switch (opcion2) {
                    case 1:
                        buscarXMarca(archivo, productos, precio);
                        break;
                    case 2:
                        buscarXCategoria(archivo, productos, precio);
                        break;
                    case 3:
                        buscarXPrecioMenor(archivo, productos, precio);
                        break;
                    default:
                        fprintf(archivo, "Opción no válida.\n");
                        break;
                }
                break;
            case 3:
                editarProducto(archivo, productos, precio, indice);
                break;
            default:
                fprintf(archivo, "Opción no válida.\n");
                break;
        }
        printf("Desea elegir otra opción:\n1. Si\n2. No\n>> ");
        scanf("%d", &opcion3);
    } while (opcion3 == 1);

    fclose(archivo);

    archivo = fopen("resultados.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char linea[256];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
    printf("Los resultados se han guardado en 'resultados.txt'\n");

    return 0;
}