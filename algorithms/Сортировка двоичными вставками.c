#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void scan(char **arrA, int i)
{
    static char temp[702];
    scanf("%s", temp);
    char *word = (char*)malloc(strlen(temp)+1);
    strcpy(word, temp);
    arrA[i]=word;
}

void sort(char** a,int n)
{
    int first,last, j,mid, i;
    char* s;
    
    for (i = 1; i < n; i++)
    {
        s = a[i];
        first = 0;
        last = i - 1;
        
        while (first + 1 < last)
        {
            mid = (first + last) / 2;
            if (strcmp(a[mid],a[i]) < 0)
                first = mid;
            else
                last = mid;
        }
        
        if (strcmp(a[last],a[i]) < 0)
            first = n - 1;
        else
            if (strcmp(a[first],a[i]) < 0)
                first = last;
        
        for (j = i-1; j > first-1; j--)
            a[j+1] = a[j];
        
        a[j+1] = s;
    }
    
}

int main()
{
    static char *arrA[70005];
    int n, i;
    
    scanf ("%d", &n);
    
    for (i = 0; i < n; i++)
        scan(arrA, i);
    
    sort(arrA, n);
    
    for (i = 0; i < n; i++)
    {
        printf("%s ", arrA[i]);
        free(arrA[i]);
    }
    
    return 0;
}
