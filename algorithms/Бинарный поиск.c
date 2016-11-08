
//Использование бинарного поиска для нахождения количества вхождений каждого из чисел одного массива в другом отсортированном массиве. 

#include <stdio.h>

int BinarySearch(int *arrA, int x, int n)
{
    int first = 0, last = n, mid;
    
    while (first + 1 < last)
    {
        mid = first + (last - first) / 2;
        if (arrA[mid] <= x)
            first = mid;
        else
            last = mid;
    }
    
    
    if (first + 1 == last)
    {
        mid = first + (last - first) / 2;
        if (arrA[mid] <= x)
            first = mid;
        else
            last = mid;
    }
    
    if (first <= last)
        return last;
    else
        return first;
}



int main()
{
    int arrA[100003], x, i, j, n, m;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++)
        scanf("%d", &arrA[i]);
    
    for (j = 0; j < m; j++)
    {
        scanf("%d", &x);
        printf("%d ", BinarySearch(arrA, x, n) - BinarySearch(arrA, x - 1, n));
    }
    return 0;
}
