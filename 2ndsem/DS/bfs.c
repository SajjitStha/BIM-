#include<stdio.h>

void main(){
    int noOfVertex;
    printf("Enter the number of vertex: ");
    scanf("%d", &noOfVertex);
    int count = 1;
    int i,j;
    int mat[noOfVertex][noOfVertex];
    for(i = 0; i<noOfVertex; i++){
        for(j=0; j<noOfVertex; j++){
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    int vertex[noOfVertex], visited[noOfVertex], oparr[noOfVertex];
    for(i = 0; i<noOfVertex; i++){
        vertex[i] = i;
        visited[i] = 0;
        oparr[i] = 0;
    }
    visited[0] = 1;
    oparr[0] = vertex[0];
    for(i = 0; i<noOfVertex; i++){
        for( j=0; j<noOfVertex; j++){
            if(mat[i][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                oparr[count] = vertex[j];
                count++;
            }
        }
    }
    for(i = 0; i<noOfVertex; i++){
            printf("%d ", oparr[i]);
    }
}
