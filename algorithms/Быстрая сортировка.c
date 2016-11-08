
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quicksort(int* arrA,int begin,int end)
{
	int i,j,mid;
	if (end - begin >= 1)
	{
        if (end - begin == 1)
		{
			if (arrA[begin] > arrA[end])
				swap(&arrA[begin],&arrA[end]);
            return;
		}
        
		mid = begin + rand()%(end-begin+1);
        
		swap(&arrA[mid],&arrA[end]);
        
		i = begin-1;
		j = end;
        
		while (j > i)
		{
			i++;
            j--;
			while (i < end && arrA[i] < arrA[end])
				i++;
			while (j > i && arrA[j] > arrA[end])
				j--;
			if (i < j)
				swap(&arrA[i],&arrA[j]);
		}
        
		swap(&arrA[i],&arrA[end]);
		quicksort(arrA, begin, i-1);
		quicksort(arrA, i+1, end);
	}
	
		
}

void sort(int* arrA,int n)
{
	quicksort(arrA,0,n-1);
}

int main()
{
    int n, i;
        scanf("%d", &n);
    int *arrA = (int *)malloc(n*sizeof(int));
    srand(time(NULL));
    
    for (i = 0; i < n; i++)
        scanf("%d", &arrA[i]);
    
        sort(arrA, n);
    
    for (i = 0; i < n; i++)
        printf("%d ", arrA[i]);
   
    free(arrA);
    return 0;
}
