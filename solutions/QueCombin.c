// Find all string combinations consisting only of 0, 1 and ?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char answer[50] = " ";

void SCombination(int i, char* s, long size) {

    if (i == size - 1 ) {

        if (s[i] == '?') {
            answer[i] = '0';
            printf("%s\n", answer);
            answer[i] = '1';
            printf("%s\n", answer);
            return;
        }
        answer[i] = s[i];
        printf("%s\n", answer);
        return;
    }

    if (s[i] == '?') {

        answer[i] = '0';
        SCombination(i + 1, s, size);
        answer[i] = '1';
        SCombination(i + 1, s, size);
    }
    else {

        answer[i] = s[i];
        SCombination(i + 1, s, size);

    }
}

int main(int argc, const char * argv[]) {

    char s[50] = "1?1?0";

    unsigned long len = strlen(s);
    SCombination(0, s, len);
    return 0;
}
