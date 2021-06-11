# Algoritmos de Ordenação

Neste repositório estãos e aplicados 6 algoritmos de ordenação com o intuito de comparar os tempos de execução e, consequentemente, a viablidade de cada um para listas de dados cada vez maiores. 

## Métodos e seus valores de complexidade
| Métodos| Melhor caso| Caso médio | Pior caso|
| ------|-----|-----|-----|
| Insertion Sort| C(n) = O(n)|C(n) = O(n²) |C(n) = O(n²)|
| Shell Sort | -------------|-------------|-------------|-------------|
| Bubble Sort |C(n) = O(n)|C(n) = O(n²)|C(n) = O(n²)|
| Quick Sort |C(n) = O(n log n)|C(n) = O(n log n)|C(n) = O(n²)|
| Merge Sort |C(n) = O(n log n)|C(n) = O(n log n)|C(n) = O(n log n)|
| Heap Sort |C(n) = O(n log n)|C(n) = O(n log n)|C(n) = O(n log n)|

## Funcionamento

O progama inicialmente pergunta o tamanho do array que será construído, depois mostra ao usuário um menu com todas as opções de ordenação e impressão do vetor. Todas as vezes que o vetor é ordenado, primeiramente ele é desorganizado, portanto, pode-se testar o tempo de execução de vários métodos sem antes visualizar o vetor inteiro.
