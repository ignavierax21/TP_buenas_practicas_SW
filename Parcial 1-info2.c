#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int Direccion;
	int Medicion;
	char UdeMedida[20];
};
struct Nodo nodos[124];

int main(int argc, char *argv[]) {
	int N, i;
	printf("Ingrese la cantidad de nodos a usar(entre 1 y 124): ");
	scanf("%d",&N);
	while (N < 1 || N> 124) {
		printf("Cantidad invalida, debe estar entre 1 y 124.\n");
		printf("Ingrese la cantidad de nodos: ");
		scanf("%d", &N);
	}
	for(i = 0; i < N; i++){
		printf("Nodo %d \n", i+1);
		
		printf("Direccion: ");
		
		scanf("%d", &nodos[i].Direccion);
		
		while (nodos[i].Direccion < 1 || nodos[i].Direccion > 124) {
			printf("Direccion invalida, debe estar entre 1 y 124.\n");
			printf("Direccion: ");
			scanf("%d", &nodos[i].Direccion);
		}
		
		printf("Medicion: ");
		scanf("%d", &nodos[i].Medicion);
		
		printf("Unidad de medida(TEMP, HUMEDAD, PRESION): ");
		scanf("%19s", nodos[i].UdeMedida);
	}
	printf("Nodos agregados \n");
	
	for (int i = 0; i < N; i++) {
		printf("\nNodo %d\n", i + 1);
		printf("Direccion: %d\n", nodos[i].Direccion);
		printf("Medicion: %d\n", nodos[i].Medicion);
		printf("Unidad de medida: %s\n", nodos[i].UdeMedida);
	}
	
	
	
	return 0;
}
