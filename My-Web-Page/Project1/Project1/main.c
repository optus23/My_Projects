#include <stdio.h>
#include "prototipo.h"

int main() {
	int p, g, cp=0,cg=0;
	char r;
	do {
		p = 0;
		g = 0;
		do {
			comprobar(piedraPapelTijera(), apuestaUsuario(), &p, &g);
			printf("Usuario: %i\n", g);
			printf("Maquina: %i\n", p);
		} while (g != 2 && p != 2);
		if (p == 2) {
			cp++;
		}
		else
			cg++;
		printf("Quiere volver a ejecutar el programa? Si<s> No<n>");
		scanf_s(" %c", &r);
	} while (r == 's');
	printf("Partidas totales: %i\n", cp + cg);
	printf("Partidas totales ganada: %i\n", cg);
	printf("Partidas totales perdidas: %i\n", cp);
	system("pause");
	return 0;
}