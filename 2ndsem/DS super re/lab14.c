#include<stdio.h>
#define vertices 100
int adjmat[vertices][vertices]; 
int visited[vertices], queue[vertices], n,i;
void bfs(int startPoint){
    int front = -1, rear = -1;
    visited[startPoint] = 1;
    queue[++rear] = startPoint;
    while(rear != front){
        int current_vertex = queue[++front];
        printf("%d ", current_vertex);
			for(i = 0; i<n; i++){
            if(adjmat[current_vertex][i] && !visited[i]){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
void main(){
    int starting_point,i,j;
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacent matrix:\n");
    for(i = 0; i<n; i++){
        for(j =0; j<n; j++){
            scanf("%d", &adjmat[i][j]);
        }
        printf("\n");
    }
    printf("Enter the starting vertex (1st Vertex is 0): ");
    scanf("%d", &starting_point);
    bfs(starting_point);
}

