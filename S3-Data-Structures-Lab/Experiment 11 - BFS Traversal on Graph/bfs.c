#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void BFS(int start, int n) {
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;
    printf("Performing BFS starting from vertex %d:\n", start);
    
    while (front <= rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges;
    int start, u, v;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    
    BFS(start, n);
    
    return 0;
}