#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int i, j, n, a[1000], temp, choice;
    clock_t t;
    //clrscr();
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    printf("1: Random\n 2: Best case\n 3: Worst case \n");
    printf("Enter choice \n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
        for(i=0, j=1000; i<n; i++, j--){
        a[i]= rand();   //random no
        }
        break;
    case 2:
    for(i=0, j=1000; i<n; i++, j--){
        a[i]= i+1;    //best case
        }
        break;
    case 3:
        for(i=0, j=1000; i<n; i++, j--){
        a[i]= j;       //worst case
        }
        break;
    default :
     printf("enter valid input");
       break;
    }
    
    t = clock();
    for(i=1; i<=n-1; i++){
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1] = temp;
    }
    t = clock() - t;
    double time_taken = ((double)t/CLOCKS_PER_SEC)*1000; // in  milliseconds
    printf("The sorted array is : \n");
    for(i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    printf("it took %lf seconds to execute \n", time_taken);
    getch();
}
