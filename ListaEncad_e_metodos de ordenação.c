#include <stdio.h>
#include <stdlib.h>

//lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertNode(Node *head, int data) {
    Node* current_node=head;
    while(current_node->next != NULL) {
        current_node=current_node->next;
    }
    current_node->next=createNode(data);
}

void printlist(Node* head) {
    Node* current_node = head;
    while (current_node!= NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


//Bubble sort
void bubbleSort(Node* head) {
    if (head == NULL) return;

    int swap;
    Node* ptr;
    Node* end = NULL;
    do {
        swap = 0;
        ptr = head;
        while (ptr->next != end) {
            if (ptr->data > ptr->next->data) {
                int old_data = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = old_data;
                swap = 1;
            }
            ptr = ptr->next;
        }
        end = ptr;
    } while (swap);
}

//Merge sort
// Função auxiliar para dividir a lista (para Merge Sort)
void split(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

struct Node* merge(struct Node* front, struct Node* back) {
    if (front == NULL) return back;
    if (back == NULL) return front;
    if (front->data < back->data) {
        front->next = merge(front->next, back);
        return front;
    } else {
        back->next = merge(front, back->next);
        return back;
    }
}

void mergeSort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct Node* front;
    struct Node* back;
    split(*head, &front, &back);
    mergeSort(&front);
    mergeSort(&back);
    *head = merge(front, back);
}

//Quick sort
// Função para encontrar o último nó de uma lista
Node* getLast(Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->next;
    Node* j = low;
    
    while (i != high) {
        if (i->data <= pivot) {
            j = (j == NULL) ? low : j->next;
            swap(j, i);
        }
        i = i->next;
    }
    swap(j->next, high);
    return j;
}

// Função recursiva de Quick Sort
void quickSortRec(Node* low, Node* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSortRec(low, pivot);
        quickSortRec(pivot->next, high);
    }
}

// Função principal para Quick Sort
void quickSort(Node** head) {
    Node* high = getLast(*head);
    quickSortRec(*head, high);
}


//insert sort
void sortedInsert(Node** head, Node* newNode) {
    Node* current;
    
    // Caso a lista esteja vazia ou o novo nó deva ir para o início
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        // Procura o nó anterior ao local onde o novo nó será inserido
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Função para realizar o Insertion Sort na lista encadeada
void insertionSort(Node** head) {
    // Lista ordenada começa vazia
    Node* sorted = NULL;
    Node* current = *head;
    
    while (current != NULL) {
        Node* next = current->next;  // Armazena o próximo nó
        sortedInsert(&sorted, current);  // Insere o nó em sorted
        current = next;  // Avança para o próximo nó
    }
    
    // Atualiza o ponteiro da cabeça para a lista ordenada
    *head = sorted;
}
int main(){
    Node* head = createNode(5);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 4);
    
    printf("Lista original:\n");
    printlist(head);
    printf("\n");

    bubbleSort(head);
    printf("Lista apos Bubble Sort: ");
    printlist(head);
    printf("\n");
    // Merge Sort
    mergeSort(&head);
    printf("Lista apos Merge Sort: ");
    printlist(head);
    printf("\n");

    // Quick Sort
    quickSort(&head);
    printf("Lista apos Quick Sort: ");
    printlist(head);
    printf("\n");

    // Insertion Sort
    insertionSort(&head);
    printf("Lista apos Insertion Sort: ");
    printlist(head);
    printf("\n");

    return 0;
}
