#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
	int Direccion;
	int Medicion;
	char UdeMedida[20];
};
struct Nodo nodos[124];

void Cargar(struct Nodo *nodo);   //Prototipo de función
void Mostrar(struct Nodo *nodo);  //Prototipo de función
int ValidarU(char unidad[]);  //Función para ver la unidad de medida
int main(int argc, char *argv[]) {
	int N, i;
	printf("Ingrese la cantidad de nodos a usar (entre 1 y 124): ");
	scanf("%d", &N);
	while (N < 1 || N > 124) {
		printf("Cantidad invalida, debe estar entre 1 y 124.\n");
		printf("Ingrese la cantidad de nodos: ");
		scanf("%d", &N);
	}
	
	for (int i = 0; i < N; i++) {
		printf("\nNodo %d\n", i + 1);
		Cargar (&nodos[i]);
	}
	
	for (int i = 0; i < N; i++) {
		printf("\nNodo %d\n", i + 1);
		Mostrar(&nodos[i]);
	}
	
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
