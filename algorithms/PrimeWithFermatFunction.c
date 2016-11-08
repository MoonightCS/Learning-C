//
//  main.c
//  PrimeWithFermatFunction

//  Copyright © 2016 Infinity. All rights reserved.



//  Проверка числа на простоту с помощью малой теоремы Ферма для уменьшения количества перебираемых чисел, а затем с помощью обычной проверки с порядком роста O(sqrt(n))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int expMod (int base, int n, int m) {
    if (n == 0)
        return 1;
    if (n % 2 == 0) {
        int res = expMod(base, n/2, m);
        res *= res;
        return res % m;
    }
    else {
        int res = base * expMod(base, n-1, m);
        return res % m;
    }
}

int fermatTest (int n) {
    
    srand(time(NULL));
    int r = rand() % (n-1) + 1;
    int result = expMod(r, n, n);
    
    if (result == r)
        return 1;
    else
        return 0;
    
}

int fastPrime (int n, int times) {
    if (times == 0)
        return 1;
    if (fermatTest(n) == 0)
        return 0;
    else return fastPrime(n, times - 1);
}

int Prime (int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    
    for (int i = 2; i < 2130; i++) {
        if (fastPrime(i, 3) == 1 && (Prime(i) == 1))
                printf("%d ", i);
    }
    
    return 0;
}
