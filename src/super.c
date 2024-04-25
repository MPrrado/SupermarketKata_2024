#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Producto
{
    int id;
    char * descripcion;
    float precio
};

typedef struct Producto Producto;

Producto* crearProducto (int id, char * descripcion, float precio);
int generadorID(int id);


char nombres[3][50] = {"leche serenisima 1l","Frutilla 500 Gr", "Arándano 125 Gr"};

int main () 
{
    Producto *productos[20];
    for (int i = 0; i < 20; i++)
    {
        productos[i] = crearProducto(i, nombres[rand()%3], 100 + rand() %3001);
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%d- %s ",productos[i]->id, productos[i]->descripcion);
        printf("\n");
    }
    

    return 0;
}

Producto *crearProducto(int id, char *descripcion, float precio)
{
    Producto *producto = (Producto*) malloc(sizeof(Producto));
    producto->id=id;
    producto->descripcion = (char *) malloc((strlen(descripcion)+1) * sizeof(char));
    strcpy(producto->descripcion, descripcion);
    producto->precio = precio;
    return producto;
}

int generadorID(int id)
{
    return id++;
}
