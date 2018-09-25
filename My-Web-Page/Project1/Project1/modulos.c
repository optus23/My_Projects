#include <stdio.h>
#include <time.h>
#include "prototipo.h"

char apuestaUsuario() {
	char i, x=0;
	do {
		printf("Dame Piedra (p), Papel(a) o Tijera(t): ");
		scanf_s(" %c", &i);
		if (i == 'p' || i == 'a' || i == 't') {
			printf("Has elegido: <%c>\n", i); x = 1;
		}
		else printf("<%c> no es una opcion valida\n", i);
	} while (x==0);
	return i;

}
char piedraPapelTijera() {
	int valor;
	srand(time(NULL));
	valor = (rand() % 2);
	if (valor == 0) valor = 'p';
	else if (valor == 1) valor = 'a';
	else if (valor == 2) valor = 't';
	printf("La maquina elige: <%c>\n", valor);
	return valor;
}
void comprobar(char i, char valor, int *g, int *p) {
		if (i == valor) printf("empate\n");
		else if (i == 'p' && valor == 'a') { printf("Piedra pierde contra Papel\n"); (*p)++; }
		else if (i == 'p' && valor == 't') { printf("Piedra gana a Tijera\n"); (*g)++; }
		else if (i == 'a' && valor == 'p') { printf("Papel gana a Piedra\n"); (*g)++; }
		else if (i == 'a' && valor == 't') { printf("Papel pierde contra Tijera\n"); (*p)++; }
		else if (i == 't' && valor == 'p') { printf("Tijera pierde contra Piedra\n"); (*p)++; }
		else if (i == 't' && valor == 'a') { printf("Tijera gana a Papel\n"); (*g)++; }
}