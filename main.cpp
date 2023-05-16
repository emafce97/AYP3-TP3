#include <iostream>

typedef struct Nodo{
    int valor;
    Nodo *sgte;
}Nodo;

typedef struct Lista{
    Nodo *cabeza;
    int cantElementos;
}Lista;

/*
 * Crea una instancia de lista
 */
Lista crearLista(){
    Lista lista;
    lista.cabeza = NULL;
    lista.cantElementos = 0;
    return lista;
}

/*
 * Crea una instancia de Nodo
 */
Nodo *crearNodo(int valor){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->valor = valor;
    nodo->sgte = NULL;
    return nodo;
}

/*
 * Añade un elemento de manera secuencial
 */
void añadirElemento(Lista *lista,Nodo **cabeza, int valor){
    Nodo *nuevo = crearNodo(valor);
    if(*cabeza == NULL){
        *cabeza = nuevo;
    }else{
        Nodo *puntero = *cabeza;
        while(puntero->sgte != NULL){
            puntero = puntero->sgte;
        }
        puntero->sgte = nuevo;
    }
    lista->cantElementos++;
}

/*
 * Imprime la lista mostrando los elementos
 */
void imprimirLista(Nodo **cabeza){
    Nodo *puntero = *cabeza;
    printf("[");
    while(puntero != NULL){
        if(puntero->sgte == NULL){
            printf("%d",puntero->valor);
        }else{
            printf("%d, ",puntero->valor);
        }
        puntero = puntero->sgte;
    }
    printf("]\n");
}

/*
 * Busca si algun nodo tiene el valor buscado
 * El metodo retorna un puntero, la referencia de memoria del nodo
 */
Nodo *buscarElemento(Nodo **cabeza,int valor_buscado){
    Nodo *puntero = *cabeza;
    if(*cabeza == NULL){
        printf("ERROR: La lista esta vacia!");
    }else{
        while(puntero != NULL){
            if(puntero->valor == valor_buscado){
                return puntero;
            }else{
                puntero = puntero->sgte;
            }
        }
    }
    return NULL;
}

/*
 * Retorna la cantidad de elementos en la lista
 */
int contarElementos(Lista *lista){
    return lista->cantElementos;
}

/*
 * Elimina un elemento de la lista
 */
void eliminarElemento(Nodo **cabeza,int valor_eliminar){
    if(buscarElemento(cabeza,valor_eliminar) == NULL){
        printf("El elemento no esta en la lista!");
    }else{
        Nodo *cursor = *cabeza;
        while(cursor->sgte != NULL){
            if(cursor->sgte->valor == valor_eliminar){
                Nodo *aux = cursor->sgte->sgte;
                free(cursor->sgte);
                cursor->sgte=aux;
            }else{
                cursor = cursor->sgte;
            }
        }
    }
}

int main() {
    Lista lista = crearLista();
    Nodo *cabeza = lista.cabeza;
    añadirElemento(&lista,&cabeza,3);
    añadirElemento(&lista,&cabeza,2);
    añadirElemento(&lista,&cabeza,1);
    añadirElemento(&lista,&cabeza,4);
    añadirElemento(&lista,&cabeza,-99);
    añadirElemento(&lista,&cabeza,-200);
    printf("La lista tiene %d elementos\n", contarElementos(&lista));
    imprimirLista(&cabeza);
    printf("El nodo con valor 1 tiene la dic de memoria %p\n", buscarElemento(&cabeza,1));
    eliminarElemento(&cabeza,1);
    imprimirLista(&cabeza);
    eliminarElemento(&cabeza,-200);
    imprimirLista(&cabeza);
    return 0;
}