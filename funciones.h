#ifndef FUNCIONES_H_
#define FUNCIONES_H_

struct Usuario {
    char nombre[20];
    char rol[20];
};

struct Producto {
    char nombre[20];
    char categoria[20];
    char marca[20];
    int codigo;
    float precio_compra;
    int inventario;
};

struct RegistroVenta {
    char vendedor[10];
    char fecha[10];
    int precioventa;
    char local[10];
};

struct Vendedor {
    char username[10];
    char password[10];
};

struct Bodeguero {
    char username[10];
    char password[10];
};

struct Usuario crearUsuario();
void actualizarUsuario(struct Usuario *usuario);
void guardarUsuarios(struct Usuario usuarios[], int numUsuarios);
void cargarUsuarios(struct Usuario usuarios[], int *numUsuarios);

struct Producto registrarProducto();
void disminuirInventario(struct Producto *producto);
void ActualizarProducto(struct Producto producto);
struct Producto CrearProducto(struct Producto producto);
void cargarProductos(struct Producto productos[], int *numProductos);
void guardarProductos(struct Producto productos[], int numProductos);

struct RegistroVenta vender(struct Producto producto);
struct Vendedor registrarVendedor(char username[10], char password[10]);
void cargarVentas(struct RegistroVenta ventas[], int *numVentas);
void guardarVentas(struct RegistroVenta ventas[], int numVentas);

struct Bodeguero registrarBodeguero(char username[10], char password[10]);

#endif
