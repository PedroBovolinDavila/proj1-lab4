// EXERCICIO 1
#if 0

#include "stdio.h"

void trim(char* str);

int main() {
	int x = 10;
	int* p = &x;

	char str[] = "oi to bem";

	printf("x: %d\n", x);
	printf("&x: %p\n", (void*)&x);
	printf("p: %p\n", (void*)p);
	printf("*p: %d\n", *p);

	trim(str);

	printf("%s\n", str);

	return 0;
}

void trim(char* str) {
	char* temp = str;
	
	for (char* i = str; *i != '\0'; i++) {
		if (*i != ' ') {
			*temp = *i;
			temp++;
		}
	}

	*temp = '\0';
}

#endif

// EXERCICIO 2
#if 0
#include "stdio.h"

int main() {
	int x = 10;
	int* p = &x;

	*p = 100;

	p = NULL;

	return 0;
}

#endif

// EXERCICIO 3
#if 0
#include "stdio.h"

void alterar_1(int x);
void alterar_2(int* x);

int main() {
	int x = 10;

	alterar_1(x);
	printf("x: %d\n", x);

	alterar_2(&x);
	printf("x: %d\n", x);

	return 0;
}

void alterar_1(int x) {
	x = 100;
}

void alterar_2(int* x) {
	*x = 100;
}

#endif

// EXERCICIO 4
#if 0
#include "stdio.h"

void trocar_valores(int* a, int* b);

int main() {
	int a = 10, b = 5;
	 
	printf("Antes  -> A: %d  B: %d\n", a, b);

	trocar_valores(&a, &b);

	printf("Depois -> A: %d   B: %d\n", a, b);

	return 0;
}

void trocar_valores(int* a, int* b) {
	int temp = *a;

	*a = *b;
	*b = temp;
}

#endif

// EXERCICIO 5
#if 0
#include "stdio.h"

struct Amostra {
	int canal;
	double tempo;
	double tensao;
};

void trocar_tensao(struct Amostra* amostra);

int main() {
	struct Amostra amostra = { 1, 5.3, 12.5 };

	printf("Tensao antes: %lf\n", amostra.tensao);

	trocar_tensao(&amostra);

	printf("Tensao depois: %lf\n", amostra.tensao);

	return 0;
}

void trocar_tensao(struct Amostra* amostra) {
	amostra->tensao = 100;
}

#endif

#if 1
#include "stdio.h"

#define MAX_SENSORES 10

struct Sensor {
	int canal;
	double ganho;
	double offset;
	double medida;
};

void calibrar_sensor(struct Sensor* sensor);
void mostrar_sensor(const struct Sensor sensor, int numero_sensor);
double calcular_media(const struct Sensor sensores[], int qtd_sensores);
int indice_maior(const struct Sensor sensores[], int qtd_sensores);

int main() {
	struct Sensor sensores[MAX_SENSORES];
	int qtd_sensores;

	do {
		printf("Informe a quantidade de sensores (0 < x < 11): ");
		scanf_s("%d", &qtd_sensores);
	} while (qtd_sensores < 1 || qtd_sensores > 10);
	printf("\n");

	for (int i = 0; i < qtd_sensores; i++) {
		printf("Sensor %d\n", i + 1);

		printf("\tCanal: ");
		scanf_s("%d", &sensores[i].canal);
		printf("\tGanho: ");
		scanf_s("%lf", &sensores[i].ganho);
		printf("\tOffset: ");
		scanf_s("%lf", &sensores[i].offset);
		printf("\tMedida: ");
		scanf_s("%lf", &sensores[i].medida);
	}
	printf("\n");

	double media_errada = calcular_media(sensores, qtd_sensores);

	printf("Media errada: %.2lf", media_errada);

	for (int i = 0; i < qtd_sensores; i++) {
		calibrar_sensor(&sensores[i]);
	}

	printf("\n");

	double media_corrigida = calcular_media(sensores, qtd_sensores);

	printf("Media corrigida: %.2lf\n\n", media_corrigida);

	int index_maior_media = indice_maior(sensores, qtd_sensores);

	printf("Sensor com maior media apos correcao: \n");
	mostrar_sensor(sensores[index_maior_media], index_maior_media + 1);
	printf("\n");

	printf("Todos os sensores apos calibracao: \n");
	for (int i = 0; i < qtd_sensores; i++) {
		mostrar_sensor(sensores[i], i + 1);
	}

	return 0;
}

void calibrar_sensor(struct Sensor* sensor) {
	sensor->medida = sensor->ganho * sensor->medida + sensor->offset;
}

void mostrar_sensor(const struct Sensor sensor, int numero_sensor) {
	printf("Sensor %d\n", numero_sensor);
	printf("\tCanal: %d\n", sensor.canal);
	printf("\tGanho: %.2lf\n", sensor.ganho);
	printf("\tOffset: %.2lf\n", sensor.offset);
	printf("\tMedida: %.2lf\n", sensor.medida);
}

double calcular_media(const struct Sensor sensores[], int qtd_sensores) {
	double temp = 0;
	for (int i = 0; i < qtd_sensores; i++) {
		temp += sensores[i].medida;
	}

	return temp / qtd_sensores;
}

int indice_maior(const struct Sensor sensores[], int qtd_sensores) {
	int temp = 0;
	for (int i = 0; i < qtd_sensores; i++) {
		if (sensores[temp].medida < sensores[i].medida) temp = i;
	}

	return temp;
}

#endif
