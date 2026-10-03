#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
	int Direccion;
	int Medicion;
	char UdeMedida[20];
};
struct Nodo *nodos = NULL;      //Cambio para memoria dinamica  struct Nodo nodos[124] e inicializar en NULL para evitar que empiece con basura
struct Nodo *temp;       //Puntero auxiliar
void Cargar(struct Nodo *nodo);   //Prototipo de función
void Mostrar(struct Nodo *nodo);  //Prototipo de función
int ValidarU(char unidad[]);  //Función para ver la unidad de medida
void Mayusculas(char cadena[]); //Función para convertir las cadenas en mayusculas y no tener problemas
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
			if(cargado == 1){     //Bloque para evitar que se carguen datos si es que ya se cargaron, para eso esta el case de agregar
				printf("Los datos ya fueron cargados.\n");
				break;
			}
			printf("Ingrese la cantidad de nodos a usar (entre 1 y 124): ");
			scanf("%d", &N);
			while (N < 1 || N > 124) {
				printf("Cantidad invalida, debe estar entre 1 y 124.\n");
				printf("Ingrese la cantidad de nodos: ");
				scanf("%d", &N);
			}
			nodos = malloc(N * sizeof(struct Nodo));
			if (nodos == NULL) {                //Mejora para verificar si se reservó memoria de forma correcta
				printf("No se pudo reservar memoria.\n");
				break;
			}
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
				while (nuevos < 1 || N + nuevos > 124) {                   //Mejora para evitar problemas con la validación del 0 o números negativos
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
			}else{
				printf("Primero debe cargar los datos\n");
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
	Mayusculas(nodo->UdeMedida);                 //LLamada para convertir en Mayusculas
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
		void Mayusculas(char cadena[]) {                   //Función para las mayusculas
			int i;
			
			for (i = 0; cadena[i] != '\0'; i++) {
				if (cadena[i] >= 'a' && cadena[i] <= 'z') {
					cadena[i] = cadena[i] - 32;
				}
			}
		}
		
	void BuscarUnidad(struct Nodo *nodos, int N) {
		char unidadBuscada[20];
		int encontrado = 0;             //Variable para verificar si la cadena existe, sino se avisa(antes no pasaba)
			
			printf("Ingrese la unidad que desea buscar(TEMP, HUM, PRES): ");
			scanf("%19s", unidadBuscada);
			Mayusculas(unidadBuscada);         //La función que pone en mayusculas para evitar problemas
			
			for (int i = 0; i < N; i++) {
				if (strcmp(nodos[i].UdeMedida, unidadBuscada) == 0) {
					Mostrar(&nodos[i]);
					encontrado = 1;
				}
			}
			if (encontrado == 0) {
				printf("No se encontraron nodos con esa unidad de medida.\n");
			}
		}
