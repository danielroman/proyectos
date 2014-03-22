#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define SIZE 10


//Funcion para rellenar las 2 variables de la sopa de letras
void rellenar(char sopa[SIZE][SIZE], int sopa_vacia[SIZE][SIZE]){


    for (int fila = 0; fila < SIZE; fila++)
	for (int col = 0; col < SIZE; col++){
	    sopa[fila][col] = (char) (rand() % ('z' - 'a') + 'a');
	    sopa_vacia[fila][col] = 0;
	}
}


//Funcion para Generar la posicion y la direccion de la palabra dentro de la sopa de letras
int posicion(char sopa[SIZE][SIZE], int sopa_vacia[SIZE][SIZE], char *palabra, int longitud){

    //Valores de la direccion
    // 0 = derecha; 1 = izquierda; 2 = arriba; 3 = abajo; 4 = derecha, abajo; 5 = derecha, arriba;
   // 6 = izquierda, arriba; 7 = izquierda, abajo; 
    rellenar(sopa, sopa_vacia);
    int direccion = rand() % 8;
    int posicion_fila = rand() % 10;
    int posicion_col = rand() % 10;

    if (direccion == 0)
	for (int letra = 0; letra < longitud; letra++, posicion_col++){
	    sopa[posicion_fila][posicion_col] = palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}

    if (direccion == 1)
	for (int letra = 0; letra < longitud; letra++, posicion_col--){
	    sopa[posicion_fila][posicion_col] = palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}

    if (direccion == 2)
	for (int letra = 0; letra < longitud; letra++, posicion_fila++){
	    sopa[posicion_fila][posicion_col] =  palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}

    if (direccion == 3)
	for (int letra = 0; letra < longitud; letra++, posicion_fila--){
	    sopa[posicion_fila][posicion_col] =  palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}

    if (direccion == 4)
	for (int letra = 0; letra < longitud; letra++, posicion_col++, posicion_fila++){
	    sopa[posicion_fila][posicion_col] =  palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}

    if (direccion == 5)
	for (int letra = 0; letra < longitud; letra++, posicion_col++, posicion_fila--){
	    sopa[posicion_fila][posicion_col] =  palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}

    if (direccion == 6)
	for (int letra = 0; letra < longitud; letra++, posicion_col--, posicion_fila++){
	    sopa[posicion_fila][posicion_col] =  palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}

    if (direccion == 7)
	for (int letra = 0; letra < longitud; letra++, posicion_col--, posicion_fila--){
	    sopa[posicion_fila][posicion_col] =  palabra[letra];
	    sopa_vacia[posicion_fila][posicion_col] = 1;
	}
}

//Funcion que me muestra la palabra que introdujo el usuario, su direccion, y su posicion dentro de la sopa
void mostrar(char sopa[SIZE][SIZE], char *palabra, int longitud, int direccion, int posicion_fila, int posicion_col){

    int sopa_vacia[SIZE][SIZE];
    rellenar(sopa, sopa_vacia);
    posicion(sopa, sopa_vacia, palabra, longitud/*, posicion_fila, posicion_col*/);

    for (int filas = 0; filas < SIZE; filas++){ 
	for (int col = 0; col < SIZE; col++)
	    printf("%c ", sopa[filas][col]);
	printf("\n");
    }
    printf("\n");
    for (int fila = 0; fila < SIZE; fila++){
	for (int col = 0; col < SIZE; col++)
	    printf("%i ", sopa_vacia[fila][col]);
	printf("\n");
    }
    printf("Palabra = %s Longitud = %i Direccion = %i\n", palabra, longitud, direccion);
}


int main (int argc, char *argv[]){

    char celdas[SIZE][SIZE];
    int sopa_vacia[SIZE][SIZE];

    char palabra[5];
    int posicion_fila = 5;
    int posicion_col;
    int direccion;
    int longitud = 0;
    srand(time(NULL));


    printf("Introduzca una palabra: ");
    scanf(" %s", palabra);

    direccion = rand() % 8;
    longitud = strlen(palabra);
    posicion_col = rand() % 10;

    int suma = longitud + posicion_col;

// | posibles maneras de limitar la insercion de la palabra (codigo en revision)
// v

    //Rellenamos la sopa
    for (int fila = 0; fila < SIZE; fila++)
	for (int col = 0; col < SIZE; col++){
	    celdas[fila][col] = (char) (rand() % ('z' - 'a') + 'a');
	    sopa_vacia[fila][col] = 0;
	}
    //Comprobamos que la palabra quepa
    do{

	if (suma <= SIZE){
	    for (int letra = 0; letra < longitud; letra++, posicion_col++){
		celdas[posicion_fila][posicion_col] = palabra[letra];
		sopa_vacia[posicion_fila][posicion_col] = 1;
	    }
	}else
	    posicion_col = rand() % 10;

	}while(suma > SIZE);
    
    //mostramos el resultado de la sopa
    for (int fila = 0; fila < SIZE; fila++){ 
	for (int col = 0; col < SIZE; col++)
	    printf("%c ", celdas[fila][col]);
	printf("\n");
    }
 
    printf("\n");
 
    for (int fila = 0; fila < SIZE; fila++){
	for (int col = 0; col < SIZE; col++)
	    printf("%i ", sopa_vacia[fila][col]);
	printf("\n");
    }

    printf("\n columna %i", posicion_col);


// ^
// |  Fin de codigo en revision

//Con la funcion mostrar vemos el contenido pero todavia no la inserta de manera adeacuada codigo en revision
//    mostrar(celdas, palabra, longitud, direccion, posicion_fila, posicion_col);



	return EXIT_SUCCESS;     
} 
