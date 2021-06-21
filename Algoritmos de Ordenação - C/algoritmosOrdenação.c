#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define CLEAR "CLS"

unsigned long long current_timestamp() {
    struct timeval tv;
    unsigned long long tim;
    gettimeofday(&tv, NULL);
    tim = 1000000 * tv.tv_sec + tv.tv_usec;
    return tim;
}

void imprimirArray(int *array, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
}

int *criarArray(int tam) {
    int *array = (int *) malloc(sizeof(int) * tam);
    for (int i = 0; i < tam; i++) {
        array[i] = i + 1;
    }
    return array;
}

int *desorganizar(int *array, int tam) {
    time_t tim;
    srand((unsigned) time(&tim));
    for (int i = 0; i < tam; i++) {
        int rand_pos = (int)(((double)rand()/RAND_MAX) * tam);
        int t = array[rand_pos];
        array[rand_pos] = array[i];
        array[i] = t;
    }
    return array;
}

void imprimeMenu(int tam) {
    printf("================================================================\n");
    printf("|     Tempo de execucao de diferentes metodos de ordenacao     |\n");
    printf("|                    Tamanho do array = %d                     \n", tam);
    printf("================================================================\n");
    printf("| Operacoes:                                                   |\n");
    printf("| 1) Insertion Sort                                            |\n");
    printf("| 2) Shell Sort                                                |\n");
    printf("| 3) Bubble Sort                                               |\n");
    printf("| 4) Quick Sort                                                |\n");
    printf("| 5) Merge Sort                                                |\n");
    printf("| 6) Heap Sort                                                |\n");
    printf("| 7) Imprimir array original                                   |\n");
    printf("| 8) Imprimir array ordenado                                   |\n");
    printf("| 9) Sair                                                      |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("  Pressione a opcao desejada ");
}

void insertionSort(int *array, int tam) {
    unsigned long long t1,t2;
    t1 = current_timestamp();
    int i, k, aux;
    for (k = 1; k < tam; k++) {
        aux = array[k];
        for (i = k - 1; i >= 0 && aux < array[i]; i--) {
            array[i + 1] = array[i];
            }
        array[i + 1] = aux;
    }
    t2 = current_timestamp();
    printf("\n\nDuracao em microssegundos: %lld\n", t2 - t1);
}

void shellSort(int *array, int tam) {
    unsigned long long t1,t2;
    t1 = current_timestamp();
    int gap, j, k, aux;
    for (gap = tam / 2; gap >= 1; gap = gap / 2) {
        for (j = gap; j < tam; j++) {
            aux = array[j];
            for (k = j - gap; k >= 0 && aux < array[k]; k -= gap) {
                array[k + gap] = array[k];
            }
            array[k + gap] = aux;
        }

    }
    t2 = current_timestamp();
    printf("\n\nDuracao em microssegundos: %lld\n", t2 - t1);
}

void bubbleSort(int *array, int tam){
    unsigned long long t1,t2;
    t1 = current_timestamp();
    int i, j, aux;
    for(j = tam - 1; j > 0; j--) {
        for(i = 0; i < j; i++) {
            if(array[i] > array[i + 1]) {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
            }
        }
    }
    t2 = current_timestamp();
    printf("\n\nDuracao em microssegundos: %lld\n", t2 - t1);
}

void quickSort(int *array, int p,int u){
    int i, j, pivo, aux;
    i = p;
    j = u;
    pivo = array[(i + j)/2];
    do{
        while(array[i] < pivo && i < u) i++;
        while(array[j] > pivo && j > p) j--;
        if(i <= j){
            aux = array[i];
            array[i] = array[j];
                array[j] = aux;
                i++;
                j--;
        }
    } while(i <= j);
    if(p < j) quickSort(array, p, j);
    if(i < u) quickSort(array, i, u);

}
void merge(int *x, int *temp, int esq, int meio, int dir) {
    int i, esq_fim, tam, tmp_pos;
    esq_fim = meio - 1;
    tmp_pos = esq;
    tam = dir - esq + 1;
    while ((esq <= esq_fim) && (meio <= dir)) { //Junção ordenada em temp
        if (x[esq] <= x[meio]) {                //Se elemento da esquerda menor
            temp[tmp_pos] = x[esq];
            tmp_pos++;
            esq++;
        }
        else {
            temp[tmp_pos] = x[meio];            //Se elemento da direita menor
            tmp_pos++;
            meio++;
        }
    }
    if (esq <= esq_fim) {                       //Sobraram elementos na esquerda
        memcpy(&temp[tmp_pos], &x[esq], (esq_fim - esq + 1)*sizeof(int));
    }
    if (meio <= dir) {                          //Sobraram elementos na direita
        memcpy(&temp[tmp_pos], &x[meio], (dir - meio + 1)*sizeof(int));
    }
    //Copiar elementos de temp para x
    memcpy(&x[dir - tam + 1], &temp[dir - tam + 1], tam*sizeof(int));
}

void mergeSort(int *x, int *temp, int esq, int dir) {
    int meio;
    if (dir > esq) {
        meio = (dir + esq) / 2;
        mergeSort(x, temp, esq, meio);
        mergeSort(x, temp, meio+1, dir);
        merge(x, temp, esq, meio+1, dir);
    }

}

void heapfica(int *x, int n) {
    int i, aux, s, f;
	for (int i = 1; i < n; i++) {
		aux = x[i];
		s = i;
		f = (s - 1) / 2;
		while (s > 0 && x[f] < aux) {
			x[s] = x[f];
			s = f;
			f = (s - 1) / 2;
		}
		x[s] = aux;
	}
}

void heapSort(int *x, int n) {
	int i, s, f, ival;
    heapfica(x, n);
	for(i = n - 1; i > 0; i--) {

		ival = x[i];

		x[i] = x[0];

		f = 0;

		if (i == 1) {
			s = -1;
		} else {
			s = 1;
		}
		if (i > 2 && x[2] > x[1]) {
			s = 2;
		}
		while (s >= 0 && ival < x[s]) {
			x[f] = x[s];
			f = s;
			s = 2 * f + 1;
			if (s + 1 <= i - 1 && x[s] < x[s + 1]) {
				s = s + 1;
			}
			if (s > i - 1) {
				s = -1;
			}
		}
		x[f] = ival;
	}
}

int main() {
    unsigned long long t1,t2;
    int *original, *ordenado, *temp;
    int tam;
    printf("Qual o tamanho do array a ser ordenado?: ");
    scanf("%d",&tam);
    //criando o array original
    original = desorganizar(criarArray(tam), tam);
    //alocando memoria para o array ordenado
    ordenado = (int *) malloc(sizeof(int) * tam);
    temp = (int *) malloc(sizeof(int) * tam);

    int ok = 1;
    char opcao = '0';
    // menu com while e funções organizadas em switch case
    while(ok==1) {
        system(CLEAR);
        imprimeMenu(tam);
        opcao = getch();
        switch(opcao) {
            case '1':   printf("\nMetodo Insertion Sort");
                        memcpy(ordenado, original, sizeof(int) * tam);
                        insertionSort(ordenado,tam);

                        getch();
						break;

            case '2': 	printf("\nMetodo Shell Sort");
                        memcpy(ordenado, original, sizeof(int) * tam);
                        shellSort(ordenado,tam);


                        getch();
						break;

			case '3':	printf("\nMetodo Bubble Sort");
                        memcpy(ordenado, original, sizeof(int) * tam);
                        bubbleSort(ordenado,tam);

                        getch();
						break;

            case '4':
                        t1 = current_timestamp();
                        printf("\nMetodo Quick Sort");
                        memcpy(ordenado, original, sizeof(int) * tam);
                        quickSort(ordenado,0,(tam-1));
                        t2 = current_timestamp();
                        printf("\n\nDuracao em microssegundos: %lld\n", t2 - t1);

                        getch();
                        break;

            case '5': t1 = current_timestamp();
                        printf("\nMetodo Merge Sort");
                        memcpy(ordenado, original, sizeof(int) * tam);
                        mergeSort(ordenado,temp,0,(tam-1));
                        t2 = current_timestamp();
                        printf("\n\nDuracao em microssegundos: %lld\n", t2 - t1);

                        getch();
                        break;

            case '6':   t1 = current_timestamp();
                        printf("\nMetodo Heap Sort");
                        memcpy(ordenado, original, sizeof(int) * tam);
                        heapSort(ordenado,tam);
                        t2 = current_timestamp();
                        printf("\n\nDuracao em microssegundos: %lld\n", t2 - t1);

                        getch();
                        break;

            case '7': 	printf("\nImprimir Array Original\n\n");
                        printf("\nOriginal: ");
                        imprimirArray(original,tam);

                        getch();
						break;

            case '8':   printf("\nImprimir Array Ordenado\n\n");
                        printf("\nOrdenado: ");
                        imprimirArray(ordenado,tam);

                        getch();
						break;

            case '9': 	ok = 0;
						break;

            default: 	printf("\nOpcao invalida!\n");
						getch();
						break;
        }
    }
    printf("\n");
    return (EXIT_SUCCESS);
}


