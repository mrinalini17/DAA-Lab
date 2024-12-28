#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

struct Edge {
    int src_08, dest_08, weight_08;
};

struct Subset {
    int parent_08, rank_08;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent_08 != i)
        subsets[i].parent_08 = find(subsets, subsets[i].parent_08);
    return subsets[i].parent_08;
}

void Union(struct Subset subsets[], int x_08, int y_08) {
    int xroot = find(subsets, x_08);
    int yroot = find(subsets, y_08);

    
    if (subsets[xroot].rank_08 < subsets[yroot].rank_08)
        subsets[xroot].parent_08 = yroot;
    else if (subsets[xroot].rank_08 > subsets[yroot].rank_08)
        subsets[yroot].parent_08 = xroot;
    else {
        subsets[yroot].parent_08 = xroot;
        subsets[xroot].rank_08++;
    }
}


int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight_08 - ((struct Edge*)b)->weight_08;
}


void kruskalMST(struct Edge edges[], int V, int E) {
    struct Subset subsets[MAX_VERTICES];
    struct Edge result[MAX_VERTICES];

    
    for (int i = 0; i < V; i++) {
        subsets[i].parent_08 = i;
        subsets[i].rank_08 = 0;
    }

    qsort(edges, E, sizeof(edges[0]), compare);

    
    printf("Edge\t\tCost\n");
    int totalWeight = 0;
    int selectedEdges = 0;
    for (int i = 0; i < E && selectedEdges < V - 1; i++) {
        int x = find(subsets, edges[i].src_08);
        int y = find(subsets, edges[i].dest_08);

        if (x != y) {
            result[selectedEdges++] = edges[i];
            Union(subsets, x, y);
            printf("%d--%d\t\t%d\n", edges[i].src_08 + 1, edges[i].dest_08 + 1, edges[i].weight_08);
            totalWeight += edges[i].weight_08;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main() {
    int V_08, E_08;

    printf("Enter the Number of Vertices and Edges: ");
    scanf("%d %d", &V_08, &E_08);

    struct Edge edges[MAX_EDGES];
    printf("Enter the Edges and Weights (u v w):\n");
    for (int i = 0; i < E_08; i++) {
        scanf("%d %d %d", &edges[i].src_08, &edges[i].dest_08, &edges[i].weight_08);
        edges[i].src_08--;
        edges[i].dest_08--; 
    }

    kruskalMST(edges, V_08, E_08);

    return 0;
}