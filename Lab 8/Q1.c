/*Aim of the program: Consider an undirected graph where each edge weights 2 units. Each of
the nodes is labeled consecutively from 1 to n. The user will input a list of edges for describing
an undirected graph. After representation of the graph, from a given starting position
● Display the breadth-first search traversal.
● Determine and display the shortest distance to each of the other nodes using the breadth-
first search algorithm. Return an array of distances from the start node in node number
order. If a node is unreachable, return -1 for that node.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define INF -1

int n_08, m_08;
int graph[MAX_NODES][MAX_NODES];
int distances[MAX_NODES];
bool visited[MAX_NODES];

void initializeGraph() {
    for (int i_08 = 0; i_08 < MAX_NODES; i_08++) {
        distances[i_08] = INF;
        visited[i_08] = false;
        for (int j_08 = 0; j_08 < MAX_NODES; j_08++) {
            graph[i_08][j_08] = 0;
        }
    }
}

void addEdge(int u_08, int v_08) {
    graph[u_08][v_08] = 2;
    graph[v_08][u_08] = 2;
}

void breadthFirstSearch(int start) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    distances[start] = 0;
    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: %d", start);

    while (front < rear) {
        int currentNode = queue[front++];
        for (int i = 1; i <= n_08; i++) {
            if (graph[currentNode][i] > 0 && !visited[i]) {
                distances[i] = distances[currentNode] + graph[currentNode][i];
                visited[i] = true;
                queue[rear++] = i;
                printf(" %d", i);
            }
        }
    }
    printf("\n");
}

int main() {
    int start;
    scanf("%d %d", &n_08, &m_08);

    initializeGraph();

    for (int i = 0; i < m_08; i++) {
        int u_08, v_08;
        scanf("%d %d", &u_08, &v_08);
        addEdge(u_08, v_08);
    }

    scanf("%d", &start);

    breadthFirstSearch(start);

    printf("Distance [");
    for (int i = 1; i <= n_08; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", distances[i]);
    }
    printf("]\n");

    return 0;
}