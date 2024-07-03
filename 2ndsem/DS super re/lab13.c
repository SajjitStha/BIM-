#include<stdio.h>

void main(){
    int vertices,i,j,k;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int adjMat[vertices][vertices];
    printf("\nEnter the adjacency matrix:\n");
    for(i = 0; i<vertices; i++){
        for(j = 0; j<vertices; j++){
            printf("From %d to %d: ", i, j);
            scanf("%d", &adjMat[i][j]);
        }
        printf("\n");
    }

    //Displaying
    for(i = -1; i<vertices; i++){
        if(i==-1){
            printf("V ");
            for(k = 0; k<vertices; k++){
                printf("%d ", k);
            }
            printf("\n");
            continue;
        }
        for(j = -1; j<vertices; j++){
            if(j==-1) printf("%d ", i);
            else{
                printf("%d ", adjMat[i][j]);
            }
        }
        printf("\n");
    }
}
