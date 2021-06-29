#include<stdio.h>
 int main()
{
   int i, j, nProc, pos, tem, tEjec[20], prio[20], tEsp[20], tLleg[20], total=0;
   float tPromEs, tPromRes;

   printf("Ingresa el numero de procesos: ");
   scanf("%d", &nProc);

   printf("Ingresa el tiempo de ejecucion del proceso: ");
   for (i=0; i<nProc; i++) //De acuerdo al la cantidad de procesos ingresados, se irán pidiendo el tiempo de ejecución
   {
     printf ("\n proceso%d: ", i+1); //Aquí se irán ingresando los tiempos de ejecución de cada proceso
     scanf("%d", &tEjec[i]); //Guarda los datos ingresados del tiempo de ejecución del proceso en el vector  tEjec
     prio[i]= i + 1;
   }

//prioridad de los tiempos de ejecución de cada proceso
  for(i=0; i<nProc;i++) //para i
   {
    pos=i;
    for (j=i+1; j<nProc;j++)
     {
      if (tEjec[j] < tEjec[pos]) //si el tiempo de ejecución en j es menor que el tiempo de ejecución de la posición
            pos=j; //la posició será igual a j
     }

    tem= tEjec[i];
    tEjec[i]= tEjec[pos];
    tEjec[pos]= tem;


    tem= prio[i];
    prio[i] = prio[pos];
    prio[pos]=tem;

   }
    tEsp[0]=0; //al tiempo de Espera, le asignamos el valor de 0, en la posición 0

    for (i=1;i<nProc; i++) //iniciamos el ciclo, para i, hasta que llegue al número de procesos
    {
    tEsp[i]=0;  //asignamos un valor de cero a cada ubicación del arreglo e iniciamos otro ciclo
    for (j=0; j<i;j++) //hasta que j, sea igual al valor del tiempo de Espera ingresado
          tEsp[i]+=tEjec[j]; //El tiempo de espera es igual al Tiempo de espera más el tiempo de ejecución
            total+=tEsp[j];  //el total es igual a total + tEspera
    }

     tPromEs = (float) total/nProc;
     total= 0;


     printf("\n No.Proceso   Tiempo Espera   T.Prom. Espera   T.Prom. Respuesta");
     for(i=0; i<nProc; i++)
      {
       tLleg[i]= tEjec[i] + tEsp[i];
       total+=tLleg[i];
       printf("\n Proc:%dtt       %dttt%d", prio[i], tEjec[i], tEsp[i], tLleg[i]);

      }




}
