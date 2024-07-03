#include<stdio.h>
#define vertices 100
int adjmat[vertices][vertices];
int visited[vertices], no;
void dfs(int n){
    printf("%d ", n);
    visited[n] = 1;
    int i;
    for(i = 0; i<no; i++){
        if((visited[i] == 0) && (adjmat[n][i] == 1)){
            dfs(i);
        }
    }
}
void main(){
    int startVertex,i,j;
    printf("\nEnter number of vertices: ");
    scanf("%d", &no);
    printf("\nEnter the adjacent matrix:\n");
    for(i = 0; i<no; i++){
        visited[i] = 0;
        for(j =0; j<no; j++){
            scanf("%d", &adjmat[i][j]);
        }
        printf("\n");
    }
    printf("Enter the starting vertex:");
    scanf("%d", &startVertex);
    dfs(startVertex);
}
