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
  return venta;
}

struct Vendedor registrarVendedor(char username[10], char password[10]) {
  struct Vendedor vendedor;
  strcpy(vendedor.username, username);
  strcpy(vendedor.password, password);
  return vendedor; 
}