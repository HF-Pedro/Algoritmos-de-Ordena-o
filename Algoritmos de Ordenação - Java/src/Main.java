
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void imprimirArray(int[] array, int tam) {
        for (int i = 0; i < tam; i++) {
            System.out.println(array[i]);
        }
    }

    public static int[] criarArray(int tam) {
        int[] array = new int[tam];
        for (int i = 0; i < tam; i++) {
            array[i] = i + 1;
        }
        return array;
    }

    public static int[] desorganizar(int[] array, int tam) {
        Random gerador = new Random();
        for (int i = 0; i < tam; i++) {
            int rand_pos = gerador.nextInt(tam);
            int t = array[rand_pos];
            array[rand_pos] = array[i];
            array[i] = t;
        }
        return array;
    }

    public static void imprimeMenu() {
        System.out.print("================================================================\n");
        System.out.print("|     Tempo de execucao de diferentes metodos de ordenacao     |\n");
        System.out.print("================================================================\n");
        System.out.print("| Operacoes:                                                   |\n");
        System.out.print("| 1) Insertion Sort                                            |\n");
        System.out.print("| 2) Shell Sort                                                |\n");
        System.out.print("| 3) Bubble Sort                                               |\n");
        System.out.print("| 4) Quick Sort                                                |\n");
        System.out.print("| 5) Merge Sort                                                |\n");
        System.out.print("| 5) Heap Sort                                                 |\n");
        System.out.print("| 7) Imprimir array original                                   |\n");
        System.out.print("| 8) Imprimir array ordenado                                   |\n");
        System.out.print("| 9) Sair                                                      |\n");
        System.out.print("+--------------------------------------------------------------+\n");
        System.out.print("  Pressione a opcao desejada ");
    }


    public static void main(String[] args) {
        Scanner inputs = new Scanner(System.in);
        int[] original, ordenado, temp;
        int tam;
        long t1, t2;
        System.out.println("Qual o tamanho do array a ser ordenado?: ");
        tam = inputs.nextInt();
        //criando o array original
        original = desorganizar(criarArray(tam), tam);
        //alocando memoria para o array ordenado
        ordenado = new int[tam];
        temp = new int[tam];

        int ok = 1;
        char opcao = '0';
        // menu com while e funções organizadas em switch case
        while (ok == 1) {

            imprimeMenu();
            opcao = inputs.next().charAt(0);

            t1 = System.currentTimeMillis();

            switch (opcao) {
                case '1' -> {
                    System.out.println("\nMetodo Insertion Sort");
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    Algoritmos.insertionSort(ordenado, tam);
                }
                case '2' -> {
                    System.out.println("\nMetodo Shell Sort");
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    Algoritmos.shellSort(ordenado, tam);
                }
                case '3' -> {
                    System.out.println("\nMetodo Bubble Sort");
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    Algoritmos.bubbleSort(ordenado, tam);
                }
                case '4' -> {
                    System.out.println("\nMetodo Quick Sort");
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    Algoritmos.quickSort(ordenado, 0, (tam - 1));
                }
                case '5' -> {
                    System.out.println("\nMetodo Merge Sort");
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    Algoritmos.mergeSort(ordenado, temp, 0, (tam - 1));
                }
                case '6' -> {
                    System.out.println("\nMetodo Heap Sort");
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    Algoritmos.mergeSort(ordenado, temp, 0, (tam - 1));
                }
                case '7' -> {
                    System.out.println("\nImprimir Array Original\n\n");
                    System.out.println("\nOriginal: ");
                    imprimirArray(original, tam);
                }
                case '8' -> {
                    System.out.println("\nImprimir Array Ordenado\n\n");
                    System.out.println("\nOrdenado: ");
                    imprimirArray(ordenado, tam);
                }
                case '9' -> ok = 0;
                default -> System.out.println("\nOpcao invalida!\n");
            }
            t2 = System.currentTimeMillis();
            System.out.println("Tempo de execução: " + (t2 - t1));
        }
        System.out.println("\n");

    }
}
