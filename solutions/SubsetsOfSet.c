// Дан массив чисел, найти все возможные комбинации элементов данного массива, включая
// пустую комбинацию (я обозначил ее "~")

#include <stdio.h>

#define SIZE 3

int binAnswer[3] = {0, 0, 0};
int array[3] = {1, 2, 3};

void print() {

    int flag = 0;
    for (int i = 0; i < SIZE; i++) {
        if (binAnswer[i] == 1) {
            printf("%d", array[i]);
            flag = 1;
        }
    }
    if (flag == 1)
        printf(" ");
    else
        printf("~ ");

}

void comb(int x) {

    if (x == SIZE - 1) {
        binAnswer[x] = 0;
        print();
        binAnswer[x] = 1;
        print();
        return;
    }
    binAnswer[x] = 0;
    comb(x+1);
    binAnswer[x] = 1;
    comb(x+1);

}

int main(int argc, const char * argv[]) {

    comb(0);
    return 0;
}
