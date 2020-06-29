#include<stdio.h>
#include<conio.h>
#include "coladeprioridad.h"
void menu();
void main(){
	int opc;
	cola cp;
	NODO A;
	inicola(&cp);
	do{
	menu();
	scanf("%d",&opc);
	fflush(stdin);
	switch(opc){
		case 1:
		printf("Nombre del documento del alumno:\n");
		gets(A.doc);
		A.prio=1;
		encolar(cp,A);		
		break;

		case 2:
		printf("Nombre del documento del maestro:\n");
		gets(A.doc);
		A.prio=2;
		encolar(cp,A);		
		break;

		case 3:
		printf("Nombre del documento del director:\n");
		gets(A.doc);
		A.prio=3;
		encolar(cp,A);		
		break;

		case 4: 
		printf("\nDocumentos: \n\n");
		printcola(cp);
		break;

		case 5: printf("\nFin del programa.\n");
		printf("GRACIAS...");
		exit(0); 

		default: printf("\nOpcion no valida\n");
		break;
	}

}while(opc!=5);
}


void menu(){
	printf("\nIMPRESIONES \n");
	printf("\n1 Alumno");
	printf("\n2 Maestro");
	printf("\n3 Director");
	printf("\n4 Mostrar cola de impresion");
	printf("\n5 Salir");
	printf("\n\n Ingrese la opcion deseada: ");
}


