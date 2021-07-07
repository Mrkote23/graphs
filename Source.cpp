#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNING

#include "stdio.h"
#include <stdlib.h>
#include "conio.h"
#include "malloc.h"
#include <locale>

void Otoshdestvlenie(int** mac, int o) {


	printf("Отождествление вершин\n\n");

	int v1, v2;


	printf("Введите первую вершину для отождествления\n");
	scanf("%d", &v1);
	printf("Введите вторую вершину для отождествления\n");
	scanf("%d", &v2);


	for (int j = 0; j < o; j++) {

		mac[v2][j] = (mac[v1][j] + mac[v2][j]);
		if (mac[v2][j] == 2) {
			mac[v2][j] = 1;
		}

	}

	if (v2 <= (o / 2)) {

		for (int i = 0; i < o; i++) {

			for (int j = 0; j < o; j++) {

				mac[j][i] = mac[i][j];
				if (i == j) { mac[i][j] = 0; }
				if ((i == j) && (i == v2)) { mac[i][j] = 1; }


			}
		}

	}

	else {

		for (int i = o - 1; i >= 0; i--) {

			for (int j = o - 1; j >= 0; j--) {

				mac[j][i] = mac[i][j];
				if (i == j) { mac[i][j] = 0; }
				if ((i == j) && (i == v2)) { mac[i][j] = 1; }


			}
		}

	}


	int** massa = (int**)malloc((o) * sizeof(int*));
	for (int i = 0; i < o; i++) {
		massa[i] = (int*)malloc((o) * sizeof(int));
	}

	int** massa2 = (int**)malloc((o) * sizeof(int*));
	for (int l = 0; l < o - 1; l++) {
		massa2[l] = (int*)malloc((o) * sizeof(int));
	}


	for (int i = 0; i < o; i++) {

		for (int j = 0; j < o; j++) {

			if (i == v1) {

				break;
			}
			if (j == v1) {

				continue;
			}

			massa[i][j] = mac[i][j];
		}

	}

	int k = 0, l = 0, i = 0, j = 0;


	for (i = 0; i < o; i++) {

		for (j = 0; j < o; j++) {

			if (k >= (o - 1)) {
				l++;
				k = 0;
			}
			if (massa[i][j] >= 0) {
				massa2[l][k] = massa[i][j];
				k++;

			}
		}
	}

	for (int i = 0; i < o - 1; i++) {

		for (int j = 0; j < o - 1; j++) {

			printf("%d  ", massa2[i][j]);

		}
		printf("\n");
	}

}

void Styagivanie(int** mac1, int o1) {


	printf("Стягивание ребра\n\n");

	int v1, v2;
	int Pr = 0;
	while (Pr == 0) {
		printf("Введите первую вершину для отождествления\n");
		scanf("%d", &v1);
		printf("Введите вторую вершину для отождествления\n");
		scanf("%d", &v2);


		if (((v2 != v1 + 1) || (v1 != v2 - 1)) && ((v1 != v2 + 1) || (v2 != v1 - 1))) {
			printf("Стягивание ребра проводится только над смежными вершинами\n");
		}

		else {
			Pr++;
		}

	}

	for (int j = 0; j < o1; j++) {

		mac1[v2][j] = (mac1[v1][j] + mac1[v2][j]);
		if (mac1[v2][j] == 2) {
			mac1[v2][j] = 1;
		}


	}

	if (v2 <= (o1 / 2)) {

		for (int i = 0; i < o1; i++) {

			for (int j = 0; j < o1; j++) {

				mac1[j][i] = mac1[i][j];
				if (i == j) { mac1[i][j] = 0; }


			}
		}

	}

	else {

		for (int i = o1 - 1; i >= 0; i--) {

			for (int j = o1 - 1; j >= 0; j--) {

				mac1[j][i] = mac1[i][j];
				if (i == j) { mac1[i][j] = 0; }

			}
		}

	}



	int** massa3 = (int**)malloc((o1) * sizeof(int*));
	for (int i = 0; i < o1; i++) {
		massa3[i] = (int*)malloc((o1) * sizeof(int));
	}

	int** massa4 = (int**)malloc((o1) * sizeof(int*));
	for (int i = 0; i < o1 - 1; i++) {
		massa4[i] = (int*)malloc((o1) * sizeof(int));
	}


	for (int i = 0; i < o1; i++) {

		for (int j = 0; j < o1; j++) {

			if (i == v1) {
				break;
			}
			if (j == v1) {
				continue;
			}

			massa3[i][j] = mac1[i][j];

		}

	}

	int k = 0, l = 0, i = 0, j = 0;


	for (i = 0; i < o1; i++) {

		for (j = 0; j < o1; j++) {



			if (k >= (o1 - 1)) {
				l++;
				k = 0;
			}
			if (massa3[i][j] >= 0) {
				massa4[l][k] = massa3[i][j];
				k++;

			}
		}
	}

	printf("\n"); printf("\n"); printf("\n");
	for (int i = 0; i < o1 - 1; i++) {

		for (int j = 0; j < o1 - 1; j++) {

			printf("%d  ", massa4[i][j]);

		}
		printf("\n");
	}

}

void Rascheplenie(int** mac2, int o2) {

	printf("Расщепление вершины:\n\n");

	int Rv;

	printf("\nВведите вершину для расщепления\n");
	scanf("%d", &Rv);


	int* tempmas1 = (int*)malloc((o2) * sizeof(int));
	for (int j = 0; j < o2; j++) {

		if (j % 2 == 1) {
			tempmas1[j] = mac2[Rv][j];
			mac2[Rv][j] = 0;
			mac2[j][Rv] = 0;
		}
		if (j % 2 == 0) {
			tempmas1[j] = 0;
		}

		if (j == Rv) {
			tempmas1[j] = 1;
		}

	}


	int** massa5 = (int**)malloc((o2 + 1) * sizeof(int*));
	for (int i = 0; i < (o2 + 1); i++) {
		massa5[i] = (int*)malloc((o2 + 1) * sizeof(int));
	}

	int** massaTrans = (int**)malloc((o2 + 1) * sizeof(int*));
	for (int i = 0; i < (o2 + 1); i++) {
		massaTrans[i] = (int*)malloc((o2 + 1) * sizeof(int));
	}


	for (int i = 0; i < (o2 + 1); i++) {

		for (int j = 0; j < (o2 + 1); j++) {

			massa5[i][j] = mac2[i][j];
			if (i == Rv) {
				massa5[i][j] = tempmas1[j];
			}

		}
		if (i == Rv) {
			for (int k = o2; k > i; k--) {
				mac2[k] = mac2[k - 1];
			}
		}


	}

	printf("\n");


	for (int i = 0; i < o2 + 1; i++) {

		for (int j = 0; j < o2 + 1; j++) {

			massaTrans[i][j] = massa5[j][i];
		}

	}

	for (int j = 0; j < (o2 + 1); j++) {
		tempmas1[j] = massa5[Rv][j];

	}

	int* tempmas2 = (int*)malloc((o2) * sizeof(int));
	for (int i = 0; i < o2 + 1; i++) {
		tempmas2[i] = massaTrans[Rv][i];
	}


	for (int i = 0; i < (o2 + 1); i++) {

		for (int j = 0; j < (o2 + 1); j++) {

			if (i == Rv) {
				massaTrans[i][j] = tempmas1[j];
			}
		}
		if (i == Rv) {
			for (int k = o2; k > Rv; k--) {
				massaTrans[k] = massaTrans[k - 1];
			}
		}

	}

	for (int i = 0; i < o2 + 1; i++) {
		massaTrans[Rv][i] = tempmas2[i];
	}

	for (int i = 0; i < o2 + 1; i++) {

		for (int j = 0; j < o2 + 1; j++) {

			massa5[i][j] = massaTrans[j][i];

		}

	}

	printf("\n");
	for (int i = 0; i < o2 + 1; i++) {

		for (int j = 0; j < o2 + 1; j++) {

			if (i == j) {
				massa5[i][j] = 0;
			}
			massa5[j][Rv] = massa5[Rv][j];
			printf("%d  ", massa5[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");
}

void Peresechenie(int** mac3, int** mac4, int men, int bol) {

	printf("Пересечение графов:\n\n");


	int** massa6 = (int**)malloc((bol) * sizeof(int*));
	for (int i = 0; i < bol; i++) {
		massa6[i] = (int*)malloc((bol) * sizeof(int));
	}

	for (int i = 0; i < (bol); i++) {

		for (int j = 0; j < (bol); j++) {

			massa6[i][j] = mac4[i][j];
		}
	}

	for (int i = 0; i < (men); i++) {

		for (int j = 0; j < (men); j++) {

			if ((mac3[i][j] == 1) && (mac4[i][j] == 1)) {
				massa6[i][j] = 1;
			}
			else {
				massa6[i][j] = 0;
			}




		}

	}

	for (int i = 0; i < (bol); i++) {

		for (int j = 0; j < (bol); j++) {


			printf("%d  ", massa6[i][j]);


		}
		printf("\n");

	}

	printf("\n\n\n");
}


void main() {


	srand(time(NULL));
	setlocale(LC_ALL, "Russian");


	int n;
	int m;

	printf("Введите размерность первого массива:\n");
	scanf("%d", &n);
	printf("Введите размерность второго массива:\n");
	scanf("%d", &m);



	int** mas = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mas[i] = (int*)malloc(n * sizeof(int));
	}

	int** mas2 = (int**)malloc((m + 1) * sizeof(int*));
	for (int i = 0; i < (m + 1); i++) {
		mas2[i] = (int*)malloc((m + 1) * sizeof(int));
	}

	int** massave = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		massave[i] = (int*)malloc(n * sizeof(int));
	}

	int** mas2save = (int**)malloc((m + 1) * sizeof(int*));
	for (int i = 0; i < (m + 1); i++) {
		mas2save[i] = (int*)malloc((m + 1) * sizeof(int));
	}

	int** mas2save1 = (int**)malloc((m + 1) * sizeof(int*));
	for (int i = 0; i < (m + 1); i++) {
		mas2save1[i] = (int*)malloc((m + 1) * sizeof(int));
	}

	int** mas2save2 = (int**)malloc((m + 1) * sizeof(int*));
	for (int i = 0; i < (m + 1); i++) {
		mas2save2[i] = (int*)malloc((m + 1) * sizeof(int));
	}


	int** massave1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		massave1[i] = (int*)malloc(n * sizeof(int));
	}

	int** massave2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		massave2[i] = (int*)malloc(n * sizeof(int));
	}

	int** massave3 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		massave3[i] = (int*)malloc(n * sizeof(int));
	}

	int** massave4 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		massave4[i] = (int*)malloc(n * sizeof(int));
	}

	int** massave5 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		massave5[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			mas[i][j] = rand() % 2;
			if (i == j) { mas[i][j] = 0; }

		}

	}


	printf("\n\n-----------------------\n");

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			mas[j][i] = mas[i][j];
			if (i == j) { mas[i][j] = 0; }
			printf("%d  ", (mas[i][j]));

		}

		printf("\n");
	}


	for (int i = 0; i < m; i++) {

		for (int j = 0; j < m; j++) {

			mas2[i][j] = rand() % 2;
			if (i == j) { mas2[i][j] = 0; }

		}

	}

	printf("\n\n-----------------------\n");

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < m; j++) {

			mas2[j][i] = mas2[i][j];
			if (i == j) { mas2[i][j] = 0; }
			printf("%d  ", (mas2[i][j]));

		}

		printf("\n");
	}



	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			massave[i][j] = mas[i][j];
			massave1[i][j] = mas[i][j];
			massave2[i][j] = mas[i][j];
			massave3[i][j] = mas[i][j];
			massave4[i][j] = mas[i][j];
			massave5[i][j] = mas[i][j];
		}
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < m; j++) {

			mas2save[i][j] = mas2[i][j];
			mas2save1[i][j] = mas2[i][j];
			mas2save2[i][j] = mas2[i][j];
		}
	}


	int variant;


	for (variant = 1; variant < 8; variant++) {


		if (variant == 1) {
			Otoshdestvlenie(massave, n);
		}

		if (variant == 2) {
			Styagivanie(massave1, n);
		}

		if (variant == 3) {
			Rascheplenie(massave2, n);
		}

		if (variant == 4) {
			if (m <= n) {
				Peresechenie(mas2save, massave3, m, n);

			}
			if (m > n) {
				Peresechenie(massave3, mas2save, n, m);
			}
		}
		

	}

}
