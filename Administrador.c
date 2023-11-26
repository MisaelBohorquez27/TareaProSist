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

void actualizarUsuario(struct Usuario *usuario) {
    printf("Ingrese el nuevo nombre del usuario: \n");
    scanf("%s", usuario->nombre);
    printf("Ingrese el nuevo rol del usuario: \n");
    scanf("%s", usuario->rol);
    guardarUsuarios(usuario, 1);
}

void guardarUsuarios(struct Usuario usuarios[], int numUsuarios) {
    FILE *archivoUsuarios = fopen("usuarios.txt", "w");
    if (archivoUsuarios == NULL) {
        printf("Hubo un problema al abrir el archivo de usuarios para escritura.\n");
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        fprintf(archivoUsuarios, "%s %s\n", usuarios[i].nombre, usuarios[i].rol);
    }

    fclose(archivoUsuarios);
}

void cargarUsuarios(struct Usuario usuarios[], int *numUsuarios) {
    FILE *archivoUsuarios = fopen("usuarios.txt", "r");
    if (archivoUsuarios == NULL) {
        printf("Parece que hubo un error al abrir el archivo de usuarios.\n");
        return;
    }

    while (fscanf(archivoUsuarios, "%s %s",
                  usuarios[*numUsuarios].nombre,
                  usuarios[*numUsuarios].rol) == 2) {
        (*numUsuarios)++;
    }

    fclose(archivoUsuarios);
}