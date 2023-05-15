#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  INSERTION SORT
-The first element in the array is assumed to be sorted. Take the second element and store it separately in key.
-Compare key with the first element. If the first element is greater than key, then key is placed in front of the first element.
-Now, the first two elements are sorted.
-Take the third element and compare it with the elements on the left of it. Placed it just behind the element smaller than it. 
-If there is no element smaller than it, then place it at the beginning of the array.
-Similarly, place every unsorted element at its correct position
*/
void insertion_sort(int a[], int n){
    int i, temp, j;
    for(i=1; i<=n-1; i++){
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1] = temp;
    }
}

/*  SELECTION SORT
-Set the first element as minimum.
-Compare minimum with the second element. If the second element is smaller than minimum, assign the second element as minimum.
-Compare minimum with the third element. Again, if the third element is smaller, then assign minimum to the third element otherwise do nothing.
-The process goes on until the last element.
-After each iteration, minimum is placed in the front of the unsorted list
-For each iteration, indexing starts from the first unsorted element. 
-Step 1 to 3 are repeated until all the elements are placed at their correct positions.
*/
void selection_sort(int a[], int n){
    int i,j,min,temp;
    for(i=0;i<n;i++){
        min= i;
        for(j=i+1;j<n-1;j++){
            if(a[j]<a[min])
                min=j;                
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

void main()
{
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
    insertion_sort(a, n);
    t = clock() - t;
    double time_taken = ((double)t/CLOCKS_PER_SEC)*1000; // in  milliseconds
    printf("The sorted array is : \n");
    for(i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    printf("it took %lf seconds to execute \n", time_taken);
    getch();
}
