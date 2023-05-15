#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int r){
    int i=0, j=0, k=l;
    int n1= m - l + 1;
    int n2= r - m;
    int leftarray[n1], rightarray[n2];
    
    for(i=0;i<n1;i++){
        leftarray[i]= a[l+i];
    }
    for(j=0;j<n2;j++){
        rightarray[i]= a[m+j];
    }
    while(i<n1 && l<n2){
        if(leftarray[i]<=rightarray[j]){
            a[k]=leftarray[i];
            i++;
        }
        else{
            a[k]=rightarray[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]= leftarray[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]= rightarray[i];
        i++;
        k++;
    }
}

void mergesort(int a[], int l, int r){
    int m;
    if(l<r){
        m = (l+r)/2;
        mergesort(a, l, m);
        mergesort(a, m+1, r);
        merge(a, l, m, r);
    }
}

void main()
{
    int len=10;
    int a1[10], a2[10], a3[10], i, choice;
    clock_t start, end;
    for(i=0;i<len;i++){
        a1[i]=i;
        a2[i]= len-i;
        a3[i]= rand()%len;
    }
    
    start = clock();
    mergesort(a1, 0, len);
    end = clock();
    printf("it took %lf seconds to execute \n", ((double)(end-start)/CLOCKS_PER_SEC));

    start = clock();
    mergesort(a2, 0, len);
    end = clock();
    printf("it took %lf seconds to execute \n", ((double)(end-start)/CLOCKS_PER_SEC));
    
    start = clock();
    mergesort(a3, 0, len);
    end = clock();
    printf("it took %lf seconds to execute \n", ((double)(end-start)/CLOCKS_PER_SEC));
}
