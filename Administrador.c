#include "funciones.h"
#include <stdio.h>


struct Usuario crearUsuario() {
  struct Usuario usuario;
  printf("Ingrese el nombre del usuario: \n");
  scanf("%s", usuario.nombre);
  printf("Ingrese el rol del usuario: \n");
  scanf("%s", usuario.rol);
  return usuario;
}

void actualizarUsuario(struct Usuario usuario) {   
  char nuevo_nombre[20];
  char nuevo_rol[20];
  printf("Ingrese el nuevo nombre del usuario: \n");
  scanf("%s", usuario.nombre);
  printf("Ingrese el nuevo rol del usuario: \n");
  scanf("%s", usuario.rol);
}