#include <stdio.h>
#include <stdlib.h>

int max (int i, int j, int *arrA)
{
	if (arrA[i] > arrA[j])
		return i;
	else
		return j;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Pyramid (int *arrA, int i, int n)
{
    int temp, x;
    
    temp = arrA[i];
    
    while(i <= n/2)
    {
        x = 2 * i ;
        if (x < n)
            if (max(x, x+1, arrA) == x+1)
                x++;
        
        if (arrA[x] <= temp)
            break;
        
        arrA[i] = arrA[x];
        i = x;
    }
    arrA[i] = temp;
}


void Sort(int *arrA, int n)
{
    int i;
    
    for (i = n/2+1; i >= 0; i--)
        Pyramid(arrA, i, n-1);
    
    for(i = n-1; i > 0; i--)
    {
        swap (&arrA[i], &arrA[0]);
        Pyramid(arrA, 0, i-1);
    }
}

int main()
{
	int n, i;
    
	scanf ("%d", &n);
    int *arrA = (int *) malloc(n*sizeof(int));
    
	for (i = 0; i < n; i++)
		scanf ("%d", &arrA[i]);
    
    Sort(arrA, n);
	
	for (i = 0; i < n; i++)
		printf ("%d ", arrA[i]);
    
    free(arrA);
	return 0;
}
