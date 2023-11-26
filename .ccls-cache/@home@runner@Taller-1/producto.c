#include "funciones.h"
#include <stdio.h>


struct Producto registrarProducto() {
  struct Producto producto;
  printf("Ingrese el nombre del producto\n");
  scanf("%s", producto.nombre);
  printf("Ingrese la categoría del producto\n");
  scanf("%s", producto.categoria);
  printf("Ingrese la marca del producto\n");
  scanf("%s", producto.marca);
  printf("Ingrese código del producto\n");
  scanf("%d", &producto.codigo);
  printf("Ingrese el precio\n");
  scanf("%f", &producto.precio_compra);
  printf("Ingrese cantidad\n");
  scanf("%d", &producto.inventario);
  return producto;
}

void disminuirInventario(struct Producto producto) {
  producto.inventario =-1;
}
