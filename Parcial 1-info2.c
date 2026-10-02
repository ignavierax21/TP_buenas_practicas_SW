#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
	int Direccion;
	int Medicion;
	char UdeMedida[20];
};
struct Nodo *nodos;      //Cambio para memoria dinamica  struct Nodo nodos[124];
struct Nodo *temp;       //Puntero auxiliar
void Cargar(struct Nodo *nodo);   //Prototipo de función
void Mostrar(struct Nodo *nodo);  //Prototipo de función
int ValidarU(char unidad[]);  //Función para ver la unidad de medida
void BuscarUnidad(struct Nodo *nodos, int N);  //Función para buscar la medida pedida
int main(int argc, char *argv[]) {
	int N, i, op, nuevos;
	int cargado = 0;
	do{                                  //Menu para opciones
		printf("\nElija una opcion\n");
		printf("1-Cargar Datos\n");
		printf("2-Mostrar Datos\n");
		printf("3-Agregar Datos\n");
		printf("4-Buscar medida\n");
		printf("5-Salir\n");
		scanf("%d", &op);
		switch(op){
		case 1:
			printf("Ingrese la cantidad de nodos a usar (entre 1 y 124): ");
			scanf("%d", &N);
			while (N < 1 || N > 124) {
				printf("Cantidad invalida, debe estar entre 1 y 124.\n");
				printf("Ingrese la cantidad de nodos: ");
				scanf("%d", &N);
			}
			nodos = malloc(N * sizeof(struct Nodo));
			for (i = 0; i < N; i++) {
				printf("\nNodo %d\n", i + 1);
				Cargar (&nodos[i]);
			}
			cargado = 1;
			break;
			
		case 2:
			if(cargado == 1){
			for ( i = 0; i < N; i++) {
				printf("\nNodo %d\n", i + 1);
				Mostrar(&nodos[i]);
			 }
			} else{
				printf("Primero debe cargar los datos\n");
			}
			break;
		case 3:                         //Case para agregar datos
			if(cargado == 1){
				printf("Ingrese la cantidad de nodos que quiere agregar: ");
				scanf("%d", &nuevos);
				while (N + nuevos > 124) {
					printf("No puede agregar esa cantidad. El maximo es 124.\n");
					printf("Ingrese nuevamente la cantidad: ");
					scanf("%d", &nuevos);
				}
				temp = realloc(nodos, (N + nuevos) * sizeof(struct Nodo));         //para la memoria dinamica
				
				if (temp != NULL) {
					nodos = temp;
					
					for (i = N; i < N + nuevos; i++) {
						printf("\nNodo %d\n", i + 1);
						Cargar(&nodos[i]);
					}
					
					N = N + nuevos;
				} else {
					printf("No se pudo reservar memoria.\n");
				}
			}
			break;
			
		case 4:                            //Case para buscar unidades
			if(cargado == 1){
				BuscarUnidad(nodos, N);
			}
			else{
				printf("Primero debe cargar los datos\n");
			}
			break;
		}
	}while(op != 5);
	free (nodos);
	
	return 0;
}


void Cargar(struct Nodo *nodo) { //Función para cargar datos
	int tipo;
	printf("Direccion: ");
	scanf("%d", &nodo->Direccion);
	
	while (nodo->Direccion < 1 || nodo->Direccion > 124) {
		printf("Direccion invalida, debe estar entre 1 y 124.\n");
		printf("Direccion: ");
		scanf("%d", &nodo->Direccion);
	}
	
	printf("Medicion: ");
	scanf("%d", &nodo->Medicion);
	
	do{                                                //Bloque para verificar la unidad
		
	printf("Unidad de medida (TEMP, HUM, PRES): ");  //Cambio en forma de escribir las unidades (nada importante)
	scanf("%19s", nodo->UdeMedida);
	tipo = ValidarU(nodo->UdeMedida);
	
	if(tipo == 0){
		printf("Unidad invalida, debe ser TEMP, HUM o PRES\n");
	}
	
	} while(tipo == 0);
}

void Mostrar(struct Nodo *nodo){   //Función de mostrar con -> por ser estructura y por referencia
	printf("Direccion: %d\n", nodo->Direccion);
	printf("Medicion: %d\n", nodo->Medicion);
	printf("Unidad de medida: %s\n", nodo->UdeMedida);
}

	int ValidarU(char unidad[]){     //Función para comparar cadenas y validar la unidad
		if(strcmp(unidad, "TEMP") == 0){
			return 1;
		}
		if(strcmp(unidad, "HUM") == 0){
			return 2;
		}
		if(strcmp(unidad, "PRES") == 0){
			return 3;
		}
		return 0;
    }
	void BuscarUnidad(struct Nodo nodos[], int N) {
		char unidadBuscada[20];
			
			printf("Ingrese la unidad que desea buscar: ");
			scanf("%19s", unidadBuscada);
			
			for (int i = 0; i < N; i++) {
				if (strcmp(nodos[i].UdeMedida, unidadBuscada) == 0) {
					Mostrar(&nodos[i]);
				}
			}
		}
