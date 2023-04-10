#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 10

int* create(){
    return (int*)malloc(sizeof(int));
}

int main(void) {
    int *p = create();
    *p = 100;
    printf("%d\n", *p);

    return 0;
}