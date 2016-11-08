#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void merge(int* arrA, int begin, int mid, int end, int* temp)
{
    
    int flag1=0, flag2=mid+1, flagT=begin;
    
    for (int i = begin; i <= mid; i++)
        temp[i-begin] = arrA[i];
    
    while (flag1 <= mid-begin && flag2 <= end)
    {
        if (temp[flag1] < arrA[flag2])
        {
            arrA[flagT] = temp[flag1];
            flagT++;
            flag1++;
        }
        else
        {
            arrA[flagT] = arrA[flag2];
            flagT++;
            flag2++;
        }
    }
    
    while (flag2 <= end)
        arrA[flagT++] = arrA[flag2++];
    
    while (flag1 <= mid-begin)
        arrA[flagT++] = temp[flag1++];
    
}

void MergeSort(int* arr,int begin,int end, int* temp)
{
	if (end-begin > 0)
	{
		int mid = (end+begin)/2;
		MergeSort(arr,begin,mid, temp);
		MergeSort(arr,mid+1,end, temp);
		merge(arr,begin,mid,end, temp);
	}
}

void sort(int* arrA,int n)
{
    int* temp = (int*)malloc((n+1)/2*sizeof(int));
	int begin = 0, end = n-1;
	MergeSort(arrA,begin,end, temp);
    free(temp);
}


int main ()
{
	int i, n;
	scanf("%d",&n);
	int *arrA = (int*)malloc(n*sizeof(int));
    
	for (i = 0; i < n; i++)
        scanf("%d",&arrA[i]);
	
	sort(arrA,n);
    
	for (i = 0; i < n; i++)
		printf("%d ",arrA[i]);
    
    free(arrA);
    return 0;
}
