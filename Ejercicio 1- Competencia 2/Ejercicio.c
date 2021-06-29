#include <stdio.h>
#include <stdlib.h>

int main(){
int x;
int y;
int *puntero; 
int *punteros; 
puntero = &x; 

printf("El valor de *puntero es: %d. \n",x,*puntero);
*puntero +1;
printf("El valor de *puntero es: %d. \n",x,*puntero);
*puntero +2;
printf("El valor de *puntero es: %d. \n",x,*puntero);
*puntero +3;
printf("La direccion de memoria de *puntero es: %p",punteros);

return 0;
}