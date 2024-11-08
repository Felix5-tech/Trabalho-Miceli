#include <stdio.h>
#include <stdlib.h>

// Função para mover pares ao início e ímpares ao fim
void sortArrayByParity(int* nums, int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        // Encontra o próximo par à esquerda
        while (left < size && nums[left] % 2 == 0) {
            left++;
        }
        
        // Encontra o próximo ímpar à direita
        while (right >= 0 && nums[right] % 2 != 0) {
            right--;
        }

        // Troca os valores, se os índices ainda são válidos
        if (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }
}

int main() {
    int size;

    // Recebe o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    int* nums = (int*)malloc(size * sizeof(int)); // Aloca memória para o array

    // Recebe os elementos do array
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }


    sortArrayByParity(nums, size);

    // Exibe o array reorganizado
    printf("Array rearranjado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    free(nums);
    return 0;
}