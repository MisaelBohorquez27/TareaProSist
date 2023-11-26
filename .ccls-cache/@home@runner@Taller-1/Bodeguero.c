#include "funciones.h"
#include <stdio.h>
#include <string.h>

void ActualizarProducto(struct Producto producto){
  disminuirInventario(producto);  
  printf("Productos disponibles: %d\n", producto.inventario);
  
};

struct Producto CrearProducto(struct Producto producto) {
  producto = registrarProducto(producto);
  printf("Producto creado: %s\n", producto.nombre);
  return producto;
};

struct Bodeguero registrarBodeguero(char username[10], char password[10]) {
  struct Bodeguero bodeguero;
  strcpy(bodeguero.username, username);
  strcpy(bodeguero.password, password);
  return bodeguero;
};