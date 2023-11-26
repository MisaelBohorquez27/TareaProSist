#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(void) {
  struct Admin admin;
  struct Usuario usuario;
  bool usrInit = false;
  struct Producto producto;
  bool productInit = false;
  struct RegistroVenta venta;
  bool ventaInit = false;
  struct Bodeguero bodeguero;
  bool bodeInit = false;
  struct Vendedor vendedor;
  bool vendeInit = false;
  strcpy(admin.username, "admin");
  strcpy(admin.password, "1234");
  char contraseña[10];

  int opcion;
  
  while (opcion != 8) {
    printf("1. Registrar usuario\n");
    printf("2. Registrar venta\n");
    printf("3. Registrar producto\n");
    printf("4. Mostrar ultimo registro de bodeguero\n");
    printf("5. Mostrar ultimo registro de vendedor\n");
    printf("6. Mostrar status de producto\n");
    printf("7. Mostrar ultima venta\n");
    printf("8. Salir\n");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
      usuario = crearUsuario();
      printf("ingresa tu contraseña: \n");
      scanf("%s", contraseña);
      if (strcmp(usuario.rol, "bodeguero") == 0) {
        bodeguero = registrarBodeguero(usuario.nombre, contraseña);
        printf("bodeguero registrado exitosamente\n");
        usrInit = true;
        bodeInit = true;
        break;
      } else if (strcmp(usuario.rol, "vendedor") == 0) {
        vendedor = registrarVendedor(usuario.rol, contraseña);
        printf("vendedor registrado exitosamente\n");
        vendeInit = true;
        break;
      }
      printf("Rol invalido\n");
      break;
    case 2:
      producto = CrearProducto(producto);
      productInit = true;
      venta = vender(producto);
      ventaInit = true;
      disminuirInventario(producto);
      break;
    case 3:
      producto = CrearProducto(producto);  
      productInit = true;
      break;
    case 4:
      if (bodeInit) {
        printf("Nombre: %s\n", bodeguero.username);
        printf("Contraseña: %s\n", bodeguero.password);
      } else {
        printf("No se ha registrado ningun bodeguero.\n");
      }
      break;
    case 5:
      if (vendeInit) {
        printf("Nombre: %s\n", vendedor.username);
        printf("Contraseña: %s\n", vendedor.password);
      } else {
        printf("No se ha registrado ningún vendedor.\n");
      }
      break;  
    case 6:
        if (productInit) {
          printf("Inventario de producto %s es %d\n", producto.nombre, producto.inventario);
        } else {
          printf("No hay ningun producto registrado\n");
        }
      break;
    case 7:
      if (ventaInit) {
        printf("Vendedor: %s\n", venta.vendedor);
        printf("Fecha de la venta: %s\n", venta.fecha);
        printf("Precio de venta: %d\n", venta.precioventa);
        printf("Local de venta: %s\n", venta.local);
      } else {
        printf("No hay ninguna venta registrada.\n");
      }
    case 8:
      break;  
    default:
      printf("Opción inválida\n");
      break;
    }
  }
  return 0;
}

