#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int Direccion;
	int Medicion;
	char UdeMedida[20];
};
struct Nodo nodos[124];

void Cargar(struct Nodo *nodo);   //Prototipo de función


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
	
	
	
	return 0;
}



void Cargar(struct Nodo *nodo) {  //Función para cargar datos
	printf("Direccion: ");
	scanf("%d", &nodo->Direccion);
	
	while (nodo->Direccion < 1 || nodo->Direccion > 124) {
		printf("Direccion invalida, debe estar entre 1 y 124.\n");
		printf("Direccion: ");
		scanf("%d", &nodo->Direccion);
	}
	
	printf("Medicion: ");
	scanf("%d", &nodo->Medicion);
	
	printf("Unidad de medida (TEMP, HUMEDAD, PRESION): ");
	scanf("%19s", nodo->UdeMedida);
}
