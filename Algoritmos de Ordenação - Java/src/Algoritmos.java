public class Algoritmos {


    public static void insertionSort(int[] array, int tam) {

        int i, k, aux;
        for (k = 1; k < tam; k++) {
            aux = array[k];
            for (i = k - 1; i >= 0 && aux < array[i]; i--) {
                array[i + 1] = array[i];
            }
            array[i + 1] = aux;
        }

    }

    public static void shellSort(int[] array, int tam) {

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

    }

    public static void bubbleSort(int[] array, int tam) {

        int i, j, aux;
        for (j = tam - 1; j > 0; j--) {
            for (i = 0; i < j; i++) {
                if (array[i] > array[i + 1]) {
                    aux = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = aux;
                }
            }
        }

    }

    public static void quickSort(int[] array, int p, int u) {
        int i, j, pivo, aux;
        i = p;
        j = u;
        pivo = array[(i + j) / 2];
        do {
            while (array[i] < pivo && i < u) i++;
            while (array[j] > pivo && j > p) j--;
            if (i <= j) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                i++;
                j--;
            }
        } while (i <= j);
        if (p < j) quickSort(array, p, j);
        if (i < u) quickSort(array, i, u);

    }

    public static void merge(int[] x, int[] temp, int esq, int meio, int dir) {
        int esq_fim, tam, tmp_pos;
        esq_fim = meio - 1;
        tmp_pos = esq;
        tam = dir - esq + 1;
        while ((esq <= esq_fim) && (meio <= dir)) { //Junção ordenada em temp
            if (x[esq] <= x[meio]) {                //Se elemento da esquerda menor
                temp[tmp_pos] = x[esq];
                tmp_pos++;
                esq++;
            } else {
                temp[tmp_pos] = x[meio];            //Se elemento da direita menor
                tmp_pos++;
                meio++;
            }
        }
        if (esq <= esq_fim) {                       //Sobraram elementos na esquerda
            System.arraycopy(x, esq, temp, tmp_pos, esq_fim - esq + 1);
        }
        if (meio <= dir) {                          //Sobraram elementos na direita
            System.arraycopy(x, meio, temp, tmp_pos, dir - meio + 1);
        }
        System.arraycopy(temp, dir - tam + 1, x, dir - tam + 1, tam);
    }

    public static void mergeSort(int[] x, int[] temp, int esq, int dir) {
        int meio;
        if (dir > esq) {
            meio = (dir + esq) / 2;
            mergeSort(x, temp, esq, meio);
            mergeSort(x, temp, meio + 1, dir);
            merge(x, temp, esq, meio + 1, dir);
        }
    }

    public static void heapfica(int[] x, int n) {
        int i, aux, s, f;
        for (i = 1; i < n; i++) {
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

    public static void heapsort(int[] x) {
        int i, s, f, ival;
        heapfica(x, x.length);
        for (i = x.length - 1; i > 0; i--) {
            //Copia-se x[i] - última posição
            ival = x[i];
            //Insere x[0] (raiz, maior valor) no final
            x[i] = x[0];
            //Ajusta o heap novamente
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
}
