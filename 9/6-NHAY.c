#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MINSIZE 100000000

char* needle;
int* prefix;
int* output;
 
void calcPrefix(int t) {
    int i, j;
 
    i = 0;
    j = prefix[0] = -1;
    while (i < t) {
        while (j > -1 && needle[i] != needle[j]) {
            j = prefix[j];
        }
        i++;
        j++;
        if (needle[i] == needle[j]) {
            prefix[i] = prefix[j];
        }
        else {
            prefix[i] = j;
        }
    }
}
 
int kmp(int m) {
    int i, j, outSize;
    char in;
 
    i = j = outSize = 0;
    while (scanf("%c", &in) != EOF && in != '\n') {
        while (i > -1 && needle[i] != in) {
            i = prefix[i];
        }
 
        i++;
        j++;
        if (i >= m) {
            output[outSize] = j - m;
            outSize++;
            i = prefix[i];
        }
    }
 
    return outSize;
}

void printAnsw(int size) {
    int i;

    for(i = 0; i < size; i++) {
        printf("%d\n", output[i]);
    }
    printf("\n");
}

void vecAlloc(int newSize) {
    free(needle);
    free(prefix);
    free(output);
    needle = malloc(newSize * sizeof(char));
    prefix = malloc(newSize * sizeof(int));
    output = malloc(newSize * sizeof(int));
}
 
int main() {
    int m, memSize, outSize;
    
    memSize = MINSIZE;
    needle = malloc(memSize * sizeof(char));
    prefix = malloc(memSize * sizeof(int));
    output = malloc(memSize * sizeof(int));

    while(scanf("%d\n", &m) != EOF) {

        if((m + 2) > memSize) {
            memSize = m + 2;
            vecAlloc(memSize);
        }

        fgets(needle, m+2, stdin); 
        calcPrefix(m);
        outSize = kmp(m);
        printAnsw(outSize);
 
        scanf("%d", &m);
    }
 
    return 0;
}