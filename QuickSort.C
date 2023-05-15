#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quicksort(int number[], int first, int last)
{
int i,j,pivot,temp;
if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(number[i]<=number[pivot]&&i<last)
            { i++; }
            while(number[j]>number[pivot])
            { j--; }
            if(i<j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
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
    quicksort(a1, 0, len);
    end = clock();
    printf("it took %lf seconds to execute \n", ((double)(end-start)/CLOCKS_PER_SEC));

    start = clock();
    quicksort(a2, 0, len);
    end = clock();
    printf("it took %lf seconds to execute \n", ((double)(end-start)/CLOCKS_PER_SEC));
    
    start = clock();
    quicksort(a3, 0, len);
    end = clock();
    printf("it took %lf seconds to execute \n", ((double)(end-start)/CLOCKS_PER_SEC));
}
