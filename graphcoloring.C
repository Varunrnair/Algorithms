#include <stdio.h>
int graph[100][100];
int m;
int n;
int x[100];

void NextVal(int k){
    int j=0;
    while(1){
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for ( j = 0; j <n; j++) {
            if(graph[k][j]!=0 && x[k]==x[j]){
                break;
            }
        }
        if(j==n)
            return;
    }
}

void mColoring(int k){
    while(1){
        NextVal(k);
        if(x[k]==0)
            return;
        if(k==n-1){
            printf("Solution is-\n");
            for (int i = 0; i < n; i++) {
                printf(" %d ",x[i]);
            }
            printf("\n");
            break;
        }
        else{
            mColoring(k+1);
        }
    }
}
void main()
{
    printf("Enter Number of Vertices: ");
    scanf("%d",&n);
    printf("Enter Distances For each Vertex-\n");
    for (int i = 0; i < n; i++)
    {
        printf("From Vertex %c : ",i + 97);
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
        x[i]=0;
    }
    printf("Enter Number of Colors: ");
    scanf("%d",&m);
    mColoring(0);
 return 0;
}