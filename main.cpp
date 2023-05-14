#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo{
    int valor;
    Nodo *next;
}Nodo;

Nodo *crearNodo(int valor){
    Nodo *nodo;
    nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->valor=valor;
    nodo->next=NULL;
    return nodo;
}

void agregarElemento(Nodo **lista, int valor) {
    Nodo *nodoNuevo = crearNodo(valor);
    if (*lista == NULL) {
        *lista = nodoNuevo;
    } else {
        Nodo *cursor = *lista;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = nodoNuevo;
    }
}

Nodo *buscarElemento(Nodo **lista, int valor){
    Nodo *cursor = *lista;
    while(cursor != NULL){
        if(cursor->valor == valor){
            return cursor;
        }else{
            cursor = cursor->next;
        }
    }
    return NULL;
}

void eliminarElemento(Nodo **lista, int valor){
    if(*lista == NULL){
        printf("La lista esta vacia!");
    }
    else if(buscarElemento(lista,valor) == NULL){
        printf("El valor no esta en la lista!");
    }else{
        Nodo *cursor = *lista;
        while(cursor != NULL){
          if(cursor->next->valor == valor){
              //Nodo * aux = cursor->next;
              *lista = cursor->next->next;
          }
          cursor = cursor->next;
        }
    }

}

int contarElementos(Nodo **lista){
    int i=0;
    Nodo *cursor = *lista;
    while(cursor != NULL){
        i++;
        cursor = cursor->next;
    }
    return i;
}

void mostrarElementos(Nodo **lista){
    Nodo *cursor = *lista;
    while(cursor != NULL){
        printf("%d, ",cursor->valor);
        cursor = cursor->next;
    }
}

int main(){
    Nodo *lista = NULL;

    agregarElemento(&lista, 5);
    agregarElemento(&lista, 3);
    agregarElemento(&lista, 9);
    agregarElemento(&lista, 6);

    int i = contarElementos(&lista);
    printf("La cantidad de elementos de la lista es: %d\n",i);

    Nodo *nodo = buscarElemento(&lista,5);
    printf("El valor 5 esta en el nodo: %p\n",nodo);

    Nodo *nodo_2 = buscarElemento(&lista,6);
    printf("El valor 6 esta en el nodo: %p\n",nodo_2);

    mostrarElementos(&lista);
    eliminarElemento(&lista,9);
    mostrarElementos(&lista);

}
