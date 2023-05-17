#include<stdio.h>
#include<math.h>
int n;
int x[20];

int place(int k, int i){
    int j;
    for(j=0;j<n;j++){
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void nqueen(int k){
    int i,j;
    for(i=1;i<=n;i++){
        if(place(k,i)==1){
            x[k]=i;
            if(k==n){
                printf("Solution will be:");
                for(j=1;j<=n;j++)
                    printf("%d",x[j]);
                printf("\n");
            }
            else    
                nqueen(k+1);
        }
    }
}

void main(){
    int i;
    printf("enter the value of n for n-queen:");
    scanf("%d",&n);
    nqueen(1);
}