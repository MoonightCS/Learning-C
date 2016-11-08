// Вывод чисел + их бинарное представление, у которых по 4 единицы в представлении (можно вставить любое число)

#include <stdio.h>

int count (int n) {
    int result = 0;
    while (n) {
        n &= n - 1;
        result++;
    }
    return result;
}

void binaryCode(int x) {
    
    int tmp;
    for (int i = 7; i >= 0 ; i--) {
        tmp = (x & (1 << i));
               if (tmp != 0)
                   tmp >>= i;
        printf("%d", tmp);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    for (int i = 0; i < 32; i++) {
        if (count(i) == 4) {
            printf("%d and its BinaryCode ", i);
            binaryCode(i);
        }
    }
    return 0;
}


