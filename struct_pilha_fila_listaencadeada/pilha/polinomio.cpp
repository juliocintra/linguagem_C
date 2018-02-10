#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define tamanho 10
#define tamanho1 20

void somaPolinomio(int a[tamanho], int b[tamanho], int c[tamanho]) {
	
	int p, q, r, m, n;
	
	//p - percorre o polinomio A
	//q - percorre o polinomio b
	//r - percorre o polinomio c
	//m - numero de coeficientes diferences de zero do polinomio A; = a[0] = 4
	//n - numero de coeficientes diferentes de zero do polinomio B; = b[0] = 3
	
	m = a[0];
	n = b[0];
	
	p = q = r = 1;
	
	while(p < 2 *m && q < 2 *n) {
		
			if (a[p] == b[q]) {                   
				c[r + 1] = a[p + 1] + b[q + 1]; //se os expoentes forem iguais, somam os coeficientes;
				
				if (c[r + 1] != 0) {
					c[r] = a[p];
					r = r + 2;
				}
				p = p + 2;
				q = q + 2;
			}
		
		else if (a[p] < b[q]) {
			c[r + 1] = b[q + 1];
			c[r] = b[q];
			r = r + 2;
			q = q + 2;
		}
		else if (a[p] > b[q]) {
			c[r + 1] = a[p + 1];
			c[r + 1] = a[p];
			p = p + 2;
		}
	}
	
	while(p < 2 *m) {
		c[r + 1] = a[p + 1];
		c[r] = a[p];
		r = r + 2;
		p = p + 2;
	}
	
	while(q < 2 *n) {
		c[r + 1] = b[q + 1];
		c[r] = b[q];
		r = r + 2;
		q = q + 2;
	}
	
	c[0] = r / 2;
}

void mostra(int a[]) {
	int i, m;
	m = 2 *a[0];
	
	printf("\n");
	
	for (i = 1; i <= m; i = i + 2) {
		
		printf("%dX^%d", a[i + 1], a[i]);
		
		if (i < m - 1)
			printf("  +  ");
	}
	
	printf("\n");
}

main() {
	int a[tamanho] = {4, 5, 10, 3, 3, 2, 4, 1, 2}; //10x^5 + 3x^3 + 4x^2 + 2x
	int b[tamanho1] = {3, 2, 3, 1, -2, 0, 4}; // 3x^2 - 2x + 4
	
	int c[tamanho1];
	
	somaPolinomio(a, b, c);
	mostra(a);
	mostra(b);
	mostra(c);
	getch();
}
