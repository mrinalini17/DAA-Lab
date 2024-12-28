#include<stdio.h>
#include<stdlib.h>

struct SYMBOL {
    char alphabet_08;
    int frequency_08;
    struct SYMBOL* left;
    struct SYMBOL* right;
};

struct MinPriorityQueue {
    int size_08;
    struct SYMBOL** array;
};

struct SYMBOL* createSymbolNode(char alphabet_08, int frequency_08) {
    struct SYMBOL* newNode = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));
    newNode->alphabet_08 = alphabet_08;
    newNode->frequency_08 = frequency_08;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct MinPriorityQueue* createMinPriorityQueue(int capacity) {
    struct MinPriorityQueue* minHeap = (struct MinPriorityQueue*)malloc(sizeof(struct MinPriorityQueue));
    minHeap->size_08 = 0;
    minHeap->array = (struct SYMBOL*)malloc(sizeof(struct SYMBOL) * capacity);
    return minHeap;
}

void swap(struct SYMBOL** a_08, struct SYMBOL** b_08) {
    struct SYMBOL* temp = *a_08;
    *a_08 = *b_08;
    *b_08 = temp;
}

void minHeapify(struct MinPriorityQueue* minHeap, int idx_08) {
    int smallest = idx_08;
    int left = 2 * idx_08 + 1;
    int right = 2 * idx_08 + 2;

    if (left < minHeap->size_08 && minHeap->array[left]->frequency_08 < minHeap->array[smallest]->frequency_08)
        smallest = left;

    if (right < minHeap->size_08 && minHeap->array[right]->frequency_08 < minHeap->array[smallest]->frequency_08)
        smallest = right;

    if (smallest != idx_08) {
        swap(&minHeap->array[idx_08], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

struct SYMBOL* buildHuffmanTree(char alphabets[], int frequencies[], int size_08) {
    struct SYMBOL *left, *right, *top;
    struct MinPriorityQueue* minHeap = createMinPriorityQueue(size_08);

    for (int i = 0; i < size_08; ++i)
        minHeap->array[i] = createSymbolNode(alphabets[i], frequencies[i]);

    minHeap->size_08 = size_08;

    for (int i = size_08 / 2 - 1; i >= 0; --i)
        minHeapify(minHeap, i);

    while (minHeap->size_08 > 1) {
        left = minHeap->array[0];
        minHeap->array[0] = minHeap->array[minHeap->size_08 - 1];
        --minHeap->size_08;
        minHeapify(minHeap, 0);

        right = minHeap->array[0];
        minHeap->array[0] = createSymbolNode('$', left->frequency_08 + right->frequency_08);
        minHeap->array[0]->left = left;
        minHeap->array[0]->right = right;
        minHeapify(minHeap, 0);
    }

    top = minHeap->array[0];
    return top;
}

void inOrderTraversal(struct SYMBOL* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%c ", root->alphabet_08);
        inOrderTraversal(root->right);
    }
}

int main() {
    int n_08;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n_08);

    char alphabets[n_08];
    int frequencies[n_08];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n_08; ++i) {
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n_08; ++i) {
        scanf("%d", &frequencies[i]);
    }

    struct SYMBOL* root = buildHuffmanTree(alphabets, frequencies, n_08);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);

    return 0;
}