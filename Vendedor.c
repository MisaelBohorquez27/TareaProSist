#include <stdio.h>
#include <string.h>
#include "funciones.h"

struct RegistroVenta vender(struct Producto producto) {
    struct RegistroVenta venta;
    printf("Ingrese el nombre del vendedor: \n");
    scanf("%s", venta.vendedor);
    printf("Ingrese la fecha de venta: \n");
    scanf("%s", venta.fecha);
    printf("Ingrese el precio de venta: \n");
    scanf("%d", &venta.precioventa);
    printf("Ingrese el local de venta: \n");
    scanf("%s", venta.local);

    // Guardar venta en el archivo
    FILE *archivoVentas = fopen("ventas.txt", "a");
    if (archivoVentas == NULL) {
        printf("Error al abrir el archivo de ventas para escritura.\n");
        return venta;
    }

    fprintf(archivoVentas, "%s %s %d %s\n",
            venta.vendedor,
            venta.fecha,
            venta.precioventa,
            venta.local);

    fclose(archivoVentas);

    return venta;
}

struct Vendedor registrarVendedor(char username[10], char password[10]) {
    struct Vendedor vendedor;
    strcpy(vendedor.username, username);
    strcpy(vendedor.password, password);
    return vendedor;
}

void cargarVentas(struct RegistroVenta ventas[], int *numVentas) {
    FILE *archivoVentas = fopen("ventas.txt", "r");
    if (archivoVentas == NULL) {
        printf("Parece que hubo un error al abrir el archivo de ventas.\n");
        return;
    }

    while (fscanf(archivoVentas, "%s %s %d %s",
                  ventas[*numVentas].vendedor,
                  ventas[*numVentas].fecha,
                  &ventas[*numVentas].precioventa,
                  ventas[*numVentas].local) == 4) {
        (*numVentas)++;
    }

    fclose(archivoVentas);
}

void guardarVentas(struct RegistroVenta ventas[], int numVentas) {
    FILE *archivoVentas = fopen("ventas.txt", "w");
    if (archivoVentas == NULL) {
        printf("Error al abrir el archivo de ventas para escritura.\n");
        return;
    }

    for (int i = 0; i < numVentas; i++) {
        fprintf(archivoVentas, "%s %s %d %s\n",
                ventas[i].vendedor,
                ventas[i].fecha,
                ventas[i].precioventa,
                ventas[i].local);
    }

    fclose(archivoVentas);
}