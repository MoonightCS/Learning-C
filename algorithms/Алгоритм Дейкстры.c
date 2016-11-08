#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minDistance(int *dlina, bool *passed, int n)
{
    int min = INT_MAX, minVer = 0, j;
    
    for (j = 0; j < n; j++)
        if (passed[j] == false && dlina[j] <= min)
        {
            min = dlina[j];
            minVer = j;
        }
    return minVer;
}

int main()

{
    int i, n, m = 4 , a, b, S, F, weight, unit, graph[1001][1001], length[1001];
    bool passed[1001];
    
    scanf("%d%d%d%d", &n, &m, &S, &F);
    S--;
    F--;
    for (i = 0; i < n; i++)
    {
        scanf ("%d%d%d", &a, &b, &weight);
        graph[a-1][b-1] = weight;
        graph[b-1][a-1] = weight;
    }
    
    for (int i = 0; i < n; i++)
    {
        length[i] = INT_MAX;
        passed[i] = false;
    }
    
    length[S] = 0;
    
    for (int count = 0; count < n; count++)
    {
        unit = minDistance(length, passed, n);
        passed[unit] = true;
        for (int j = 0; j < n; j++)
            if ((passed[j] == 0) && (graph[unit][j] != 0) && (length[unit] != INT_MAX) && (length[unit]+graph[unit][j] < length[j]))
                length[j] = length[unit] + graph[unit][j];
    }
    
    printf("%d", length[F]);
    
    return 0;
}
