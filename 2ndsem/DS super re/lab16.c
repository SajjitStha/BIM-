#include<stdio.h>
#define V 100
int queue[V], visited[V], flag = -1, n;
int primMST(int graph[V][V], int search){
    visited[search] = 1;
    int find, min, count = 0, from, to,i,j;
    flag++;
    queue[flag] = search;
for(j = 0; j<=flag; j++){
        find = queue[j];
        for(i=0; i<n; i++){
            if(graph[find][i] != 0 && visited[i] != 1 && count == 0){
                min = graph[find][i];
                from = find; to = i; 
                count++;
                continue;
            }
            if(count != 0){
                if(graph[find][i] != 0 && min>graph[find][i] && visited[i] != 1){
                    min = graph[find][i];
                    from = find; to = i;
                }
            }
        }
    }
    if(count == 0){
        return 0;
    }
    else{
        printf("%d - %d = %d\n", from, to, min);
        primMST(graph, to);
    }
}
int main()
{
   int graph[V][V] = {{0, 4, 7, 6, 0, 0, 0},
                      {4, 0, 4, 0, 9, 0, 0},
                      {7,4,0,3,6,5,0},
                      {6,0,3,0,0,6,0},
                      {0,9,6,0,0,3,7},
                      {0,0,5,6,3,0,0},
                      {0,0,0,0,7,0,0}
                     };
    n = 7;
    primMST(graph, 0);
return 0;
}
