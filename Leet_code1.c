#include <stdio.h>
#include <stdlib.h>
void merge(int* nums1, int m, int* nums2, int n) {
    int p1 = m - 1;       // Último elemento válido em nums1
    int p2 = n - 1;       // Último elemento em nums2
    int p = m + n - 1;    // Última posição em nums1

    // Preenche nums1 de trás para frente
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // Se ainda houver elementos em nums2, copie-os para nums1
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p--;
        p2--;
    }
}

int main() {
    int m, n;

    printf("Digite o número de elementos válidos em nums1: ");
    scanf("%d", &m);

    printf("Digite o número de elementos em nums2: ");
    scanf("%d", &n);

    int* nums1 = (int*)malloc((m + n) * sizeof(int));
    int* nums2 = (int*)malloc(n * sizeof(int));

    printf("Digite os elementos válidos de nums1: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    printf("Digite os elementos de nums2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }


    merge(nums1, m, nums2, n);

    printf("Array mesclado: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    free(nums1);
    free(nums2);

    return 0;
}