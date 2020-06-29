#include<stdio.h>
#include<stdlib.h>

//estructuras
struct nodo{
	char doc[100];
	int prio;
	struct nodo* sig;
	
};

struct cabecera{
	struct nodo *I;
	struct nodo *F;
};

//alias
typedef struct nodo NODO;
typedef struct cabecera CAB;
typedef CAB *cola;
typedef NODO *liga;
typedef enum m{NO_MEMORY,OK} mensaje;
typedef enum b{FALSE,TRUE} boolean;

//prototipos
mensaje inicola(cola *c);
void clearcola(cola c);
void liberarcola(cola *c);
mensaje encolar(cola c,NODO);
NODO desencolar(cola c);
boolean isempty(cola c);
void printcola(cola);


mensaje inicola(cola *c){
	cola temp= NULL;

	temp=(cola)malloc(sizeof(CAB));
	if(temp==NULL)
		return NO_MEMORY;
	temp->I=NULL;
	temp->F=NULL;
	*c=temp;
	temp=NULL;
	return OK;
}

void clearcola(cola c){
	while (!isempty(c)){
		desencolar(c);
	}
}

void liberarcola (cola *c){
	clearcola (*c);
	free(*c);
	*c=NULL;
}

mensaje encolar(cola c, NODO N){
	liga temp=NULL;
	liga aux1=NULL,aux2=NULL;
	temp=(liga)malloc(sizeof(NODO));

	if(temp==NULL){
		exit (0);
		return NO_MEMORY;
	}
	*temp=N;

	if(isempty(c)){
		c->I=c->F=temp;
		temp->sig=NULL;
	}
	else{			//hay almenos un elemento
		if(N.prio>(c->I->prio)){
			temp->sig=c->I;
			c->I=temp;
		}else 
			if(N.prio<=c->F->prio){ //inserta al ultimo
            	temp->sig=NULL;
            	c->F->sig=temp;
            	c->F=temp;
			}
			else{  //enmedio
				aux1=NULL;
				aux2=c->I;
			while(N.prio<=aux2->prio){
				aux1=aux2;
				aux2=aux2->sig;
			}
			temp->sig=aux2;
			aux1->sig=temp;
		}
		return OK;
	}
}

NODO desencolar(cola c){
	NODO copia;
	if (isempty(c)){
		printf("\nERROR:COLA VACIA!!\n");
		exit(0);
	}		
	else{
		
		copia =*(c->I);
		if(c->I->sig==NULL){
		free(c->F);
		c->I=c->F=NULL;
		}
		else{
		free (c->I);
		c->I=copia.sig;
		}
	}
copia.sig=NULL;
return copia;
}

boolean isempty(cola c){
	if(c->I==NULL && c->F==NULL)
		return TRUE;
	return FALSE;
}

void printcola(cola c){
	liga aux;
	if(isempty(c))
		printf("\n cola de impresion vacia \n");
	aux=c->I;
	while(aux!=NULL){
		puts(aux->doc);
		aux=aux->sig;
	}
	printf("\n");
}
