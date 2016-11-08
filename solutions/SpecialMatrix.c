#include <stdio.h>


int main(void)
{
    long long n, i, j, k,m,p;
    long long x;

    scanf("%lld", &n);
    long long arrA[n][n];

    x = 1;

    for (i = n - 1; i >= 0; i--)
    {
        p = 0;
        m = i;

        for (k = n - i; k > 0; k--)
        {
            arrA[p][m] = x;
            x++;
            p++;
            m++;

        }
    }
    x = n * n;

    for (i = 0; i <= n-1; i++)
    {
        p = n-1;
        m = i;

        for (k = i+1; k > 0; k--)
        {
            arrA[p][m] = x;
            x--;
            p--;
            m--;

        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5lld ", arrA[i][j]);
        }
        printf("\n");


    }

    return 0;
}
