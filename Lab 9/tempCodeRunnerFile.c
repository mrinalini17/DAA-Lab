#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];
int key[MAX_VERTICES];
bool inMST[MAX_VERTICES];

void initializeGraph(int vertices) {
    for (int i_08 = 1; i_08 <= vertices; i_08++) {
        key[i_08] = INF;
        inMST[i_08] = false;
    }
}

int minKey(int vertices) {
    int min = INF;
    int minIndex = -1;

    for (int v_08 = 1; v_08 <= vertices; v_08++) {
        if (!inMST[v_08] && key[v_08] < min) {
            min = key[v_08];
            minIndex = v_08;
        }
    }

    return minIndex;
}

void printMST(int vertices) {
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");
    for (int i_08 = 1; i_08 <= vertices; i_08++) {
        for (int j_08 = 1; j_08 <= vertices; j_08++) {
            if (parent[j_08] == i_08) {
                printf("%d ", graph[i_08][j_08]);
            } else if (parent[i_08] == j_08) {
                printf("%d ", graph[i_08][j_08]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void primMST(int vertices, int startVertex) {
    key[startVertex] = 0;
    parent[startVertex] = -1;

    for (int count = 1; count <= vertices - 1; count++) {
        int u = minKey(vertices);
        inMST[u] = true;

        for (int v_08 = 1; v_08 <= vertices; v_08++) {
            if (graph[u][v_08] && !inMST[v_08] && graph[u][v_08] < key[v_08]) {
                parent[v_08] = u;
                key[v_08] = graph[u][v_08];
            }
        }
    }
}

int main() {
    int vertices, startVertex;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &vertices);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    FILE *file = fopen("C:\\Users\\KIIT\\Desktop\\DAA\\output\\inUnAdjMat.txt", "r");
    if (file == NULL) {
        perror("Error opening the input file");
        return 1;
    }

    for (int i_08 = 1; i_08 <= vertices; i_08++) {
        for (int j_08 = 1; j_08 <= vertices; j_08++) {
            fscanf(file, "%d", &graph[i_08][j_08]);
        }
    }

    fclose(file);

    initializeGraph(vertices);
    primMST(vertices, startVertex);

    printMST(vertices);

    int totalWeight = 0;
    for (int i_08 = 1; i_08 <= vertices; i_08++) {
        if (i_08 != startVertex) {
            totalWeight += key[i_08];
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

    return 0;
}