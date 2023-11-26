#include "funciones.h"
#include <stdio.h>

void ActualizarProducto(struct Producto producto) {
    disminuirInventario(producto);
    printf("Productos disponibles: %d\n", producto.inventario);

    // Guardar producto en el archivo
    FILE *archivoProductos = fopen("productos.txt", "a");
    if (archivoProductos == NULL) {
        printf("Error al abrir el archivo de productos para escritura.\n");
        return;
    }

    fprintf(archivoProductos, "%s %s %s %d %f %d\n",
            producto.nombre,
            producto.categoria,
            producto.marca,
            producto.codigo,
            producto.precio_compra,
            producto.inventario);

    fclose(archivoProductos);
}

struct Producto CrearProducto(struct Producto producto) {
    producto = registrarProducto(producto);
    printf("Producto creado: %s\n", producto.nombre);
    return producto;
}

struct Bodeguero registrarBodeguero(char username[10], char password[10]) {
    struct Bodeguero bodeguero;
    strcpy(bodeguero.username, username);
    strcpy(bodeguero.password, password);
    return bodeguero;
}

void cargarProductos(struct Producto productos[], int *numProductos) {
    FILE *archivoProductos = fopen("productos.txt", "r");
    if (archivoProductos == NULL) {
        printf("Parece que hubo un error al abrir el archivo de productos.\n");
        return;
    }

    while (fscanf(archivoProductos, "%s %s %s %d %f %d",
                  productos[*numProductos].nombre,
                  productos[*numProductos].categoria,
                  productos[*numProductos].marca,
                  &productos[*numProductos].codigo,
                  &productos[*numProductos].precio_compra,
                  &productos[*numProductos].inventario) == 6) {
        (*numProductos)++;
    }

    fclose(archivoProductos);
}

void guardarProductos(struct Producto productos[], int numProductos) {
    FILE *archivoProductos = fopen("productos.txt", "w");
    if (archivoProductos == NULL) {
        printf("Error al abrir el archivo de productos para escritura.\n");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        fprintf(archivoProductos, "%s %s %s %d %f %d\n",
                productos[i].nombre,
                productos[i].categoria,
                productos[i].marca,
                productos[i].codigo,
                productos[i].precio_compra,
                productos[i].inventario);
    }

    fclose(archivoProductos);
}