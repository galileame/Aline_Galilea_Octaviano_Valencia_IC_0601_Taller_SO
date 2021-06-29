#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 100

typedef struct elemento{
  char fichero[MAX];
  struct elemento *signo;
}Nodo;
typedef struct {
  char fichero[MAX];
}ficheros;

Nodo *crear_lista(Nodo *lista); 
Nodo *agregar_elemento(Nodo *lista, char *fichero); 
void ordenar_elementos(Nodo *lista); 
ficheros array_ordenado[2000];
int c=0;

int main(int argc, char *argv[]){
  Nodo *lista_enlazada = crear_lista(lista_enlazada);
  FILE *f_entrada, *f_salida;
  char fichero[MAX];
  f_entrada = fopen(argv[1],"r");

  if(f_entrada == NULL){
    printf("No existe el fichero");
    fclose(f_entrada);
  }else{
    while(!feof(f_entrada)){
      fscanf(f_entrada,"%s",fichero);
      if(strcmp(fichero,"") != 0){
	  lista_enlazada = agregar_elemento(lista_enlazada,fichero);
      }
      memset(fichero,0,MAX);
    }
  }
  ordenar_elementos(lista_enlazada);
  fclose(f_entrada);
  f_salida = fopen(argv[2],"w");
  printf("Abriendo/creando fichero llamado : %s\nOrdenando...\n",argv[2]);
  for(int i=0; i<=c; i++){
    strcpy(fichero,array_ordenado[i].fichero);
    if(strcmp(fichero,"") != 0){
      fprintf(f_salida,"%s\n",fichero);
    }
  }
  printf("Fichero \"%s\" Ordenado de manera correcta\n",argv[2]);
  fclose(f_salida);
}

Nodo *crear_lista(Nodo *lista){
  lista = NULL;
  return lista;
};
Nodo *agregar_elemento(Nodo *lista, char *fichero){
  Nodo *nuevo_Elemento, *aux;
  nuevo_Elemento = (Nodo*)malloc(sizeof(Nodo));
  strcpy(nuevo_Elemento->fichero,fichero);
  nuevo_Elemento->signo = NULL;
  if(lista == NULL){
    lista = nuevo_Elemento;
  }else{
    aux = lista;
    while(aux->signo != NULL){ 
      aux = aux->signo;
    }
    aux->signo = nuevo_Elemento;
  }
  return lista;
};
void ordenar_elementos(Nodo *lista){
  ficheros array[1000];

  while(lista->signo != NULL){
    strcpy(array[c].fichero,lista->fichero);
    lista = lista->signo;
    c++;
  }
  strcpy(array[c].fichero,lista->fichero);

  char temp[MAX];
  for(int i=0; i<c; i++){
    for(int j=0; j<c; j++){
      if(strcmp(array[j].fichero,array[j+1].fichero) >= 0){
	strcpy(temp,array[j].fichero);
	strcpy(array[j].fichero,array[j+1].fichero);
	strcpy(array[j+1].fichero,temp);
      }
    }
  } 
  for(int i=0; i<=c; i++){
    if(strcmp(array[i].fichero,"") != 0){
      strcpy(array_ordenado[i].fichero,array[i].fichero);
      printf("fichero [ %s ]\n",array_ordenado[i].fichero);
    }
  }
};
